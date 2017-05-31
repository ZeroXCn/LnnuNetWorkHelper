//作者：孟二千
//链接：http ://www.zhihu.com/question/31817619/answer/53747471
//来源：知乎
//著作权归作者所有，转载请联系作者获得授权。

#include "httpop.h"


HttpOp* HttpOp::url(QString surl)
{
	//每次重新设置URL都必须清空一次Request对象
	//模式更换,做清空操作
	//if (surl != this->mUrl){
	delete this->mtRequest;
	this->mNetRequest = this->mtRequest = new QNetworkRequest();
	this->mNetRequest->setHeader(QNetworkRequest::UserAgentHeader, "Mozilla/5.0 (Windows NT 6.1; WOW64; Trident/7.0; rv:11.0) like Gecko");
	this->mNetRequest->setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
	//}

	this->mSetUrlCount++;

	this->mNetRequest->setUrl(QUrl(surl));
	this->mmode = GET;
	return this;
}

HttpOp* HttpOp::url(QUrl url)
{
	return this->url(url.toString());
}

HttpOp* HttpOp::head(QByteArray key, QByteArray value)
{
	this->mNetRequest->setRawHeader(key, value);
	return this;
}
HttpOp* HttpOp::head(QNetworkRequest::KnownHeaders key, QByteArray value)
{
	this->mNetRequest->setHeader(key, value);
	return this;
}

HttpOp* HttpOp::ssl(QString path)
{
	QSslConfiguration config;
	QList<QSslCertificate> certs = QSslCertificate::fromPath(path);
	config.setCaCertificates(certs);
	this->mNetRequest->setSslConfiguration(config);

	return this;
}
HttpOp* HttpOp::ssl(QSsl::SslProtocol protocol)
{
	QSslConfiguration config;
	config.setPeerVerifyMode(QSslSocket::VerifyNone);
	config.setProtocol(protocol);
	this->mNetRequest->setSslConfiguration(config);

	return this;
}

HttpOp* HttpOp::ssl(QSslConfiguration ssl)
{
	this->mNetRequest->setSslConfiguration(ssl);
	return this;
}

HttpOp* HttpOp::cookie()
{
	QVariant var;
	var.setValue(mNetCookieJar->cookiesForUrl(mNetRequest->url()));
	this->mNetRequest->setHeader(QNetworkRequest::CookieHeader, var);

	return this;
}

HttpOp* HttpOp::cookie(QString scookie)
{
	
	QByteArray lbyte;
	lbyte.append(scookie);

	this->mNetRequest->setRawHeader("Cookie", lbyte);
	return this;
}

HttpOp* HttpOp::cookie(QByteArray scookie)
{
//	mNetCookieJar->setCookiesFromUrl(QNetworkCookie::parseCookies(scookie), mNetRequest->url());
	
	QVariant var;
	var.setValue(QNetworkCookie::parseCookies(scookie));
	this->mNetRequest->setHeader(QNetworkRequest::CookieHeader, var);
	
	return this;
}

// set send data for class member
HttpOp* HttpOp::data(QByteArray sdata)
{
	HttpOp::mode(POST);
	this->mQdataArray = sdata;
	this->mNetRequest->setHeader(QNetworkRequest::ContentLengthHeader, this->mQdataArray.length());

	return this;
}

HttpOp* HttpOp::data(QString sdata)
{
	QByteArray ldata = "";
	ldata.append(sdata);
	return data(ldata);
}

// set send mode (post or get)
HttpOp* HttpOp::mode(Method smode)
{
	this->mmode = smode;
	return this;
}

HttpOp* HttpOp::mode(QString smode)
{
	if (smode.toUpper() == "POST"){
		this->mmode = HttpOp::POST;
	}
	else this->mmode = HttpOp::GET;
	return this;
}

// send data
QNetworkReply* HttpOp::send()
{
	if (this->mmode == POST)
	{

		this->mNetRequest->setUrl(this->mNetRequest->url());
		return mNetManager->post(*this->mNetRequest, this->mQdataArray);
	}
	else{

		this->mNetRequest->setUrl(this->mNetRequest->url());
		return mNetManager->get(*this->mNetRequest);
	}

	return NULL;
}

void HttpOp::init()
{
	mNetManager = new QNetworkAccessManager();
	mNetRequest = mtRequest = new QNetworkRequest();
	mNetCookieJar = mtCookieJar = new CookieJar();
	mNetManager->setCookieJar(mNetCookieJar);
	mtCookieJar->setParent(NULL);	//防止共享删除

	connect(mNetManager, SIGNAL(finished(QNetworkReply *)), this, SIGNAL(finished(QNetworkReply *)));
	this->mmode = GET;
	this->mSetUrlCount = 0;

}


QUrl HttpOp::getUrl()
{
	return mNetRequest->url();
}

