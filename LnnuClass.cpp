#include "LnnuClass.h"

LnnuClass::LnnuClass(QWidget *parent) :
	NetClass(parent)
{
	ui.setupUi(this);

	init();

}
LnnuClass::~LnnuClass()
{

	m_pCookieJar->deleteLater();
	delete m_pLoginHp;
	delete m_pConnectHp;
	delete m_pVCodeHp;
	delete m_pInfoHp;

	delete m_loginKeyMap;
	delete m_infoResultMap;

}

void LnnuClass::init()
{
	//创建对象

	m_pCookieJar = new QNetworkCookieJar();
	m_pLoginHp = new HttpOp();
	m_pConnectHp = new HttpOp();
	m_pVCodeHp = new HttpOp();
	m_pInfoHp = new HttpOp();

	m_loginKeyMap = new QVariantMap();
	m_infoResultMap = new QVariantMap();

	//设置COOKieJAr
	m_pLoginHp->setCookieJar(m_pCookieJar);
	m_pConnectHp->setCookieJar(m_pCookieJar);
	m_pVCodeHp->setCookieJar(m_pCookieJar);
	m_pInfoHp->setCookieJar(m_pCookieJar);
	
	//连接槽
	connect(m_pLoginHp, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyLoginSlot(QNetworkReply *)));
	connect(m_pVCodeHp, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyVCodeSlot(QNetworkReply *)));
	connect(m_pInfoHp, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyInfoSlot(QNetworkReply *)));
	connect(m_pConnectHp, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyConnectSlot(QNetworkReply *)));

	connect(ui.lnnu_connect_pushbutton, SIGNAL(clicked()), this, SLOT(connectSlot()));

	connect(ui.lnnu_login_pushbutton, SIGNAL(clicked()), this, SLOT(sendLoginInfo()));
	connect(ui.lnnu_logout_pushbutton, SIGNAL(clicked()), this, SLOT(sendLogOutInfo()));
	connect(ui.lnnu_getcode_pushbutton, SIGNAL(clicked()), this, SLOT(sendGetPictureInfo()));
	connect(ui.lnnu_regetinfo_pushButton, SIGNAL(clicked()), this, SLOT(sendGetInfo()));

	connect(ui.lnnu_buypackage_pushButton, SIGNAL(clicked()), this, SLOT(buypackageSlot()));
	connect(ui.lnnu_detail_pushbutton, SIGNAL(clicked()), this, SLOT(detailSlot()));

	connect(ui.lnnu_user_delete_pushButton, SIGNAL(clicked()), this, SLOT(DelUserButtonSlot()));

	connect(ui.lnnu_user_comboBox, SIGNAL(activated(int)), this, SLOT(LnnuComboBoxChangedSlot(int)));
	connect(ui.lnnu_pass_le, SIGNAL(textEdited(const QString &)), this, SLOT(pawEditSlot(const QString &)));

	//加载数据
	ui.lnnu_user_comboBox->setModel(loadUserData("lnnu"));
	LnnuComboBoxChangedSlot(0);

	//设置控件属性
	ui.lnnu_login_frame->setVisible(true);
	ui.lnnu_info_frame->setVisible(false);

	ui.lnnu_code_le->setEnabled(false);

	//设置控件位置
	ui.lnnu_info_frame->setGeometry(ui.lnnu_login_frame->geometry());
}

int LnnuClass::currentClass()
{
	//初始化 
	setLabelTextAndTip(ui.lnnu_state_label, "");
	ui.lnnu_code_le->setEnabled(false);
	ui.lnnu_login_pushbutton->setEnabled(false);

	//获取验证码
	//BUG:不能用TRUE判断,窗体初始化默认全为FALSE
	if (ui.lnnu_info_frame->isVisible() == false)
		sendGetPictureInfo();

	return 1;
}
//
void LnnuClass::sendLoginInfo()
{
	//首次访问
	m_pLoginHp->setUrlCount(0);
	//取得控件内容
	QString uesrname = ui.lnnu_user_comboBox->currentText();
	QString password = ui.lnnu_pass_le->text();
	QString code = ui.lnnu_code_le->text();
	QString passmd5 = NetWorkHelper::MD5(password);
	QString checkcode = (*m_loginKeyMap)["checkcode"].toString();
	
	QString postdata = QString("account=%1&password=%2&code=%3&checkcode=%4").arg(uesrname).arg(passmd5).arg(code).arg(checkcode);

	m_pLoginHp->url(Keyword::LNNU_INFO_URL)
		->cookie()
		->data(postdata)
		->mode(HttpOp::POST)->send();
}


