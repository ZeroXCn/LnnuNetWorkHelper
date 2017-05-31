#include "CmccClass.h"

CmccClass::CmccClass(QWidget *parent):
	NetClass(parent)
{
	ui.setupUi(this);

	//创建对象
	m_pInfoKey = new QVariantMap();
	m_pLogoutKey= new QVariantMap();

	m_pPageInfoHp = new HttpOp();
	m_pLoginHp = new HttpOp();
	m_pLogOutHp = new HttpOp();
	m_pVcodeHp= new HttpOp();

	m_pCookieJar =new HttpOp::CookieJar();

	m_pPageInfoHp->setCookieJar(m_pCookieJar);
	m_pLoginHp->setCookieJar(m_pCookieJar);
	m_pLogOutHp->setCookieJar(m_pCookieJar);
	m_pVcodeHp->setCookieJar(m_pCookieJar);

	//初始化数据
	ui.cmcc_username_cb->setModel(loadUserData("cmcc"));
	comboboxChangedSlot(0);

	//连接信号
	connect(m_pPageInfoHp, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyPageInfoSlot(QNetworkReply *)));
	connect(m_pLoginHp, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyLoginSlot(QNetworkReply *)));
	connect(m_pLogOutHp, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyLogoutSlot(QNetworkReply *)));
	connect(m_pVcodeHp, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyVcodeSlot(QNetworkReply *)));

	connect(ui.cmcc_deleteuser_pb, SIGNAL(clicked()), this, SLOT(deleteUserSlot()));
	connect(ui.cmcc_login_pb, SIGNAL(clicked()), this, SLOT(loginSlot()));
	connect(ui.cmcc_logout_pb, SIGNAL(clicked()), this, SLOT(logoutSlot()));
	connect(ui.cmcc_sms_pb, SIGNAL(clicked()), this, SLOT(getsmsSlot()));
	connect(ui.cmcc_changevcode_pb, SIGNAL(clicked()), this, SLOT(getVcodeSlot()));


	connect(ui.cmcc_username_cb, SIGNAL(activated(int)), this, SLOT(comboboxChangedSlot(int)));

	//设置控件位置
	ui.cmcc_info_frame->setGeometry(ui.cmcc_login_frame->geometry());

	//控件设置
	ui.cmcc_login_frame->setVisible(true);
	ui.cmcc_info_frame->setVisible(false);
	ui.cmcc_vcode_le->setEnabled(false);
	
}
CmccClass::~CmccClass()
{
	m_pCookieJar->deleteLater();
	delete m_pPageInfoHp;
	delete m_pLoginHp;
	delete m_pLogOutHp;
	delete m_pVcodeHp;

	delete m_pInfoKey;
	delete m_pLogoutKey;
}

int CmccClass::currentClass()
{

	setLabelTextAndTip(ui.cmcc_state_la, QStringLiteral("正在加载信息,请稍等.."));
	ui.cmcc_login_pb->setEnabled(false);
	ui.cmcc_vcodepic_la->clear();
	ui.cmcc_vcode_le->setText("");

	if (ui.cmcc_info_frame->isVisible() == false)
		initPageInfo();

	return 1;
}
void CmccClass::initPageInfo()
{
//	((HttpOp::CookieJar *)m_pCookieJar)->clear();
	m_pPageInfoHp->setUrlCount(0);
	m_pPageInfoHp->url(Keyword::CMCC_START_URL)
		->ssl(QSsl::TlsV1SslV3)
		->mode(HttpOp::GET)->send();
}

void CmccClass::getVcodeSlot()
{
	QString code = (*m_pInfoKey)["code"].toString();
	QString ttime = systemTime_t();
	QString data = QString("vcssid=cmcc&flag=localrefresh&sessionId=%1&t=%2").arg(code).arg(ttime);
	m_pVcodeHp->setUrlCount(0);
	m_pVcodeHp->url(Keyword::CMCC_VCODE_FRESH_URL)
		->ssl(QSsl::TlsV1SslV3)
		->data(data)
		->mode(HttpOp::POST)->send();
}

