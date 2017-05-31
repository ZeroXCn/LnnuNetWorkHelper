#include "IlnClass.h"
#include "CardModel.h"
void IlnClass::init()
{
	//��������
	m_pLoginHp = new HttpOp();
	m_pCookieHp = new HttpOp();
	m_pConnectHp = new HttpOp();
	m_pInfoHp = new HttpOp();
	m_pSmsHp = new HttpOp();

	m_pCookieJar = new QNetworkCookieJar();

	m_loginKeyMap =new QVariantMap();

	m_pUserModel = new UserModel();
	
	//����COOkie
	m_pLoginHp->setCookieJar(m_pCookieJar);
	m_pCookieHp->setCookieJar(m_pCookieJar);
	m_pConnectHp->setCookieJar(m_pCookieJar);
	m_pInfoHp->setCookieJar(m_pCookieJar);
	m_pSmsHp->setCookieJar(m_pCookieJar);

	//��������
	connect(m_pLoginHp, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyLoginSlot(QNetworkReply *)));
	connect(m_pCookieHp, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyCookieSlot(QNetworkReply *)));
	connect(m_pConnectHp, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyConnectSlot(QNetworkReply *)));
	connect(m_pInfoHp, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyInfoSlot(QNetworkReply *)));
	connect(m_pSmsHp, SIGNAL(finished(QNetworkReply *)), this, SLOT(replySmsSlot(QNetworkReply *)));

	connect(ui.iln_login_pushbutton, SIGNAL(clicked()), this, SLOT(sendLoginInfo()));
	connect(ui.iln_logout_pushbutton, SIGNAL(clicked()), this, SLOT(sendLogOutInfo()));
	connect(ui.iln_getsmspas_pushbutton, SIGNAL(clicked()), this, SLOT(sendSmsInfo()));
	connect(ui.iln_user_delete_pushButton, SIGNAL(clicked()), this, SLOT(delUserButtonSlot()));

	connect(ui.iln_service_pushbutton, SIGNAL(clicked()), this, SLOT(serviceSlot()));
	connect(ui.iln_recharge_pushButton, SIGNAL(clicked()), this, SLOT(rechargeCardSlot()));


	connect(ui.iln_user_comboBox, SIGNAL(activated(int)), this, SLOT(comboBoxChangedSlot(int)));

	//��������
	SQLiteDB userdb(Keyword::DATABASE_PATH);
	SQLiteDB::SqlQuery sqlquery;
	sqlquery = userdb.exec(QString("select * from %1 where type='%2' order by lately DESC").arg(Keyword::DATABASE_USER_TABLE).arg("iln"));
	while (sqlquery.next()){
		UserModel::User *user = new UserModel::User();
		user->mUsername = sqlquery.value("username").toString();
		user->mPassword = sqlquery.value("password").toString();
		user->mType = sqlquery.value("type").toString();
		user->mLately = sqlquery.value("lately").toDateTime();
		m_pUserModel->addData(user);
	}
	userdb.close();
	ui.iln_user_comboBox->setModel(m_pUserModel);
	comboBoxChangedSlot(0);


	//���ÿؼ�
	ui.iln_login_frame->setVisible(true);
	ui.iln_info_frame->setVisible(false);
	ui.iln_smspas_le->setEnabled(false);

	ui.iln_login_pushbutton->setEnabled(false);

	//���ÿؼ�λ��
	ui.iln_info_frame->setGeometry(ui.iln_login_frame->geometry());

	
}

int IlnClass::currentClass()
{
	//��ʼ��
	ui.iln_login_pushbutton->setEnabled(false);
	setLabelTextAndTip(ui.iln_state_label, "");
	//��ȡCookie
	
	if (ui.iln_info_frame->isVisible() == false)
		initPageCookie();

	return 1;
}

IlnClass::IlnClass(QWidget *parent):
	NetClass(parent)
{
	ui.setupUi(this);

	m_pServiceDialog=NULL;

	init();
}

IlnClass::~IlnClass()
{

	m_pCookieJar->deleteLater();
	delete m_pLoginHp;
	delete m_pCookieHp;
	delete m_pConnectHp;
	delete m_pInfoHp;
	delete m_pSmsHp;

	delete m_loginKeyMap;

	delete m_pUserModel;

	delete m_pServiceDialog;

}
void IlnClass::initPageCookie()
{
	setLabelTextAndTip(ui.iln_state_label, QStringLiteral("���ڼ�����Ϣ,���Ե�.."));
	m_pCookieHp->setUrlCount(0);
	m_pCookieHp->url(Keyword::ILN_COOKIE_URL)
		->mode(HttpOp::GET)->send();
}
void IlnClass::sendLoginInfo()
{
	m_pLoginHp->setUrlCount(0);
	QString uesrname = ui.iln_user_comboBox->currentText();
	QString password = ui.iln_pass_le->text();
	QString smspas = ui.iln_smspas_le->text();
	QString postdata = QString("contextType=11&username=%1&password=%2&verifyCode=%3").arg(uesrname).arg(password).arg(smspas);

	m_pLoginHp->url(Keyword::ILN_LOGIN_URL)
		//->cookie()
		->data(postdata)
		->mode(HttpOp::POST)->send();
}