void  LnnuClass::sendLogOutInfo()
{
	//注销
	sendDisConnectInfo();
//	HttpOp::post(Keyword::LNNU_LOGOUT_URL,"");

	//返回到登陆界面
	ui.lnnu_login_frame->setVisible(true);
	ui.lnnu_info_frame->setVisible(false);

	//重新获取验证码
	currentClass();
	//sendGetPictureInfo();


	//设置控件
	setLabelTextAndTip(ui.lnnu_state_label, QStringLiteral("注销成功"));
	setLogined(false);

}

void LnnuClass::sendGetPictureInfo()
{
	m_pVCodeHp->setUrlCount(0);
	m_pVCodeHp->url(Keyword::LNNU_INFO_INDEX_URL)
		->mode(HttpOp::GET)->send();
}

void LnnuClass::sendGetInfo()
{
	m_pInfoHp->setUrlCount(0);
	//获取登陆信息
	QString url = Keyword::LNNU_INFO_JSON_URL +"0."+randomNumber(18);
		m_pInfoHp->url(url)
		->cookie()
		->mode(HttpOp::GET)->send();


}
void LnnuClass::connectSlot()
{
	QString text = ui.lnnu_connect_pushbutton->text();
	if (text == QStringLiteral("直接联网")){
		sendConnectInfo();
	}
	else {
		sendDisConnectInfo();
	}
}

void  LnnuClass::sendConnectInfo()
{

	QString uesrname = ui.lnnu_user_comboBox->currentText();
	QString password = ui.lnnu_pass_le->text();
	m_pConnectHp->url(Keyword::LNNU_LOGIN_URL)
		->data("DDDDD=%2C0%2C" + uesrname + "&upass=" + password)
		->mode(HttpOp::POST)->send();
}


void  LnnuClass::sendDisConnectInfo()
{
	//发送注销信息
	m_pConnectHp->url(Keyword::LNNU_LOGOUT_URL)
		->mode(HttpOp::POST)->send();

}

void LnnuClass::buypackageSlot()
{
	LnnuPayPackageClass dialog(this);

	dialog.setCookieJar(m_pCookieJar);

	dialog.exec();
}
void LnnuClass::detailSlot()
{
	//获取登陆信息
	QString url1 = Keyword::LNNU_INFO_JSON_URL + "0." + randomNumber(18);
	QString url2 = Keyword::LNNU_INFO_GET_URL;
	QString data1 = QString(HttpOp::get(url1, m_pInfoHp->getCookiesList()));
	QString data2 = QString(HttpOp::get(url2, m_pInfoHp->getCookiesList()));

	QVariantMap ResultMap1 = JsonHelper::fromJson(data1);
	QVariantMap resultNode = ResultMap1["note"].toMap();
	
	QString monleft = NetWorkHelper::SubString(data2, "id=\"noteLeftFlow\">", "</span>").value(0, "");
	QString orgmonUse = NetWorkHelper::SubString(data2, QRegExp(QStringLiteral("<td>本月流量（MB）</td>([\\s\\S]*)</td>"))).value(0, "");
	QString orgmonTime = NetWorkHelper::SubString(data2, QRegExp(QStringLiteral("<td>本月时长（分钟）</td>([\\s\\S]*)</td>"))).value(0, "");
	QString orgmonFree = NetWorkHelper::SubString(data2, QRegExp(QStringLiteral("<td>时长/流量计费（元）</td>([\\s\\S]*)</td>"))).value(0, "");
	QString orgAddress = NetWorkHelper::SubString(data2, QRegExp(QStringLiteral("<td>安装地址</td>([\\s\\S]*)</td>"))).value(0, "");

	QString monUse = NetWorkHelper::SubString(orgmonUse, QRegExp("(\\d+\\.\\d+)")).value(0, "");
	QString monFree = NetWorkHelper::SubString(orgmonFree, QRegExp("(\\d+\\.\\d+)")).value(0, "");
	QString monTime = NetWorkHelper::SubString(orgmonTime, QRegExp("(\\d+)")).value(1, "");
	QString Address = NetWorkHelper::SubString(orgAddress, QRegExp("(\\d+)")).value(1, "");

	QString message = QStringLiteral("帐号:%1\n本月已用:%2 MB(剩%3 MB)\n本月时长(分钟):%4\n流量计费:%5\n剩余金额:%6(共%7 MB)\n在线设备:%8\n到期日期:%9\n安装地址:%10\n当前状态:%11")
		.arg(resultNode["welcome"].toString())
		.arg(monUse).arg(monleft)
		.arg(monTime)
		.arg(monFree)
		.arg(resultNode["leftmoeny"].toString()).arg(resultNode["leftFlow"].toString())
		.arg(resultNode["onlinestate"].toString())
		.arg(NetWorkHelper::SubString(resultNode["overdate"].toString(), QRegExp("(\\d*)-(\\d*)-(\\d*)")).value(0, ""))
		.arg(Address)
		.arg(resultNode["status"].toString());
	QMessageBox::information(this, Keyword::LNH_NAME, message);
}
//////////////////////////
void LnnuClass::delUser()
{
	QString uesrname = ui.lnnu_user_comboBox->currentText();
	QString type = "lnnu";
	int currentId = ui.lnnu_user_comboBox->currentIndex();
	int haveId = ui.lnnu_user_comboBox->count();
	if (currentId == -1){
		LnnuComboBoxChangedSlot(-1); 
		return; 
	}

	//从数据库中删除并更新MOdel
	deleteUserData(currentId);
	
	LnnuComboBoxChangedSlot(haveId - 1);
}