void CmccClass::delUser()
{
	QString uesrname = ui.cmcc_username_cb->currentText();
	QString type = "cmcc";
	int currentId = ui.cmcc_username_cb->currentIndex();
	int haveId = ui.cmcc_username_cb->count();
	if (currentId == -1){
		comboboxChangedSlot(-1);
		return;
	}

	//从数据库中删除并更新MOdel
	deleteUserData(currentId);

	comboboxChangedSlot(haveId - 1);
}
void CmccClass::alterUser()
{
	QString uesrname = ui.cmcc_username_cb->currentText();
	QString password = ui.cmcc_password_le->text();
	QString type = "cmcc";

	if (!ui.cmcc_remember_cb->isChecked())password = "";

	//数据保存
	int index = insertUserData(uesrname, password, type);

	comboboxChangedSlot(index);
}


void CmccClass::replyPageInfoSlot(QNetworkReply *reply)
{
	QVariant replycode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
	if (302 == replycode.toInt())
	{
		QVariant redirectionUrl = reply->attribute(QNetworkRequest::RedirectionTargetAttribute);

		if (redirectionUrl.toUrl() == QUrl(Keyword::ILN_HAVE_COOKIE_URL))//已经联网
		{
			setLabelTextAndTip(ui.cmcc_state_la, QStringLiteral("您已经在互联网上!"));
			ui.cmcc_login_pb->setEnabled(false);
			reply->deleteLater();
			return;
		}
		m_pPageInfoHp->url(redirectionUrl.toString())
			->mode(HttpOp::GET)->send();

	}
	else if (200 == replycode.toInt())
	{

		QString pageContent = QString::fromLocal8Bit(reply->readAll());
		QString keyContent = NetWorkHelper::SubString(pageContent, "<frame src='", "'").value(0, "");

		if (!keyContent.isEmpty())
		{
			(*m_pInfoKey)["wlanacip"] = NetWorkHelper::SubString(keyContent, QRegExp("wlanacip="), QRegExp("&"), true, true).value(0, "");
			(*m_pInfoKey)["wlanacname"] = NetWorkHelper::SubString(keyContent, QRegExp("wlanacname="), QRegExp("&"), true, true).value(0, "");
			(*m_pInfoKey)["wlanuserip"] = NetWorkHelper::SubString(keyContent, QRegExp("wlanuserip="), QRegExp("&"), true, true).value(0, "");
			(*m_pInfoKey)["wlanacssid"] = NetWorkHelper::SubString(keyContent, QRegExp("wlanacssid="), QRegExp("&"), true, true).value(0, "");
			(*m_pInfoKey)["uaId"] = NetWorkHelper::SubString(keyContent, QRegExp("uaId="), QRegExp("&"), true, true).value(0, "");
			(*m_pInfoKey)["wlanparameter"] = NetWorkHelper::SubString(keyContent, QString("wlanparameter="), QString("")).value(0, "");

			//Info成功获取,可以登陆
			setLabelTextAndTip(ui.cmcc_state_la, "");
			setLabelTextAndTip(ui.cmcc_state_la, QStringLiteral(""));
			ui.cmcc_login_pb->setEnabled(true);
		}
		else
			setLabelTextAndTip(ui.cmcc_state_la, QStringLiteral("信息获取失败,请重新切换选项卡!"));
				
		

	}
	else
		setLabelTextAndTip(ui.cmcc_state_la, QStringLiteral("网络异常!"));


	reply->deleteLater();
}
void CmccClass::replyLoginSlot(QNetworkReply *reply)
{
	int nCount = m_pLoginHp->getUrlCount();
	/*if (!(*m_pInfoKey)["code"].toString().isEmpty()){
		nCount = 2;
		m_pLoginHp->setUrlCount(nCount);
	}
*/
	if (nCount == 1)
	{
		QString content = QString::fromLocal8Bit(reply->readAll());
		(*m_pInfoKey)["code"] = content;
		if (!content.isEmpty()){
			ui.cmcc_vcode_le->setEnabled(true);

			if (ui.cmcc_vcode_le->text().isEmpty())
			{
				ui.cmcc_login_pb->setEnabled(true);
				setLabelTextAndTip(ui.cmcc_state_la, QStringLiteral("请输入验证码"));
				ui.cmcc_vcode_le->setFocus();
				getVcodeSlot();
				reply->deleteLater();
				return;
			}
		}

		QString username = ui.cmcc_username_cb->currentText();
		QString password = ui.cmcc_password_le->text();
		QString vcode = ui.cmcc_vcode_le->text().isEmpty() ? "%CA%E4%C8%EB%D1%E9%D6%A4%C2%EB" : ui.cmcc_vcode_le->text();
		QString code = (*m_pInfoKey)["code"].toString();
		QString data = QString("staticusername=%1&spid=&staticpassword=%2&sloginvalidate=%3&sloginhiddenvalidate=%4&button2=%5&loginmode=static&wlanacip=%6&wlanacname=%7&wlanuserip=%8&wlanacssid=%9&wlanparameter=%10&portion=cmcc&uaId=%11&obsReturnAccount=%12&Token=First")
			.arg(username)
			.arg(password)
			.arg(vcode)
			.arg(code)
			.arg("%B5%C7+%C2%BC")
			.arg((*m_pInfoKey)["wlanacip"].toString())
			.arg((*m_pInfoKey)["wlanacname"].toString())
			.arg((*m_pInfoKey)["wlanuserip"].toString())
			.arg((*m_pInfoKey)["wlanacssid"].toString())
			.arg((*m_pInfoKey)["wlanparameter"].toString())
			.arg((*m_pInfoKey)["uaId"].toString())
			.arg(username);
		m_pLoginHp->url(Keyword::CMCC_LOGIN_URL)
			->ssl(QSsl::TlsV1SslV3)
			->data(data)
			->mode(HttpOp::POST)->send();
	
	}
	else if (nCount == 2)
	{
		QString content = QString::fromLocal8Bit(reply->readAll());
		if (!content.isEmpty()){

			QString msg = "";
			int success = content.indexOf("loginrr.jpg");

			if (success != -1)
			{
				//获取登录成功信息
				//QString username = NetWorkHelper::SubString(content, QStringLiteral("尊敬的用户"), "\r\n").value(0, "");
				QString username = ui.cmcc_username_cb->currentText();
				QString netTime = NetWorkHelper::SubString(content, QStringLiteral("<div class=\"loginrtt\">截至"), "，").value(0, "");
				QString netType = NetWorkHelper::SubString(content, QStringLiteral("您当前使用的套餐是：<br /><div class=\"loginortt\">"), "</div>").value(0, "");
				QString netUse = NetWorkHelper::SubString(content, QStringLiteral("您本月已使用流量：<br /><div class=\"loginorttt\">"), "</div>").value(0, "");

				//
				ui.cmcc_username_lb->setText(username);
				ui.cmcc_useType_lb->setText(netType);
				ui.cmcc_useMB_lb->setText(netUse);

				//保存密码-如果没勾选,则只保存帐号
				alterUser();
				setLogined(true);

				//
				//获取登出Key
				(*m_pLogoutKey)["username"] = NetWorkHelper::SubString(content, "id=\"username\" value=\"", "\"").value(0, "");
				(*m_pLogoutKey)["backupInfo"] = NetWorkHelper::SubString(content, "id=\"backupInfo\" value=\"", "\"").value(0, "");
				(*m_pLogoutKey)["Token"] = NetWorkHelper::SubString(content, "name=\"Token\" value=\"", "\"").value(0, "");
				/*(*m_pLogoutKey)["logintime"] = NetWorkHelper::SubString(content, "name=\"logintime\" value=\"", "\"").value(0, "");
				(*m_pLogoutKey)["remaintime"] = NetWorkHelper::SubString(content, "name=\"remaintime\" value=\"", "\"").value(0, "");
				(*m_pLogoutKey)["areacode"] = NetWorkHelper::SubString(content, "name=\"areacode\" value=\"", "\"").value(0, "");
				(*m_pLogoutKey)["wlanacip"] = NetWorkHelper::SubString(content, "name=\"wlanacip\" value=\"", "\"").value(0, "");
				(*m_pLogoutKey)["wlanacname"] = NetWorkHelper::SubString(content, "name=\"wlanacname\" value=\"", "\"").value(0, "");
				(*m_pLogoutKey)["wlanuserip"] = NetWorkHelper::SubString(content, "name=\"wlanuserip\" value=\"", "\"").value(0, "");
				(*m_pLogoutKey)["productid"] = NetWorkHelper::SubString(content, "name=\"productid\" value=\"", "\"").value(0, "");
				(*m_pLogoutKey)["effecttime"] = NetWorkHelper::SubString(content, "name=\"effecttime\" value=\"", "\"").value(0, "");
				(*m_pLogoutKey)["expiretime"] = NetWorkHelper::SubString(content, "name=\"expiretime\" value=\"", "\"").value(0, "");
				(*m_pLogoutKey)["keystr"] = NetWorkHelper::SubString(content, "name=\"keystr\" value=\"", "\"").value(0, "");
				(*m_pLogoutKey)["cf"] = NetWorkHelper::SubString(content, "name=\"cf\" value=\"", "\"").value(0, "");
				(*m_pLogoutKey)["logouttype"] = NetWorkHelper::SubString(content, "name=\"logouttype\" value=\"", "\"").value(0, "");

				(*m_pLogoutKey)["logonsessid"] = NetWorkHelper::SubString(content, "name=\"logonsessid\" value=\"", "\"").value(0, "");
				(*m_pLogoutKey)["portion"] = NetWorkHelper::SubString(content, "name=\"portion\" value=\"", "\"").value(0, "");
				(*m_pLogoutKey)["wlanacssid"] = NetWorkHelper::SubString(content, "name=\"wlanacssid\" value=\"", "\"").value(0, "");
				(*m_pLogoutKey)["uaId"] = NetWorkHelper::SubString(content, "name=\"uaId\" value=\"", "\"").value(0, "");*/

				//(*m_pLogoutKey)["passflag"] = NetWorkHelper::SubString(content, "name=\"passflag\" value=\"", "\"").value(0, "");
				//(*m_pLogoutKey)["passtype"] = NetWorkHelper::SubString(content, "name=\"passtype\" value=\"", "\"").value(0, "");
				//(*m_pLogoutKey)["isRoam"] = NetWorkHelper::SubString(content, "name=\"isRoam\" value=\"", "\"").value(0, "");

				setLabelTextAndTip(ui.cmcc_state_la, QStringLiteral("登陆成功!"));
				ui.cmcc_info_frame->setVisible(true);
				ui.cmcc_login_frame->setVisible(false);
			}
			else setLabelTextAndTip(ui.cmcc_state_la, QStringLiteral("登陆失败,请重试!"));
		}
		else setLabelTextAndTip(ui.cmcc_state_la, QStringLiteral("网络异常!"));
		ui.cmcc_login_pb->setEnabled(true);

	}
	reply->deleteLater();
}