void IlnClass::sendLogOutInfo()
{
	//���ȶϿ�Wifi
	sendDisConnectInfo();

	//����������Ϣ-ע���ʺ�
	QVariantMap LoginUser = (*m_loginKeyMap)["LoginUser"].toMap();
	QString flowID = LoginUser["flowID"].toString();
	QString username = LoginUser["userName"].toString();
	QString terminalType = LoginUser["terminalType"].toString();

	QString postdata = QString("flowID=%1&username=%2&terminalType=%3&wlanusermac=")
		.arg(flowID).arg(username).arg(terminalType);

	m_pLoginHp->setUrlCount(-1);
	m_pLoginHp->url(Keyword::ILN_LOGOUT_URL)
		->data(postdata)
		->mode(HttpOp::POST)->send();
	//TODO:����Ӧ�÷��ؽ�����ж�


	//�л�Frame
	ui.iln_login_frame->setVisible(true);
	ui.iln_info_frame->setVisible(false);

	//���ÿؼ�
	currentClass();
	//initPageCookie();

	//���ÿؼ�
	setLabelTextAndTip(ui.iln_state_label, QStringLiteral("ע���ɹ�"));
	setLogined(false);


}

void IlnClass::sendConnectInfo()
{
	//����������Ϣ
	QVariantMap LoginUser = (*m_loginKeyMap)["LoginUser"].toMap();
	QString flowID = LoginUser["flowID"].toString();
	QString username = LoginUser["userName"].toString();
	QString terminalType = LoginUser["terminalType"].toString();
	QString terminalOS = LoginUser["terminalOS"].toString();
	QString uuid = LoginUser["uuid"].toString();
	QString resourceID = LoginUser["resourceID"].toString();

	QString postdata = QString("flowID=%1&username=%2&terminalType=%3&userMac=&userDomain=&terminalOS=%4&uuid=%5&locationAddress=&cityID=&poiID=&resourceID=%6&changeToForward=&contextType=51")
		.arg(flowID).arg(username).arg(terminalType).arg(terminalOS).arg(uuid).arg(resourceID);

	m_pConnectHp->url(Keyword::ILN_OPENWIFI_URL)
		->data(postdata)
		->mode(HttpOp::POST)->send();

	m_pConnectHp->setUrlCount(0);
}
void IlnClass::sendDisConnectInfo()
{
	//����������Ϣ
	QVariantMap LoginUser = (*m_loginKeyMap)["LoginUser"].toMap();
	QString flowID = LoginUser["flowID"].toString();
	QString uuid = LoginUser["uuid"].toString();
	QString username = LoginUser["userName"].toString();
	QString terminalType = LoginUser["terminalType"].toString();
	QString userType = LoginUser["userType"].toString();
	QString loginTime = LoginUser["loginTime"].toString();

	QString postdata = QString("flowID=%1&uuid=%2&username=%3&terminalType=%4&userMac=&userType=%5(%6)&wjflag=false&loginTime=%7")
		.arg(flowID).arg(uuid).arg(username).arg(terminalType).arg(userType).arg(1).arg(loginTime);


	m_pConnectHp->url(Keyword::ILN_CLOSEWIFI_URL)
		->data(postdata)
		->mode(HttpOp::POST)->send();

	m_pConnectHp->setUrlCount(1);
}

void IlnClass::sendSmsInfo()
{
	QString uesrname = ui.iln_user_comboBox->currentText();
	m_pSmsHp->url(Keyword::ILN_LOGIN_SMS_URL)
		->data(QString("username=%1").arg(uesrname))
		->mode(HttpOp::POST)->send();
	ui.iln_keepinmine_checkBox->setChecked(false);
	ui.iln_pass_le->setText("");
	ui.iln_smspas_le->setText(QStringLiteral("��������������������"));

//	connect(ui.iln_pass_le, SIGNAL(textEdited(const QString &)), this, SLOT(pawLetextEditSlot(const QString &)));
}

void IlnClass::pawLetextEditSlot(const QString &text)
{
	ui.iln_smspas_le->setText(text);
}
void IlnClass::serviceSlot()
{
	if (!m_pServiceDialog){
		m_pServiceDialog = new IlnServiceClass(this);
		((IlnServiceClass *)m_pServiceDialog)->setModel(m_pUserModel);
	}

	((IlnServiceClass *)m_pServiceDialog)->setCurrentIndex(ui.iln_user_comboBox->currentIndex());
	((IlnServiceClass *)m_pServiceDialog)->show();
}

void IlnClass::rechargeCardSlot()
{
	//����ģ��Ի���
	IlnCardClass form(this);
	
	form.setCookieList(m_pLoginHp->getCookiesList());
	form.getPageCookie();

	form.exec();
}

void IlnClass::updataInfoSlot()
{

}