QByteArray HttpOp::getCookies()
{
	QByteArray cookieStr;
//	QList<QNetworkCookie> cookies = ((MyNetworkCookie*)mNetCookieJar)->getCookies();
	QList<QNetworkCookie> cookies = mNetCookieJar->cookiesForUrl(mNetRequest->url());
	for (int i = 0; i < cookies.count(); i++){
		cookieStr.append(cookies.at(i).toRawForm());
		cookieStr.append("; ");
	}
	return cookieStr;
}

QList<QNetworkCookie> HttpOp::getCookiesList()
{
	return mNetCookieJar->cookiesForUrl(mNetRequest->url());
}

int HttpOp::getUrlCount()
{
	return this->mSetUrlCount;
}
void HttpOp::setUrlCount(int count)
{
	this->mSetUrlCount = count;
}

QVariant &HttpOp::getAddition()
{
	return this->mAddition;
}
void HttpOp::setAddition(const QVariant &var)
{
	this->mAddition=var;
}

QNetworkRequest *HttpOp::getRequest()
{
	return this->mNetRequest;
}
void  HttpOp::setRequest(QNetworkRequest *request)
{

	this->mNetRequest = request;
}

void HttpOp::setCookieJar(QNetworkCookieJar *jar)
{
	this->mNetCookieJar = jar;
	this->mNetManager->setCookieJar(jar);
	jar->setParent(NULL);//防止共享删除
	
}
QNetworkCookieJar *HttpOp::getCookieJar()
{
	return this->mNetCookieJar;
}

// Structure function
HttpOp::HttpOp(QObject *parent)
	:QObject(parent)
{
	this->init();
	
}

HttpOp::~HttpOp()
{
	//disconnect(mNetManager, SIGNAL(finished(QNetworkReply *)), this, SIGNAL(finished(QNetworkReply *)));
	
	mtCookieJar->deleteLater();//删除Cookie,之前必须设置Parent(0);
	mNetManager->deleteLater();	
	
	delete mtRequest;
}

QByteArray HttpOp::post(QString url, QString data)
{
	QNetworkReply *reply = post(url, (QNetworkCookieJar *)NULL, data);
	QByteArray result;
	result.append(reply->readAll());

	reply->deleteLater();

	return result;
}                
QByteArray HttpOp::get(QString url)
{
	QNetworkReply *reply = get(url, (QNetworkCookieJar *)NULL);
	QByteArray result;
	result.append(reply->readAll());

	reply->deleteLater();
	return result;
}
QByteArray HttpOp::post(QString url, QString cookie, QString data)
{
	return post(url, QNetworkCookie::parseCookies(cookie.toLatin1()), data);

}
QByteArray HttpOp::get(QString url, QString cookie)
{
	return get(url, QNetworkCookie::parseCookies(cookie.toLatin1()));
}

QByteArray HttpOp::post(QString url, QList<QNetworkCookie> cookielist, QString data)
{
	QNetworkReply *reply;
	QNetworkCookieJar cookiejar;
	cookiejar.setCookiesFromUrl(cookielist, QUrl(url));
	reply = post(url, &cookiejar, data);

	QByteArray result;
	result.append(reply->readAll());

	reply->deleteLater();

	return result;
}
QByteArray HttpOp::get(QString url, QList<QNetworkCookie> cookielist)
{
	QNetworkReply *reply;
	QNetworkCookieJar cookiejar;
	cookiejar.setCookiesFromUrl(cookielist, QUrl(url));
	reply = get(url, &cookiejar);

	QByteArray result;
	result.append(reply->readAll());

	reply->deleteLater();

	return result;
}

QByteArray HttpOp::post(QString url, HttpOp::CookieJar *cookiejar, QString data)
{
	QNetworkReply *reply;

	reply = post(url, (QNetworkCookieJar *)cookiejar, data);

	QByteArray result;
	result.append(reply->readAll());

	reply->deleteLater();

	return result;

}
QByteArray HttpOp::get(QString url, HttpOp::CookieJar *cookiejar)
{
	QNetworkReply *reply;
	reply = get(url, (QNetworkCookieJar *)cookiejar);

	QByteArray result;
	result.append(reply->readAll());

	reply->deleteLater();

	return result;
}