void CmccClass::replyLogoutSlot(QNetworkReply *reply)
{
	QString content = QString::fromLocal8Bit(reply->readAll());
	if (!content.isEmpty())
	{
		QString msg = NetWorkHelper::SubString(content, "alert(\"", "\");").value(0, "");
		if (msg.indexOf(QStringLiteral("下线成功")) != -1){
			currentClass();
			setLabelTextAndTip(ui.cmcc_state_la, QStringLiteral("注销成功!"));
			ui.cmcc_login_frame->setVisible(true);
			ui.cmcc_info_frame->setVisible(false);
		}else
			QMessageBox::information(this, Keyword::LNH_NAME, msg);
	}
	reply->deleteLater();
}
void CmccClass::comboboxChangedSlot(int index)
{
	//设置控件
	comboxChangedIndex(ui.cmcc_username_cb, ui.cmcc_password_le, index);
	ui.cmcc_remember_cb->setChecked(!ui.cmcc_password_le->text().isEmpty());

}


void CmccClass::deleteUserSlot()
{
	delUser();
}
void CmccClass::loginSlot()
{
	QString data = QString("vcssid=cmcc&userName=%1&t=%2").arg(ui.cmcc_username_cb->currentText()).arg(systemTime_t());
	m_pLoginHp->setUrlCount(0);
	m_pLoginHp->url(Keyword::CMCC_COOKIECLOSEDCODE_URL)
		->ssl(QSsl::TlsV1SslV3)
		->data(data)
		->mode(HttpOp::POST)->send();

	ui.cmcc_login_pb->setEnabled(false);

}
void CmccClass::logoutSlot()
{
	QString data=QString("button2=%1&username=%2&backupInfo=%3&logintime=&remaintime=&areacode=&wlanacip=%4&wlanacname=%5&wlanuserip=%6&productid=&effecttime=&expiretime=&keystr=&cf=&logouttype=TYPESUBMIT&logonsessid=&portion=cmcc&wlanacssid=%7&uaId=%8&Token=%9&passflag=1&passtype=0&isRoam=null")
					.arg("%CF%C2++%CF%DF")
					.arg((*m_pLogoutKey)["username"].toString())
					.arg((*m_pLogoutKey)["backupInfo"].toString())
					.arg((*m_pInfoKey)["wlanacip"].toString())
					.arg((*m_pInfoKey)["wlanacname"].toString())
					.arg((*m_pInfoKey)["wlanuserip"].toString())
					.arg((*m_pInfoKey)["wlanacssid"].toString())
					.arg((*m_pInfoKey)["uaId"].toString())
					.arg((*m_pLogoutKey)["Token"].toString());
	m_pLogOutHp->url(Keyword::CMCC_LOGOUT_URL)
		->data(data)
		->mode(HttpOp::POST)->send();
}
void CmccClass::getsmsSlot()
{
	QString username = ui.cmcc_username_cb->currentText();
	QString data = QString("username=%1&wlanacname=%2&wlanacssid=%3&wlanuserip=%4&wlanacip=&t=%5")
		.arg(username)
		.arg((*m_pInfoKey)["wlanacname"].toString())
		.arg((*m_pInfoKey)["wlanacssid"].toString())
		.arg((*m_pInfoKey)["wlanuserip"].toString())
		.arg(NetClass::systemTime_t());
	QNetworkReply *reply = HttpOp::send(HttpOp::createRequest(Keyword::CMCC_SMSPAW_URL, ((HttpOp::CookieJar *) m_pCookieJar)->getCookies(), QSsl::TlsV1SslV3), HttpOp::POST, data.toLatin1());
	QString content = reply->readAll();
	if (!content.isEmpty())
	{
		QMessageBox::information(this, Keyword::LNH_NAME, content);
	}
	reply->deleteLater();
}
void CmccClass::replyVcodeSlot(QNetworkReply *reply)
{
	int nCount = m_pVcodeHp->getUrlCount();
	if (nCount == 1)
	{
		QString code = (*m_pInfoKey)["code"].toString();
		QString ttime = systemTime_t();
		QString url = QString(Keyword::CMCC_VCODE_URL).arg(code).arg(ttime);
		m_pVcodeHp->url(url)
			->ssl(QSsl::TlsV1SslV3)
			->mode(HttpOp::GET)->send();
	}
	else if (nCount == 2)
	{
		QByteArray data = reply->readAll();
		if (!data.isEmpty())
		{
			setLabelPicture(ui.cmcc_vcodepic_la, &data);
		}
	}
	reply->deleteLater();
}