void LnnuClass::alterUser()
{
	QString uesrname = ui.lnnu_user_comboBox->currentText();
	QString password = ui.lnnu_pass_le->text();
	QString type = "lnnu";

	if (!ui.lnnu_keepinmine_checkBox->isChecked())password = "";

	//数据保存
	int index = insertUserData(uesrname, password, type);

	LnnuComboBoxChangedSlot(index);

}


////////////////////////////
void LnnuClass::replyConnectSlot(QNetworkReply *reply)
{
	//不在需要判断--不连接消息
	QVariant replycode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
	if (302 == replycode.toInt())
	{
		//网页重定向
		QVariant redirectionUrl = reply->attribute(QNetworkRequest::RedirectionTargetAttribute);

		m_pConnectHp->url(redirectionUrl.toString())
					->mode(HttpOp::GET)->send();
	}
	else if (200 == replycode.toInt()){
		//获取结果信息
		QString content = QString::fromLocal8Bit(reply->readAll());
		QStringList list = NetWorkHelper::SubString(content, QRegExp("newComm\\.setNessArg\\('"), QRegExp("'\\);"));
		QString pageType = list[1];

		if (pageType == "pc_3"){
			//保存密码-如果没勾选,则只保存帐号
			alterUser();
			setLogined(true);

			setLabelTextAndTip(ui.lnnu_state_label, QStringLiteral("登陆成功"));
			ui.lnnu_connect_pushbutton->setText(QStringLiteral("直接注销"));

		}
		else{
			QString urlStr = reply->url().toString();
			int stateCode = NetWorkHelper::SubString(urlStr, QRegExp("ACLogOut="), QRegExp("(&|$)"))[0].toInt();
			if (stateCode == 1){	//注销成功
				setLabelTextAndTip(ui.lnnu_state_label, QStringLiteral("注销成功"));
				ui.lnnu_connect_pushbutton->setText(QStringLiteral("直接联网"));
			}
			else if (stateCode == 6){
				setLabelTextAndTip(ui.lnnu_state_label, QStringLiteral("用户名或密码错误"));
			}
			//else if (stateCode == 7){
			//	//获取学生信息
			//	ui.iliaoningtab->setEnabled(false);

			//	ui.lnnu_login_frame->setVisible(false);
			//	ui.lnnu_info_frame->setVisible(true);
			//}
			//错误类型7,如果已经连上网依然会触发类型7(不管密码对错)

			else setLabelTextAndTip(ui.lnnu_state_label,QStringLiteral("登陆异常"));

		}
	}
	reply->deleteLater();
}

