#include <QString>
#include <QVariantMap>
#ifndef KEYWORD_H
#define KEYWORD_H

namespace Keyword
{
	const QString LNH_NAME = QStringLiteral("辽师网络登陆助手");
	const float LNH_VERSION_NUM = 2.00f;
	const QString LNH_VERSION_STR = "v2.0";
	const QString LNH_LASTTIME_STR = QStringLiteral("2017年6月");
	const QString LNH_GETINFO_URL = "http://xjcsmap.vicp.net/LnnuNetworkHelper/Information";

	////////////////////////////////////////////////////////////////////////////////////////////////
	const QString LNNU_LOGIN_URL = "http://210.47.208.191:801/eportal/?c=ACSetting&a=Login";
	const QString LNNU_LOGINSTATE_CHECK_URL = "http://210.47.208.191/3.htm";
	const QString LNNU_LOGOUT_URL = "http://210.47.208.191:801/eportal/?c=ACSetting&a=Logout";
	const QString LNNU_INFO_INDEX_URL = "http://account.lnnu.edu.cn:8080/nav_login";
	const QString LNNU_INFO_URL = "http://account.lnnu.edu.cn:8080/LoginAction.action";
	const QString LNNU_INFO_RANDOM_URL = "http://account.lnnu.edu.cn:8080/RandomCodeAction.action?randomNum=";
	const QString LNNU_INFO_GET_URL = "http://account.lnnu.edu.cn:8080/nav_getUserInfo";
	const QString LNNU_INFO_JSON_URL = "http://account.lnnu.edu.cn:8080/refreshaccount?t=";

	const QString LNNU_PAY_SAVEPACKAGE_URL = "http://account.lnnu.edu.cn:8080/savepackageAction.action";

	//////////////////////////////////////////////////////////////////////////////////////////////////////
	const QString ILN_COOKIE_URL = "http://www.hao123.com/";	//存在302跳转--不存在则是联网成功
	const QString ILN_HAVE_COOKIE_URL = "https://www.hao123.com/";	//存在302跳转--不存在则是联网成功
	const QString ILN_LOGIN_URL_INDEX = "http://www.i-liaoning.com.cn:8088/iLN/AggrInfo/pc/offline/index.jsp";
	const QString ILN_LOGIN_SMS_URL = "http://www.i-liaoning.com.cn:8088/sendMsgPwd.do";
	const QString ILN_LOGIN_URL = "http://www.i-liaoning.com.cn:8088/loginServlet.do";
	const QString ILN_LOGOUT_URL = "http://www.i-liaoning.com.cn:8088/offineLogout.do";
	const QString ILN_OPENWIFI_URL = "http://www.i-liaoning.com.cn:8088/loginServlet.do";
	const QString ILN_CLOSEWIFI_URL = "http://www.i-liaoning.com.cn:8088/logout.do";

	const QString ILN_CARD_SERVICE_URL = "http://www.i-liaoning.com.cn//SSOValid.do?CSRFDOURL=showLogin";
	const QString ILN_CARD_CARDVCODE_URL = "http://www.i-liaoning.com.cn//randomImageCode";
	const QString ILN_CARD_CARDCHECK_URL = "http://www.i-liaoning.com.cn//cardCheck.do";
	const QString ILN_CARD_CARDACTIVE_URL = "http://www.i-liaoning.com.cn//cardActive.do";


	const QString ILN_SERVICE_START_URL = "http://www.i-liaoning.com.cn/redirectLogin.do";
	const QString ILN_SERVICE_VCODE_URL = "http://www.i-liaoning.com.cn/verifycode";
	const QString ILN_SERVICE_LOGIN_URL = "http://www.i-liaoning.com.cn/login.do";	//
	const QString ILN_SERVICE_SMSPAW_URL = "http://www.i-liaoning.com.cn/sendMsgPwd.do";

	const QString ILN_SERVICE_LOGINFORM_URL = "http://www.i-liaoning.com.cn//%1";
	const QString ILN_SERVICE_OFFER_URL = "http://www.i-liaoning.com.cn//MyOfferServlet.do?CSRFToken_HW=%1&url=%2";
	const QString ILN_SERVICE_FORCELOGOUT_URL = "http://www.i-liaoning.com.cn//forcedLogout.do";

	///////////////////////////////////////////////////////////////////////////
	const QString CMCC_START_URL = "http://www.hao123.com/";
	const QString CMCC_HAD_NET_URL = "https://www.hao123.com/";
	const QString CMCC_LOGIN_URL = "https://221.176.1.140:8090/web/login.do";
	const QString CMCC_COOKIECLOSEDCODE_URL = "https://221.176.1.140:8090/web/cookieclosedCode.do";
	const QString CMCC_VCODE_FRESH_URL = "https://221.176.1.140:8090/web/verificationCodereFresh.do";
	const QString CMCC_VCODE_URL = "https://221.176.1.140:8090/web/verifyCodeImage.do?vcssid=cmcc&code=%1&t=%2";
	const QString CMCC_LOGOUT_URL = "http://221.176.1.140:8080/web/logout.do";
	const QString CMCC_SMSPAW_URL = "https://221.176.1.140:8090/web/applyDynaPasswd.do";
	///////////////////////////////////////
	const QString PASSWORD_KEY = "ilovelnnuiamshichaojun";

	const QString DATABASE_PATH = "userdatabase.db";
	const QString DATABASE_USER_TABLE = "user";
	const QString DATABASE_CONFIG_TABLE = "config";

	////////////////////////////////////////
	//全局变量
	extern QVariantMap CONFIGMAP;

};

#endif