QNetworkReply *HttpOp::post(QString url, QNetworkCookieJar *cookiejar, QString data)
{
	return post(url, cookiejar, NULL, data);
}
QNetworkReply *HttpOp::get(QString url, QNetworkCookieJar *cookiejar)
{
	return get(url, cookiejar, NULL);
}
QNetworkReply *HttpOp::post(QString url, QNetworkCookieJar *cookiejar, QSslConfiguration *ssl, QString data)
{
	QNetworkRequest lNetRequest;
	QNetworkAccessManager lNetManager;
	if (cookiejar){
		lNetManager.setCookieJar(cookiejar);
		cookiejar->setParent(NULL);	//共享变量防删除
	}

	if (ssl){
		lNetRequest.setSslConfiguration(*ssl);
	}

	QByteArray lQdataArray("");

	lQdataArray.append(data);

	lNetRequest.setUrl(QUrl(QString(url)));
	lNetRequest.setHeader(QNetworkRequest::ContentLengthHeader, lQdataArray.length());
	lNetRequest.setHeader(QNetworkRequest::UserAgentHeader, "Mozilla/5.0 (Windows NT 6.1; WOW64; Trident/7.0; rv:11.0) like Gecko");
	lNetRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

	QNetworkReply *reply = lNetManager.post(lNetRequest, lQdataArray);

	if (reply){
		//事件同步
		QEventLoop eventLoop;
		connect(reply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);
		//connect(&lNetManager, &QNetworkAccessManager::finished, &eventLoop, &QEventLoop::quit);
		eventLoop.exec(QEventLoop::ExcludeUserInputEvents);
	}
	reply->setParent(NULL);	//防止被lNetManager析构
	return reply;
}
QNetworkReply *HttpOp::get(QString url, QNetworkCookieJar *cookiejar, QSslConfiguration *ssl)
{
	QNetworkRequest lNetRequest;
	QNetworkAccessManager lNetManager;

	if (cookiejar){
		lNetManager.setCookieJar(cookiejar);
		cookiejar->setParent(NULL);	//共享变量防删除
	}

	if (ssl){
		lNetRequest.setSslConfiguration(*ssl);
	}

	lNetRequest.setUrl(QUrl(QString(url)));

	lNetRequest.setHeader(QNetworkRequest::UserAgentHeader, "Mozilla/5.0 (Windows NT 6.1; WOW64; Trident/7.0; rv:11.0) like Gecko");
	lNetRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");


	QNetworkReply *reply = lNetManager.get(lNetRequest);

	if (reply){
		//事件同步
		QEventLoop eventLoop;
		connect(reply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);
		//connect(&lNetManager, &QNetworkAccessManager::finished, &eventLoop, &QEventLoop::quit);
		eventLoop.exec(QEventLoop::ExcludeUserInputEvents);

	}
	reply->setParent(NULL);	//防止被lNetManager析构
	return reply;

}

QNetworkRequest HttpOp::createRequest(QString url, QString cookies, QSslConfiguration ssl)
{
	QNetworkRequest lNetRequest;
	lNetRequest.setUrl(QUrl(QString(url)));
	lNetRequest.setRawHeader("Cookie", cookies.toLatin1());
	lNetRequest.setHeader(QNetworkRequest::UserAgentHeader, "Mozilla/5.0 (Windows NT 6.1; WOW64; Trident/7.0; rv:11.0) like Gecko");
	lNetRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
	lNetRequest.setSslConfiguration(ssl);
	return lNetRequest;

}
QNetworkRequest HttpOp::createRequest(QString url, QString cookies, QSsl::SslProtocol protocol)
{
	QSslConfiguration config;
	config.setPeerVerifyMode(QSslSocket::VerifyNone);
	config.setProtocol(protocol);
	return createRequest(url, cookies, config);
}


QNetworkReply *HttpOp::send(QNetworkRequest request, Method method, QByteArray data)
{
	QNetworkRequest &lNetRequest = request;
	QNetworkAccessManager lNetManager;
	QByteArray &lQdataArray = data;
	QNetworkReply *reply;

	if (method == POST){
		lNetRequest.setHeader(QNetworkRequest::ContentLengthHeader, lQdataArray.length());
		reply = lNetManager.post(lNetRequest, lQdataArray);
	}
	else
		reply=lNetManager.get(lNetRequest);


	if (reply){
		//事件同步
		QEventLoop eventLoop;
		connect(reply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);
		//connect(&lNetManager, &QNetworkAccessManager::finished, &eventLoop, &QEventLoop::quit);
		eventLoop.exec(QEventLoop::ExcludeUserInputEvents);

	}
	reply->setParent(NULL);	//防止被lNetManager析构
	return reply;

}