void IlnClass::replyCookieSlot(QNetworkReply *reply)
{
	QVariant replycode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
	
	if (302 == replycode.toInt())
	{
		
		QVariant redirectionUrl = reply->attribute(QNetworkRequest::RedirectionTargetAttribute);

		if (redirectionUrl.toUrl() == QUrl(Keyword::CMCC_HAD_NET_URL))//�Ѿ�����
		{
			setLabelTextAndTip(ui.iln_state_label, QStringLiteral("���Ѿ��ڻ�������!"));
			ui.iln_login_pushbutton->setEnabled(false);
			reply->deleteLater();
			return;
		}

		m_pCookieHp->url(redirectionUrl.toString())
			->mode(HttpOp::GET)->send();
		
	}
	else if (200 == replycode.toInt())
	{
		//COOKIE�ɹ���ȡ,���Ե�½
		setLabelTextAndTip(ui.iln_state_label, QStringLiteral(""));
		ui.iln_login_pushbutton->setEnabled(true);
		
	}
	else 
		setLabelTextAndTip(ui.iln_state_label, QStringLiteral("�����쳣!"));


	reply->deleteLater();
}

void IlnClass::replyLoginSlot(QNetworkReply *reply)
{
	int nCount = m_pLoginHp->getUrlCount();
	if (nCount == 1)
	{
		QString jsoncontent=QString(reply->readAll());
		if (jsoncontent.isEmpty()){
			setLabelTextAndTip(ui.iln_state_label, QStringLiteral("��½��Ϣ��ȡʧ��,�������л�ѡ�!"));
			reply->deleteLater();
			return;
		}

		*m_loginKeyMap = JsonHelper::fromJson(jsoncontent);

		//��½�ɹ�
		if ((*m_loginKeyMap)["ErrCode"].toString() == "0")
		{

			//��������-���û��ѡ,��ֻ�����ʺ�
			alterUser();
			setLogined(true);

			//���ӻ�����
			sendConnectInfo();

			//���ÿؼ�
			setLabelTextAndTip(ui.iln_state_label, QStringLiteral("��½�ɹ�"));
		}
		else{
			setLabelTextAndTip(ui.iln_state_label, QStringLiteral("��½��Ϣ��ȡʧ��,�������л�ѡ�!"));
		}
	}
	reply->deleteLater();
}



void IlnClass::replyConnectSlot(QNetworkReply *reply)
{
	QString content=QString(reply->readAll());
	if (!content.isEmpty())
	{
		QVariantMap InfoMap = JsonHelper::fromJson(content);
		QString errorCode = InfoMap["ErrCode"].toString();
		if (errorCode == "0")
		{
			int nType = m_pConnectHp->getUrlCount();
			if (nType == 0){
				//��ȡ������Ϣ
				QVariantMap CarMap = InfoMap["OnlineInfo"].toMap();

				QString offerName = CarMap["offerName"].toString();
				QString username = CarMap["username"].toString();
				QString effTime = CarMap["effTime"].toString();
				QString expTime = CarMap["expTime"].toString();
				int price = CarMap["price"].toInt();
				int offerHour = CarMap["offerHour"].toInt();
				QString accuTime = CarMap["accuTime"].toString();
				QString freeTime = CarMap["freeTime"].toString();
				int leftPercent = NetWorkHelper::SubString(CarMap["leftPercent"].toString(), QRegExp("(\\d+)")).value(0,0).toInt();

				ui.iln_card_comboBox->clear(); //TODO:Ӧ�������»�ȡ��Ϣʱ���
				ui.iln_card_comboBox->addItem(offerName);
				ui.iln_username_label->setText(username);
				ui.iln_effTime_label->setText(effTime);
				ui.iln_expTime_label->setText(expTime);
				ui.iln_price_label->setText(QString(QStringLiteral("%1Ԫ")).arg(price));
				ui.iln_offerHour_label->setText(QString(QStringLiteral("%1Сʱ")).arg(offerHour / 3600));
				ui.iln_accuTime_label->setText(accuTime);
				ui.iln_freeTime_label->setText(freeTime);
				ui.iln_leftPercent_label->setText(QString("%1%").arg((100 - leftPercent)));


				ui.iln_info_frame->setVisible(true);
				ui.iln_login_frame->setVisible(false);
			}
			else if (nType == 1){

			}
		}
		else 
			setLabelTextAndTip(ui.iln_state_label, InfoMap["ErrDesc"].toString());
	}
	reply->deleteLater();
}



void IlnClass::replyInfoSlot(QNetworkReply *reply)
{

	reply->deleteLater();
}

void IlnClass::replySmsSlot(QNetworkReply *reply)
{
	QString content = QString(reply->readAll());
	if (!content.isEmpty())
	{
		QVariantMap InfoMap = JsonHelper::fromJson(content);
		
		QString errorCode = InfoMap["ErrCode"].toString();
		QString desc = InfoMap["ErrDesc"].toString();
		if (errorCode == "0")
		{
			QStringList number = NetWorkHelper::SubString(desc, QRegExp("(\\d+)"));
			QString str = QString(QStringLiteral("������������:%1/%2")).arg(number.value(1, 0)).arg(number.value(0, 0));

			setLabelTextAndTip(ui.iln_state_label, str);
		}else 
			setLabelTextAndTip(ui.iln_state_label, desc);

	}

	reply->deleteLater();
}

