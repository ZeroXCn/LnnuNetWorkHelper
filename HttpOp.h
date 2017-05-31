//作者：孟二千
//链接：http ://www.zhihu.com/question/31817619/answer/53747471
//来源：知乎
//著作权归作者所有，转载请联系作者获得授权。

//由ZeroX进行二改,日期:2017-05-28

#ifndef HTTPOP_H
#define HTTPOP_H

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkCookieJar>
#include <QtNetwork/QNetworkCookie>  
#include <QtNetwork/QSslConfiguration>  

#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QEventLoop>

// Http Operation Class
class HttpOp:public QObject
{
	Q_OBJECT
public:
	static const enum Method{ POST = 1, GET = 2 };
public:
	static class CookieJar : public QNetworkCookieJar
	{
	public:
		CookieJar(QObject *parent = NULL);
		~CookieJar();

		CookieJar(const CookieJar &);
		CookieJar *operator=(const CookieJar &);

		CookieJar(QList<QNetworkCookie>);
		CookieJar(QByteArray);
		//CookieJar *operator=(const QNetworkCookieJar &);
		

		QList<QNetworkCookie> getCookieList();
		QString getCookies();
		void setCookies(QList<QNetworkCookie> cookieList);
		void clear();

	};
private:
	int mSetUrlCount;
	QVariant mAddition;
	QNetworkCookieJar *mtCookieJar;
	QNetworkRequest *mtRequest;

	QNetworkRequest *mNetRequest;
	QNetworkAccessManager *mNetManager;
	QNetworkCookieJar *mNetCookieJar;

	QByteArray mQdataArray;
	Method mmode;

	void init();

public:
	static QByteArray post(QString url, QString data);
	static QByteArray get(QString url);
	static QByteArray post(QString url, HttpOp::CookieJar *cookiejar, QString data);
	static QByteArray get(QString url, HttpOp::CookieJar *cookiejar);
	static QNetworkReply *post(QString url, QNetworkCookieJar *cookiejar, QString data);
	static QNetworkReply *get(QString url, QNetworkCookieJar *cookiejar);
	static QNetworkReply *post(QString url, QNetworkCookieJar *cookiejar, QSslConfiguration *ssl, QString data);
	static QNetworkReply *get(QString url, QNetworkCookieJar *cookiejar, QSslConfiguration *ssl);
	static QByteArray post(QString url, QList<QNetworkCookie> cookielist, QString data);
	static QByteArray get(QString url, QList<QNetworkCookie> cookielist);
	static QByteArray post(QString url, QString cookie, QString data);
	static QByteArray get(QString url, QString cookie);

	static QNetworkRequest createRequest(QString url, QString cookies, QSslConfiguration ssl);
	static QNetworkRequest createRequest(QString url, QString cookies, QSsl::SslProtocol protocol);
	static QNetworkReply *send(QNetworkRequest request, Method method, QByteArray data="");

	static void print(QNetworkRequest *);
	static void print(QNetworkReply *);
public:
	HttpOp(QObject *parent = NULL);
	~HttpOp();
	
	HttpOp* url(QUrl url);
	HttpOp* url(QString surl);
	HttpOp* head(QByteArray key, QByteArray value);
	HttpOp* head(QNetworkRequest::KnownHeaders key, QByteArray value);
	HttpOp* ssl(QString path);
	HttpOp* ssl(QSsl::SslProtocol protocol);
	HttpOp* ssl(QSslConfiguration ssl);
	HttpOp* cookie(QString scookie);
	HttpOp* cookie(QByteArray scookie);
	HttpOp* cookie();
	HttpOp* data(QByteArray sdata);
	HttpOp* data(QString sdata);
	HttpOp* mode(Method smode);
	HttpOp* mode(QString smode);
	QNetworkReply* send();

	QUrl getUrl();
	QByteArray getCookies();
	QList<QNetworkCookie> getCookiesList();

	void setCookieJar(QNetworkCookieJar *jar);
	QNetworkCookieJar *getCookieJar();

	int getUrlCount();
	void setUrlCount(int count);

	QVariant &getAddition();
	void setAddition(const QVariant &var);

	QNetworkRequest *getRequest();
	void setRequest(QNetworkRequest *request);


	QNetworkAccessManager *getNetManager(){ return mNetManager; }
signals:
	void finished(QNetworkReply *reply);
};


#endif // HTTPOP_H