void LnnuClass::replyVCodeSlot(QNetworkReply *reply)
{
	int nCount = m_pVCodeHp->getUrlCount();
	QVariant replycode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
	if (replycode != 200 ){
		if (replycode  == 0)
			setLabelTextAndTip(ui.lnnu_state_label, QStringLiteral("网络异常!"));
		else
			setLabelTextAndTip(ui.lnnu_state_label, QStringLiteral("信息获取失败,请重新切换选项卡."));
		reply->deleteLater();
		return;
	}

	if (nCount == 1){
		//取得Code,这里非常重要,否则可能登陆不上
		QString url = Keyword::LNNU_INFO_RANDOM_URL + "0." + randomNumber(16);
		m_pVCodeHp->url(url)
			->mode(HttpOp::GET)->send();

	}
	else if (nCount == 2){
		QByteArray pic = reply->readAll();

		ui.lnnu_code_pic->clear();
		NetWorkHelper::setLabelPicture(ui.lnnu_code_pic, &pic);

		m_pVCodeHp->url(Keyword::LNNU_INFO_INDEX_URL)
			->mode(HttpOp::GET)->send();

	}
	else if (nCount == 3){
		//取得网页内容
		QString pageContent = reply->readAll();

		QString refereurl = m_pVCodeHp->getRequest()->url().toString();
		QString checkcode = NetWorkHelper::SubString(pageContent, "checkcode=\"", "\";").value(0, "");

		(*m_loginKeyMap)["checkcode"] = checkcode;

		ui.lnnu_login_pushbutton->setEnabled(true);
		
	}
	reply->deleteLater();
}
void LnnuClass::replyLoginSlot(QNetworkReply *reply)
{
	int nCount = m_pLoginHp->getUrlCount();
	if (nCount == 1){
		//从这里开始区分到底是失败还是成功
		QString pageContent = reply->readAll();
		if (pageContent.isEmpty()){
			setLabelTextAndTip(ui.lnnu_state_label,QStringLiteral("网络异常!"));
			return;//错误
		}
		//取得页面反馈结果
		QStringList keyContent = NetWorkHelper::SubString(pageContent, QRegExp("<div id=\"fielderror2\"(.*)>"), QRegExp("</div>"));
		if (keyContent.isEmpty()) //表示成功
		{
			//保存密码-如果没勾选,则只保存帐号
			alterUser();
			setLogined(true);

			//连接互联网--如果成功连入就不需要这么多步骤
			//sendConnectInfo();
			QString uesrname = ui.lnnu_user_comboBox->currentText();
			QString password = ui.lnnu_pass_le->text();
			HttpOp::post(Keyword::LNNU_LOGIN_URL, QString("DDDDD=%2C0%2C" + uesrname + "&upass=" + password));
				

			//获取信息
			sendGetInfo();

			//设置控件
			setLabelTextAndTip(ui.lnnu_state_label,QStringLiteral("登陆成功"));

		}
		else{
			int maxtry = NetWorkHelper::SubString(pageContent, "(trytimes)>=", ")").value(0,"6").toInt();
			QString message = NetWorkHelper::SubString(keyContent.value(0,""), "nbsp;", "&lt;").value(0, QStringLiteral("登陆异常"));

			if (message.indexOf(QStringLiteral("密码不正确")) != -1){
				QStringList number = NetWorkHelper::SubString(message, QRegExp("(\\d+)"));
				QString str = QString(QStringLiteral("密码不正确:%1/%2")).arg(number[0]).arg(number[1]);

				if (number[0].toInt() >= maxtry+1){
					ui.lnnu_code_le->setEnabled(true);
				}

				setLabelTextAndTip(ui.lnnu_state_label,str);

			}
			else if (message.indexOf(QStringLiteral("验证码错误")) != -1){
				ui.lnnu_code_le->setEnabled(true);
				setLabelTextAndTip(ui.lnnu_state_label,message);
			}
			else
				setLabelTextAndTip(ui.lnnu_state_label,message);

			//重新获取验证码
			sendGetPictureInfo();
		}
	
	}
	

	reply->deleteLater();
}

