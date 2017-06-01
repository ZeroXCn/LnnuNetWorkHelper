#include "NetClass.h"
bool NetClass::g_isLogined = false;

NetClass::NetClass(QWidget *parent):
	QWidget(parent)
{
	m_pUserModel =new  UserModel();
}

NetClass::~NetClass()
{

	delete m_pUserModel;
}

QAbstractListModel *NetClass::getModel()
{
	return m_pUserModel;
}


bool NetClass::getLogined()
{
	return g_isLogined;
}
void NetClass::setLogined(bool state)
{
	g_isLogined = state;
}

void NetClass::setLabelTextAndTip(QLabel *obj, QString str)
{
	if (obj){
		obj->setText(str);
		obj->setToolTip(str);
	}
}

void NetClass::setLabelPicture(QLabel *obj, QByteArray *data)
{
	QPixmap imageresult;//
	imageresult.loadFromData(*data);
	obj->clear();//清空
	obj->setPixmap(imageresult);//加载到Label标签
	obj->show();//显示
}

void NetClass::comboxChangedIndex(QComboBox *combo, QLineEdit *linedit, int index)
{
	UserModel::User *user = ((UserModel *)m_pUserModel)->getData(index);
	if (user == NULL || index < 0){
		combo->setCurrentText("");
		linedit->setText("");
		return;
	}

	combo->setCurrentText(user->mUsername);

	//解密
	QString password = decrypt(user->mPassword, Keyword::PASSWORD_KEY);
	linedit->setText(password);

}

void NetClass::passwordTextEdit(QCheckBox *checkbox, const QString &text)
{
	if (text.isEmpty())
		checkbox->setChecked(false);
}

QString NetClass::randomNumber(int bit)
{
	QString result = "";
	qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
	for (int i = 0; i < bit; i++)
		result.append(QChar(qrand() % 10 + 0x30));
	return result;
}

QString NetClass::systemTime_t()
{
	QDateTime time = QDateTime::currentDateTime();   //获取当前时间  
	int timeT = time.toTime_t();   //将当前时间转为时间戳  
	return QString("%1").arg(timeT);
}

QString NetClass::encrypt(QString value, QString key)
{
	string enpasswordStdSz = Encryption::Binary(value.toStdString(), key.toStdString());
	QString enpassword = QString::fromStdString(enpasswordStdSz);
	return enpassword;
}
QString NetClass::decrypt(QString value, QString key)
{
	string passwordStdSz = Encryption::EnBinary(value.toStdString(), key.toStdString());
	QString password = QString::fromStdString(passwordStdSz);
	return password;
}

QVariantMap NetClass::readUserData(int index)
{
	UserModel::User *user = ((UserModel *)m_pUserModel)->getData(index);
	QVariantMap result;
	if (user){
		result["username"] = user->mUsername;
		result["password"] = NetClass::decrypt(user->mPassword, Keyword::PASSWORD_KEY);
		result["type"] = user->mType;
		result["lately"] = user->mLately;
	}
	return result;
}

QAbstractListModel *NetClass::loadUserData(QString type)
{
	QList<QVariantMap> list = loadDataFromDB(type);
	for (QList<QVariantMap>::iterator it = list.begin(); it != list.end(); it++){
		UserModel::User *user = new UserModel::User();
		user->mUsername=(*it)["username"].toString();
		user->mPassword = (*it)["password"].toString();
		user->mType = (*it)["type"].toString();
		user->mLately = (*it)["lately"].toDateTime();

		((UserModel *)m_pUserModel)->addData(user);
	}
	return m_pUserModel;
}
int NetClass::deleteUserData(int index)
{
	UserModel::User *user = ((UserModel *)m_pUserModel)->getData(index);
	if (user)
	{
		deleteDataFromDB(user->mUsername, user->mType);
		((UserModel *)m_pUserModel)->deleteData(index);
	}
	else return 0;

	return 1;

}
int NetClass::insertUserData(QString username, QString password, QString type)
{
	//if (password.isEmpty())password = "";
	//加密
	QString enpassword = encrypt(password, Keyword::PASSWORD_KEY);

	//添加数据库
	insertDataToDB(username, enpassword, type);

	//保存Tab
	saveCurrentTabIndex();

	//添加MODEL
	int index = ((UserModel *)m_pUserModel)->index(username, type);
	if (index != -1){
		UserModel::User *user = ((UserModel *)m_pUserModel)->getData(index);
		user->mPassword = enpassword;
		user->mLately = QDateTime::currentDateTime();

	}
	else{
		UserModel::User *user = new UserModel::User();
		user->mUsername = username;
		user->mPassword = enpassword;
		user->mType = type;
		user->mLately = QDateTime::currentDateTime();

		((UserModel *)m_pUserModel)->addData(user);

		index = ((UserModel *)m_pUserModel)->index(username, type);
	}
	return index;

}


QList<QVariantMap> NetClass::loadDataFromDB(QString type)
{
	//加载数据
	QList<QVariantMap> list;
	SQLiteDB userdb(Keyword::DATABASE_PATH);
	SQLiteDB::SqlQuery sqlquery;
	sqlquery = userdb.exec(QString("select * from %1 where type='%2' order by lately DESC").arg(Keyword::DATABASE_USER_TABLE).arg(type));
	while (sqlquery.next()){
		QVariantMap resultMap;
		resultMap["username"] = sqlquery.value("username").toString();
		resultMap["password"] = sqlquery.value("password").toString();
		resultMap["type"] = sqlquery.value("type").toString();
		resultMap["lately"] = sqlquery.value("lately").toDateTime();
		list.push_back(resultMap);
	}
	userdb.close();
	return list;
}
void NetClass::deleteDataFromDB(QString uesrname, QString type)
{
	SQLiteDB userdb(Keyword::DATABASE_PATH);
	userdb.exec(QString("delete from %1 where username = '%2' and type = '%3';").arg(Keyword::DATABASE_USER_TABLE).arg(uesrname).arg(type));
	userdb.close();
}
void NetClass::insertDataToDB(QString uesrname, QString password, QString type)
{
	//加密

	//保存密码和设置登陆设置
	SQLiteDB userdb(Keyword::DATABASE_PATH);
	userdb.exec(QString("REPLACE INTO %1(username,password,type,lately,date) VALUES('%2','%3','%4',datetime(CURRENT_TIMESTAMP, 'localtime'),(SELECT date FROM %5 WHERE username = '%6'));").arg(Keyword::DATABASE_USER_TABLE).arg(uesrname).arg(password).arg(type).arg(Keyword::DATABASE_USER_TABLE).arg(uesrname));

	userdb.close();

}


void NetClass::saveCurrentTabIndex()
{
	emit saveTabIndex();
}