//////////////////////////////////////////

void IlnClass::delUser()
{
	QString uesrname = ui.iln_user_comboBox->currentText();
	int currentId = ui.iln_user_comboBox->currentIndex();
	int haveId = ui.iln_user_comboBox->count();
	if (currentId == -1){ comboBoxChangedSlot(-1); return; }

	SQLiteDB userdb(Keyword::DATABASE_PATH);
	userdb.exec(QString("delete from %1 where username = '%2' and type='%3';").arg(Keyword::DATABASE_USER_TABLE).arg(uesrname).arg("iln"));

	//����Model
	//���û��ѡ��ComboBox��ֵ���������ֵ�Ͳ���ɾ��
	m_pUserModel->deleteData(currentId);

	comboBoxChangedSlot(haveId - 1);
}
void IlnClass::alterUser()
{
	QString uesrname = ui.iln_user_comboBox->currentText();

	//����
	QString password = ui.iln_pass_le->text();
	string enpasswordStdSz = Encryption::Binary(password.toStdString(), Keyword::PASSWORD_KEY.toStdString());
	QString enpassword = QString::fromStdString(enpasswordStdSz);

	if (!ui.iln_keepinmine_checkBox->isChecked())enpassword = "";

	SQLiteDB userdb(Keyword::DATABASE_PATH);
	userdb.exec(QString("REPLACE INTO %1(username,password,type,lately,date) VALUES('%2','%3','%4',datetime(CURRENT_TIMESTAMP, 'localtime'),(SELECT date FROM %5 WHERE username = '%6'));").arg(Keyword::DATABASE_USER_TABLE).arg(uesrname).arg(enpassword).arg("iln").arg(Keyword::DATABASE_USER_TABLE).arg(uesrname));

	SQLiteDB::SqlQuery sqlquery = userdb.exec(QString("select * from %1 where username = '%2' and type = '%3'").arg(Keyword::DATABASE_USER_TABLE).arg(uesrname).arg("iln"));
	sqlquery.next();

	UserModel::User *user = new UserModel::User();
	user->mUsername = sqlquery.value("username").toString();
	user->mPassword = sqlquery.value("password").toString();
	user->mType = sqlquery.value("type").toString();
	user->mLately = sqlquery.value("lately").toDateTime();

	//����Model
	int index = m_pUserModel->index(uesrname,"iln");
	if (index != -1){
		UserModel::User *luser = m_pUserModel->getData(index);
		luser->mPassword = user->mPassword;
		luser->mLately = user->mLately;
		delete user;

		comboBoxChangedSlot(index);
	}
	else{
		m_pUserModel->addData(user);
		//TODO:????????????
		int lindex = m_pUserModel->index(uesrname, "iln");
		comboBoxChangedSlot(lindex);
	}
	//��ǰ�ر����ݿ�����,��Ȼ�޷�д��
	userdb.close();

	//�����½����
	saveCurrentTabIndex();

	
}

void IlnClass::comboBoxChangedSlot(int index)
{
	UserModel::User *user = m_pUserModel->getData(index);
	if (user == NULL || index < 0){
		ui.iln_user_comboBox->setCurrentText("");
		ui.iln_pass_le->setText("");
		ui.iln_keepinmine_checkBox->setChecked(false);
		return;
	}

	ui.iln_user_comboBox->setCurrentText(user->mUsername);

	//����
	QString enpassword = user->mPassword;
	string passwordStdSz = Encryption::EnBinary(enpassword.toStdString(), Keyword::PASSWORD_KEY.toStdString());
	QString password = QString::fromStdString(passwordStdSz);

	ui.iln_pass_le->setText(password);

	if (user->mPassword.isEmpty())
		ui.iln_keepinmine_checkBox->setChecked(false);
	else ui.iln_keepinmine_checkBox->setChecked(true);
}

void IlnClass::delUserButtonSlot()
{
	delUser();
}


////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////

IlnCardClass::IlnCardClass(QWidget *parent) :
	QDialog(parent)
{
	ui.setupUi(this);

	m_pPageInfoHp = new HttpOp();
	m_pActiveHp = new HttpOp();

	m_pCookieJar = m_ptCJar = new HttpOp::CookieJar();

	m_pPageInfoHp->setCookieJar(m_pCookieJar);
	m_pActiveHp->setCookieJar(m_pCookieJar);

	connect(m_pPageInfoHp, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyPageInfoSlot(QNetworkReply *)));
	connect(m_pActiveHp, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyActiveSlot(QNetworkReply *)));

	connect(ui.iln_card_reget_button, SIGNAL(clicked()), this, SLOT(getPicSlot()));
	connect(ui.iln_card_active_button, SIGNAL(clicked()), this, SLOT(postActiveSlot()));

	//�����Ի����С
	setFixedSize(width(), height());
}
IlnCardClass::~IlnCardClass()
{
	disconnect(m_pPageInfoHp, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyPageInfoSlot(QNetworkReply *)));
	disconnect(m_pActiveHp, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyActiveSlot(QNetworkReply *)));
	m_ptCJar->deleteLater();
	delete m_pPageInfoHp;
	delete m_pActiveHp;
}
void IlnCardClass::setCookieJar(QNetworkCookieJar *jar)
{
	m_pCookieJar = jar;
	m_pPageInfoHp->setCookieJar(m_pCookieJar);
	m_pActiveHp->setCookieJar(m_pCookieJar);

}