void HttpOp::print(QNetworkRequest *request)
{
	if (request == NULL) return;
	qDebug() << "";
	qDebug() << "[Request]:" << request;
	qDebug() << request->url();
	qDebug() << "Accept : " << request->rawHeader("Accept");
	qDebug() << "Accept-Encoding : " << request->rawHeader("Accept-Encoding");
	qDebug() << "Accept-Language : " << request->rawHeader("Accept-Language");
	qDebug() << "Cache-Control : " << request->rawHeader("Cache-Control");
	qDebug() << "Connection : " << request->rawHeader("Connection");
	qDebug() << "Content-Length : " << request->rawHeader("Content-Length");
	qDebug() << "Content-Type : " << request->rawHeader("Content-Type");
	qDebug() << "Cookie : " << request->rawHeader("Cookie");
	qDebug() << "DNT : " << request->rawHeader("DNT");
	qDebug() << "Host : " << request->rawHeader("Host");
	qDebug() << "Referer : " << request->rawHeader("Referer");
	qDebug() << "User-Agent : " << request->rawHeader("User-Agent");

}
void HttpOp::print(QNetworkReply *reply)
{
	if (reply == NULL) return;
	qDebug() << "";
	qDebug() << "[Reply]:" << reply;
	qDebug() << reply->url();
	qDebug() << "HttpStatusCodeAttribute : " << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toString();
	qDebug() << "HttpReasonPhraseAttribute : " << reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
	qDebug() << "Server : " << reply->rawHeader("Server");
	qDebug() << "Set-Cookie : " << reply->rawHeader("Set-Cookie");
	qDebug() << "Content-Type : " << reply->rawHeader("Content-Type");
	qDebug() << "Transfer-Encoding : " << reply->rawHeader("Transfer-Encoding");
	qDebug() << "Content-Length : " << reply->size();
	qDebug() << "Date : " << reply->rawHeader("Date");

	qDebug() << "RedirectionTargetAttribute : " << reply->attribute(QNetworkRequest::RedirectionTargetAttribute).toString();
	qDebug() << "ConnectionEncryptedAttribute : " << reply->attribute(QNetworkRequest::ConnectionEncryptedAttribute).toString();
	qDebug() << "CacheLoadControlAttribute : " << reply->attribute(QNetworkRequest::CacheLoadControlAttribute).toString();
	qDebug() << "CacheSaveControlAttribute : " << reply->attribute(QNetworkRequest::CacheSaveControlAttribute).toString();
	qDebug() << "SourceIsFromCacheAttribute : " << reply->attribute(QNetworkRequest::SourceIsFromCacheAttribute).toString();
	qDebug() << "DoNotBufferUploadDataAttribute : " << reply->attribute(QNetworkRequest::DoNotBufferUploadDataAttribute).toString();
	qDebug() << "HttpPipeliningAllowedAttribute : " << reply->attribute(QNetworkRequest::HttpPipeliningAllowedAttribute).toString();
	qDebug() << "HttpPipeliningWasUsedAttribute : " << reply->attribute(QNetworkRequest::HttpPipeliningWasUsedAttribute).toString();
	qDebug() << "CustomVerbAttribute : " << reply->attribute(QNetworkRequest::CustomVerbAttribute).toString();
	qDebug() << "CookieLoadControlAttribute : " << reply->attribute(QNetworkRequest::CookieLoadControlAttribute).toString();
	qDebug() << "CookieSaveControlAttribute : " << reply->attribute(QNetworkRequest::CookieSaveControlAttribute).toString();
	qDebug() << "AuthenticationReuseAttribute : " << reply->attribute(QNetworkRequest::AuthenticationReuseAttribute).toString();
	qDebug() << "BackgroundRequestAttribute : " << reply->attribute(QNetworkRequest::BackgroundRequestAttribute).toString();
}


HttpOp::CookieJar::CookieJar(QObject *parent)
: QNetworkCookieJar(parent)
{

}
HttpOp::CookieJar::CookieJar(const CookieJar &jar)
{
	this->setAllCookies(jar.allCookies());
}
HttpOp::CookieJar::CookieJar(QList<QNetworkCookie> list)
{
	this->setAllCookies(list);
}
HttpOp::CookieJar::CookieJar(QByteArray scookie)
{
	this->setAllCookies(QNetworkCookie::parseCookies(scookie));
}

HttpOp::CookieJar *HttpOp::CookieJar::operator=(const CookieJar &jar)
{
	this->setAllCookies(jar.allCookies());
	return this;
}


HttpOp::CookieJar::~CookieJar()
{

}

QList<QNetworkCookie> HttpOp::CookieJar::getCookieList()
{
	return allCookies();
}

QString HttpOp::CookieJar::getCookies()
{
	QByteArray cookieStr;
	QList<QNetworkCookie> cookies = allCookies();
	for (int i = 0; i < cookies.count(); i++){
		cookieStr.append(cookies.at(i).toRawForm());
		cookieStr.append("; ");
	}
	return cookieStr;
}

void HttpOp::CookieJar::setCookies(QList<QNetworkCookie> cookieList)
{
	this->setAllCookies(cookieList);
}
void HttpOp::CookieJar::clear()
{
	QList<QNetworkCookie> cookies = allCookies();
	for (int i = 0; i < cookies.size(); i++)
		QNetworkCookieJar::deleteCookie(cookies.at(i));
	this->setAllCookies(QNetworkCookie::parseCookies(""));
}