void LnnuClass::replyInfoSlot(QNetworkReply *reply)
{
	int nCount = m_pInfoHp->getUrlCount();
	if (nCount == 1)
	{
		QString jsoncontent = reply->readAll();

		*m_infoResultMap = JsonHelper::fromJson(jsoncontent);

		//获取用户信息
		m_pInfoHp->url(Keyword::LNNU_INFO_GET_URL)
			->cookie()
			->mode(HttpOp::GET)->send();
	}
	else if (nCount == 2){

		QString pageContent = reply->readAll();
		QString monleft = NetWorkHelper::SubString(pageContent, "id=\"noteLeftFlow\">", "</span>").value(0, "");
		QString orgmonUse = NetWorkHelper::SubString(pageContent, QRegExp(QStringLiteral("<td>本月流量（MB）</td>([\\s\\S]*)</td>"))).value(0, "");
		QString monUse = NetWorkHelper::SubString(orgmonUse, QRegExp("(\\d+\\.\\d+)")).value(0, "");
		
		QVariantMap resultNode = (*m_infoResultMap)["note"].toMap();
		ui.lnnu_uerename_label->setText(resultNode["welcome"].toString());
		ui.lnnu_userrest_label->setText(QString(QStringLiteral("%1 MB(剩%2 MB)")).arg(monUse).arg(monleft));
		ui.lnnu_restmoney_label->setText(QString(QStringLiteral("%1(共%2 MB)")).arg(resultNode["leftmoeny"].toString()).arg(resultNode["leftFlow"].toString()));
		ui.lnnu_onlinenumber_label->setText(resultNode["onlinestate"].toString());
		ui.lnnu_deadline_label->setText(NetWorkHelper::SubString(resultNode["overdate"].toString(), QRegExp("(\\d*)-(\\d*)-(\\d*)")).value(0, ""));
		ui.lnnu_nowstate_label->setText(resultNode["status"].toString());

		//信息牌翻转
		ui.lnnu_login_frame->setVisible(false);
		ui.lnnu_info_frame->setVisible(true);
	}
	reply->deleteLater();

}

void LnnuClass::LnnuComboBoxChangedSlot(int index)
{
	if (index < 0){
		ui.lnnu_user_comboBox->setCurrentText("");
		ui.lnnu_pass_le->setText("");
		ui.lnnu_keepinmine_checkBox->setChecked(false);
		return;
	}

	QVariantMap user = readUserData(index);
	ui.lnnu_user_comboBox->setCurrentText(user.value("username","").toString());
	ui.lnnu_pass_le->setText(user.value("password", "").toString());

	ui.lnnu_keepinmine_checkBox->setChecked(!ui.lnnu_pass_le->text().isEmpty());

}

void LnnuClass::pawEditSlot(const QString &text)
{
	passwordTextEdit(ui.lnnu_keepinmine_checkBox, text);
}

void LnnuClass::DelUserButtonSlot()
{
	delUser();
}


LnnuPayPackageClass::LnnuPayPackageClass(QWidget *parent) :
	QDialog(parent)
{
	ui.setupUi(this);
	m_pCookieJar = NULL;

	connect(ui.buyButton, SIGNAL(clicked()), this, SLOT(postPayActionSlot()));

	//调整对话框大小
	setFixedSize(width(), height());
}
LnnuPayPackageClass::~LnnuPayPackageClass()
{

}

void LnnuPayPackageClass::setCookieJar(QNetworkCookieJar *jar)
{
	m_pCookieJar = jar;
}

void LnnuPayPackageClass::postPayActionSlot()
{
	QByteArray data;
	if (ui.radioButton->isChecked())
		data = "hidpckselect=207&pckid=207";
	else 
		data = "hidpckselect=208&pckid=208";

	QNetworkReply *reply=HttpOp::post(Keyword::LNNU_PAY_SAVEPACKAGE_URL, m_pCookieJar, data);
	QString replyContent = reply->readAll();

	if (!replyContent.isEmpty())
	{
		QString result = NetWorkHelper::SubString(replyContent, QStringLiteral("<strong>提示：</strong>操作状态："), "\r\n").value(0, QStringLiteral("也许成功了,只是程序没有内容"));

		QMessageBox::information(this, Keyword::LNH_NAME, result);

		//更新父窗口数据
		((LnnuClass *)this->parent())->sendGetInfo();
	}else
		QMessageBox::information(this, Keyword::LNH_NAME, QStringLiteral("处理异常,请重试"));

	reply->deleteLater();
}