void IlnCardClass::setCookieList(QList<QNetworkCookie> list)
{
	((HttpOp::CookieJar *)m_pCookieJar)->setCookies(list);
}


void IlnCardClass::getPageCookie()
{
	//�ȴ�Cookie��ȡ��CSRFToken�ؼ���
	QString cookie = ((HttpOp::CookieJar *)m_pCookieJar)->getCookies();
	QString selfCSRFToken = NetWorkHelper::SubString(cookie, "CSRFCookie=", ";").value(0,"");
	
	//ƴ��Ŀ���ַGET
	QString url = QString("%1&%2").arg(Keyword::ILN_CARD_SERVICE_URL).arg(selfCSRFToken);

	//GEt����
	m_pPageInfoHp->url(url)->mode(HttpOp::GET)->send();
}

void IlnCardClass::setToken(QString token)
{
	m_CSRFToken_HW = token;
}

void IlnCardClass::clearControl()
{
	ui.iln_card_number_le->setText(""); ui.iln_card_number_le->setPlaceholderText(QStringLiteral("������12λ�����к�"));
	ui.iln_card_vcode_le->setText("");
	ui.iln_card_picture->clear();
}

void IlnCardClass::getPicSlot()
{
	//��ʼ״̬GEt����
	QNetworkReply *reply= HttpOp::get(Keyword::ILN_CARD_CARDVCODE_URL, m_pCookieJar);
	QByteArray data = reply->readAll();

	if (!data.isEmpty())
		NetWorkHelper::setLabelPicture(ui.iln_card_picture, &data);

	reply->deleteLater();
}
void IlnCardClass::postActiveSlot()
{
	//ƴ��POST����
	QString cardnumber = ui.iln_card_number_le->text();
	QString vcode = ui.iln_card_vcode_le->text();
	QString post = QString("activationCode=%1&verifyCode=%2&CSRFToken_HW=%3").arg(cardnumber).arg(vcode).arg(m_CSRFToken_HW);
	//POST
	m_pActiveHp->url(Keyword::ILN_CARD_CARDCHECK_URL)
		->cookie()
		->data(post)
		->mode(HttpOp::POST)->send();
}

void IlnCardClass::replyPageInfoSlot(QNetworkReply *reply)
{
	//�ж�״̬302��ת��
	QVariant replycode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
	if (302 == replycode.toInt())
	{
		QVariant redirectionUrl = reply->attribute(QNetworkRequest::RedirectionTargetAttribute);
		QString url = redirectionUrl.toString();
		m_pPageInfoHp->url(url)->mode(HttpOp::GET)->send();
	
	}
	//Ϊ200��ȡ��ǰĿ���ַ
	else if (200 == replycode.toInt())
	{
		//��Ŀ���ַ��ȡCSRFToken_HW�����浽������
		QString url = reply->url().toString();
		QString CSRFToken_HW = NetWorkHelper::SubString(url, "CSRFToken_HW=", "").value(0, "");
		
		//�ж��Ƿ�Ϊ��
		if (CSRFToken_HW.isEmpty());
		m_CSRFToken_HW = CSRFToken_HW;

		getPicSlot();
	}
	
	reply->deleteLater();
}
void IlnCardClass::replyActiveSlot(QNetworkReply *reply)
{
	QString pageContent = reply->readAll();
	QVariantMap result= JsonHelper::fromJson(pageContent);
	//ȡ��״̬,������һ������
	int resultcode = result.value("code", -10).toInt();
	if (resultcode == 0)
	{
		QString cardnumber = ui.iln_card_number_le->text();
		QString content = QString(QStringLiteral("�㿨���к�:%1\n�㿨����:%2\nʱ��:%3Сʱ\n���:%4Ԫ\n�Ƿ�ȷ�ϼ���?"))
			.arg(cardnumber).arg(result.value("offerName", "").toString()).arg(result.value("offerHour", "").toInt()/3600).arg(result.value("price", "").toString());
		//�Ƿ�ȷ�ϵ���ʾ��ť
		QMessageBox::StandardButton button;
		button = QMessageBox::question(this, Keyword::LNH_NAME,
			content,
			QMessageBox::Yes | QMessageBox::No);
		if (button == QMessageBox::Yes) {
			//��ʼ״̬GEt����
			QString post = QString("activationCode=%1&offerType=%2&CSRFToken_HW=%3")
				.arg(cardnumber).arg(result.value("offerType", "").toString()).arg(m_CSRFToken_HW);

			QNetworkReply *lreply = HttpOp::post(Keyword::ILN_CARD_CARDACTIVE_URL, m_pCookieJar, post);
			QByteArray data = lreply->readAll();
			if (!data.isEmpty())
			{	
				//TODO:.................ȡ������Ϣ
				QVariantMap lresult = JsonHelper::fromJson(pageContent);
				QString resultMsg = lresult["resultMsg"].toString();

				QMessageBox::information(this, Keyword::LNH_NAME, resultMsg);

				//���¸���������
				emit updata();
			}

			lreply->deleteLater();
		}
		else if (button == QMessageBox::No) {
			
		}
	}
	else
		QMessageBox::critical(this, Keyword::LNH_NAME, result.value("resultMsg", QStringLiteral("��Ϣ���ش���,�����¼��ر�����")).toString());


	reply->deleteLater();

	getPicSlot();
}

//////////////////////////////////////////////////////////////////////////////////////////
IlnServiceClass::IlnServiceClass(QWidget *parent) :
QDialog(parent)
{
	ui.setupUi(this);

	m_pCardModel = NULL;
	m_pUserModel = NULL;

	m_pPageInfoHp = new HttpOp();
	m_pVcodeHp = new HttpOp();
	m_pLoginHp = new HttpOp();
	m_pBusinessHp = new HttpOp();

	m_pCardModel = new CardModel();

	m_pIlnCardClass = new IlnCardClass(this);

	m_pCookieJar = new HttpOp::CookieJar();

	m_pPageInfoHp->setCookieJar(m_pCookieJar);
	m_pVcodeHp->setCookieJar(m_pCookieJar);
	m_pLoginHp->setCookieJar(m_pCookieJar);
	m_pBusinessHp->setCookieJar(m_pCookieJar);

	((IlnCardClass *)m_pIlnCardClass)->setCookieJar(m_pCookieJar);

	///
	connect(m_pPageInfoHp, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyPageInfoSlot(QNetworkReply *)));
	connect(m_pVcodeHp, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyVcodeSlot(QNetworkReply *)));
	connect(m_pLoginHp, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyLoginSlot(QNetworkReply *)));
	connect(m_pBusinessHp, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyBusinessSlot(QNetworkReply *)));

	connect(ui.iln_service_getpic_pb, SIGNAL(clicked()), this, SLOT(changeVcodeSlot()));
	connect(ui.iln_service_login_pb, SIGNAL(clicked()), this, SLOT(loginServiceSlot()));
	connect(ui.iln_service_sms_pb, SIGNAL(clicked()), this, SLOT(sendSmsSlot()));
	connect(ui.iln_service_forcelogout_pb, SIGNAL(clicked()), this, SLOT(forceLogoutSlot()));

	connect(ui.tabWidget, SIGNAL(currentChanged(int)), this, SLOT(tabChangedSlot(int)));

	connect(ui.iln_service_user_cb, SIGNAL(activated(int)), this, SLOT(usercomboBoxChangedSlot(int)));
	connect(ui.iln_card_comboBox, SIGNAL(activated(int)), this, SLOT(cardcomboBoxChangedSlot(int)));

	connect((IlnCardClass *)m_pIlnCardClass, SIGNAL(updata()), this, SLOT(getMyBusinessSlot()));

	//
	ui.iln_service_login_frame->setVisible(true);
	ui.iln_service_info_frame->setVisible(false);

	//��ӹ���Tab
	ui.tabWidget->insertTab(1, m_pIlnCardClass, QStringLiteral("��Ʒ����"));

	//���ÿؼ�λ��
	ui.iln_service_info_frame->setGeometry(ui.iln_service_login_frame->geometry());

	//
	setFixedSize(width(), height());

}
IlnServiceClass::~IlnServiceClass()
{
	delete m_pPageInfoHp;
	delete m_pVcodeHp;
	delete m_pLoginHp;
	delete m_pBusinessHp;
	delete m_pCookieJar;

	delete m_pCardModel;
}

void IlnServiceClass::initPage()
{
	//���Cookie
	m_pPageInfoHp->url(Keyword::ILN_SERVICE_START_URL)
		->mode(HttpOp::GET)->send();

}
void IlnServiceClass::replyPageInfoSlot(QNetworkReply *reply)
{
	QVariant replycode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
	int ncode = replycode.toInt();
	if (ncode==200)
		changeVcodeSlot();

	reply->deleteLater();
}

void IlnServiceClass::replyVcodeSlot(QNetworkReply *reply)
{
	QByteArray data = reply->readAll();
	if (!data.isEmpty())
		NetWorkHelper::setLabelPicture(ui.iln_service_vcodepic_la, &data);

	reply->deleteLater();
}

void IlnServiceClass::setModel(UserModel *pModel, int index)
{
	m_pUserModel = pModel;
	ui.iln_service_user_cb->setModel(pModel);
	usercomboBoxChangedSlot(index);
}
void IlnServiceClass::setCurrentIndex(int index)
{
	usercomboBoxChangedSlot(index);
}

void IlnServiceClass::show()
{
	//��տؼ�
	ui.tabWidget->setCurrentIndex(0);
	ui.iln_service_vcodepic_la->clear();
	ui.iln_service_vcode_le->setText("");
	ui.iln_service_state_la->setText("");
	ui.iln_service_login_pb->setEnabled(true);

	((IlnCardClass *)m_pIlnCardClass)->clearControl();


	((HttpOp::CookieJar*)m_pCookieJar)->clear();

	ui.iln_service_info_frame->setVisible(false);
	ui.iln_service_login_frame->setVisible(true);

	QWidget::show();
	initPage();
}
void IlnServiceClass::usercomboBoxChangedSlot(int index)
{
	UserModel::User *user = ((UserModel *)m_pUserModel)->getData(index);
	if (user == NULL || index < 0){
		ui.iln_service_user_cb->setCurrentText("");
		ui.iln_service_password_le->setText("");
		return;
	}
	QString password = NetClass::decrypt(user->mPassword, Keyword::PASSWORD_KEY);
	ui.iln_service_user_cb->setCurrentText(user->mUsername);
	ui.iln_service_password_le->setText(password);

}
void IlnServiceClass::cardcomboBoxChangedSlot(int index)
{
	CardModel::Card *card = ((CardModel *)m_pCardModel)->getData(index);
	if (card == NULL || index < 0){
		return;
	}
	ui.iln_effTime_label->setText(card->effTime);
	ui.iln_expTime_label->setText(card->expTime);
	ui.iln_price_label->setText(card->price);
	ui.iln_offerHour_label->setText(card->offerHour);
	ui.iln_accuTime_label->setText(card->accuTime);
	ui.iln_freeTime_label->setText(card->freeTime);
	ui.iln_leftPercent_label->setText(card->leftPercent);
}

void IlnServiceClass::replyLoginSlot(QNetworkReply *reply)
{

	QString content = reply->readAll();
	if (!content.isEmpty()){
		QVariantMap InfoMap = JsonHelper::fromJson(content);
		if (InfoMap.value("resultCode", "").toString() == "0"){
			QString successpage = InfoMap.value("successpage", "").toString();
			m_CSRFToken_HW = NetWorkHelper::SubString(successpage, "CSRFToken_HW=", "").value(0, "");
			
			//��ȡ��������
			getMyBusinessSlot();

			//��ģ��һ����
			((IlnCardClass *)m_pIlnCardClass)->setToken(m_CSRFToken_HW);
			((IlnCardClass *)m_pIlnCardClass)->getPicSlot();
		}
		else {
			ui.iln_service_login_pb->setEnabled(true);
			changeVcodeSlot();
			NetClass::setLabelTextAndTip(ui.iln_service_state_la, InfoMap.value("errDesc", QStringLiteral("δ֪�쳣")).toString());
		}
	}
	
}
void IlnServiceClass::changeVcodeSlot()
{
	QString url = Keyword::ILN_SERVICE_VCODE_URL;// + "?0." + NetClass::randomNumber(16);
	m_pVcodeHp->url(url)
		->mode(HttpOp::GET)->send();
}


void IlnServiceClass::loginServiceSlot()
{
	QString username = ui.iln_service_user_cb->currentText();
	QString password = ui.iln_service_password_le->text();
	QString vode = ui.iln_service_vcode_le->text();
	QString post = QString("username=%1&password=%2&verifyCode=%3").arg(username).arg(password).arg(vode);
	m_pLoginHp->url(Keyword::ILN_SERVICE_LOGIN_URL)
		->data(post)
		->mode(HttpOp::POST)->send();

	ui.iln_service_login_pb->setEnabled(false);
}

void IlnServiceClass::sendSmsSlot()
{
	QString username = ui.iln_service_user_cb->currentText();
	QString data = QString("username=%1").arg(username);
	QString content=HttpOp::post(Keyword::ILN_SERVICE_SMSPAW_URL, (HttpOp::CookieJar *)m_pCookieJar, data);

	if (!content.isEmpty())
	{
		QVariantMap InfoMap = JsonHelper::fromJson(content);

		QString errorCode = InfoMap["ErrCode"].toString();
		QString desc = InfoMap["ErrDesc"].toString();
		if (errorCode == "0")
		{
			QStringList number = NetWorkHelper::SubString(desc, QRegExp("(\\d+)"));
			QString str = QString(QStringLiteral("������������:%1/%2")).arg(number.value(1, 0)).arg(number.value(0, 0));

			NetClass::setLabelTextAndTip(ui.iln_service_state_la, str);
			ui.iln_service_password_le->setText("");
		}
		else{
			NetClass::setLabelTextAndTip(ui.iln_service_state_la, desc);
		}

	}
}

void IlnServiceClass::forceLogoutSlot()
{
	QMessageBox::StandardButton button;
	button = QMessageBox::question(this, Keyword::LNH_NAME,
		QStringLiteral("ǿ�����ߺ�ʹ�����豸����,�Ƿ����?"),
		QMessageBox::Yes | QMessageBox::No);
	if (button == QMessageBox::Yes) {
		QString data = QString("CSRFToken_HW=%1").arg(m_CSRFToken_HW);
		QString content = HttpOp::post(Keyword::ILN_SERVICE_FORCELOGOUT_URL, (HttpOp::CookieJar *)m_pCookieJar, data);
		
		if (!content.isEmpty()){
			if (content == "SUCCESS")
				QMessageBox::information(this, Keyword::LNH_NAME, QStringLiteral("�����ɹ�!"));
			else
				QMessageBox::information(this, Keyword::LNH_NAME, QStringLiteral("û���豸�ɹ�����"));
		}
		else QMessageBox::critical(this, Keyword::LNH_NAME, QStringLiteral("�����쳣,�����µ�½��������"));
	}
}
void IlnServiceClass::getMyBusinessSlot()
{
	ui.iln_card_comboBox->clear();
	ui.iln_nowcard_checkBox->setChecked(false);
	ui.iln_leftPercent_label->setText("");
	ui.iln_username_label->setText("");
	ui.iln_effTime_label->setText("");
	ui.iln_expTime_label->setText("");
	ui.iln_price_label->setText("");
	ui.iln_offerHour_label->setText("");
	ui.iln_accuTime_label->setText("");
	ui.iln_freeTime_label->setText("");
	((CardModel *)m_pCardModel)->clear();


	QString url = QString(Keyword::ILN_SERVICE_OFFER_URL).arg(m_CSRFToken_HW).arg("myBusiness");
	m_pBusinessHp->url(url)
		->mode(HttpOp::GET)->send();
}

void IlnServiceClass::replyBusinessSlot(QNetworkReply *reply)
{
	QString content = reply->readAll();
	
	if (!content.isEmpty())
	{
		QList<QVariantMap> list=parsePageContent(content);
		
		//����ģ��
		for (int i = 0; i < list.size(); i++){
			QVariantMap key = list.at(i);
			CardModel::Card *card = new CardModel::Card();
			card->offerName = key["offerName"].toString();
			card->effTime = key["effTime"].toString();
			card->expTime = key["expTime"].toString();
			card->price = QStringLiteral("%1Ԫ").arg(key["price"].toString());
			card->offerHour = QStringLiteral("%1Сʱ").arg(key["offerHour"].toString());
			card->accuTime = QStringLiteral("%1Сʱ%2����").arg(key["accuTime"].toInt() / 3600).arg((key["accuTime"].toInt() % 3600) /60);
			card->freeTime = QStringLiteral("%1Сʱ%2����").arg(key["freeTime"].toInt() / 3600).arg((key["freeTime"].toInt() % 3600) / 60);
			card->leftPercent = QString("%1%").arg(key["leftPercent"].toString());
			card->productID = key["productID"].toString();
			((CardModel *)m_pCardModel)->addData(card);

		}
		//
		ui.iln_card_comboBox->setModel(m_pCardModel);
		ui.iln_username_label->setText(ui.iln_service_user_cb->currentText());

		ui.iln_service_login_pb->setEnabled(true);

		cardcomboBoxChangedSlot(0);
		
		ui.iln_service_info_frame->setVisible(true);
		ui.iln_service_login_frame->setVisible(false);

	}
	reply->deleteLater();
}

QList<QVariantMap> IlnServiceClass::parsePageContent(QString &content)
{
	QStringList paths = NetWorkHelper::SubString(content, QRegExp("<div class=\"text_content\">"), QRegExp("</script></b>\r\n\t\t\t\t\t\t\t\t\t\t\t</li>\r\n\t\t\t\t\t\t\t\t\t\r\n\t\t                            \t</ul>"));
	QList<QVariantMap> list;
	for (int i = 0; i < paths.size(); i++)
	{
		QString &org = paths.value(i, "");
		QVariantMap key;
		key["offerName"] = NetWorkHelper::SubString(org, "<span class=\"div_inline blue width450 height35 line_height35  paddingTop10 paddingBottom10\">", "</span>").value(0,"");
		QStringList dTime = NetWorkHelper::SubString(org, "<span class=\"div_inline gray_333 font_14\">", "</span>");
		key["effTime"] = dTime.value(1,"");
		key["expTime"] =dTime.value(3, "");
		key["price"] = NetWorkHelper::SubString(org, "<li class=\"i_2\"><b>","</b>");
		key["offerHour"] = NetWorkHelper::SubString(org, "<li class=\"i_3\"><b>", "</b>");

		QString tTimeOrg = NetWorkHelper::SubString(org, QRegExp("unUseTime(.*);"),true).value(0, "");
		QStringList tTime = NetWorkHelper::SubString(tTimeOrg, QRegExp("(\\d+)"));
		key["accuTime"] = tTime.value(1, "");
		key["freeTime"] = QString("%1").arg(tTime.value(0, "").toInt() - tTime.value(1, "").toInt());

		QString percentOrg=NetWorkHelper::SubString(org, QRegExp("<dd>(.*)%</dd>"), true).value(0,"");
		QString leftPercent = NetWorkHelper::SubString(percentOrg, QRegExp("(\\d+)")).value(0,"");
		key["leftPercent"] = leftPercent;

		QString productIDOrg = NetWorkHelper::SubString(org, "id=\"locationId\"/>","id=\"productId").value(0, "");
		QString productID = NetWorkHelper::SubString(productIDOrg, "value=\"", "\"").value(0, "");
		key["productID"] = productID;

		list.push_back(key);
	}
	return list;
}

void IlnServiceClass::tabChangedSlot(int index)
{
	switch (index)
	{
	case 0:
		break;
	case 1:
		//changeVcodeSlot();
		break;
	default:break;
	}
}