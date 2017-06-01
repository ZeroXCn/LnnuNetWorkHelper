#include <QDialog>
#include <QMessageBox>
#include "NetClass.h"
#include "ui_ilnui.h"
#include "ui_ilncard.h"
#include "ui_ilnservice.h"

#ifndef ILNCLASS_H
#define ILNCLASS_H


class IlnClass :public NetClass
{
	Q_OBJECT
private:
	HttpOp *m_pConnectHp;
	HttpOp *m_pLoginHp;
	HttpOp *m_pCookieHp;
	HttpOp *m_pInfoHp;
	HttpOp *m_pSmsHp;

	QNetworkCookieJar *m_pCookieJar;

	QVariantMap	*m_loginKeyMap;

	UserModel *m_pUserModel;

	QDialog *m_pServiceDialog;

	Ui::IlnFrame ui;
private slots:
	void replyCookieSlot(QNetworkReply *reply);
	void replyLoginSlot(QNetworkReply *reply);
	void replyConnectSlot(QNetworkReply *reply);
	void replyInfoSlot(QNetworkReply *reply);
	void replySmsSlot(QNetworkReply *reply);
private slots:
	void pawLetextEditSlot(const QString &text);
public:
	void init();
	int currentClass();
public:
	IlnClass(QWidget *parent = 0);
	~IlnClass();
public slots:
	void sendLoginInfo();
	void sendLogOutInfo();

	void sendConnectInfo();
	void sendDisConnectInfo();

	void sendSmsInfo();
private:
	void initPageCookie();


private:
	void delUser();
	void alterUser();
private slots:
	void comboBoxChangedSlot(int index);
	void pawEditSlot(const QString &);

	void delUserButtonSlot();

	void serviceSlot();
	void rechargeCardSlot();

	void updataInfoSlot();
};

	
class IlnCardClass : public QDialog
{
	Q_OBJECT
private:
	QString m_CSRFToken_HW;
private:
	HttpOp *m_pPageInfoHp;
	HttpOp *m_pActiveHp;

	QNetworkCookieJar *m_ptCJar;
	QNetworkCookieJar *m_pCookieJar;

	Ui::IlnCardForm ui;
public:
	IlnCardClass(QWidget *parent = 0);
	~IlnCardClass();

public:
	void setCookieJar(QNetworkCookieJar *);
	void setCookieList(QList<QNetworkCookie>);
	void getPageCookie();
	void setToken(QString token);

	void clearControl();
public slots:
	void getPicSlot();
	void postActiveSlot();
private slots:
	void replyPageInfoSlot(QNetworkReply *reply);
	void replyActiveSlot(QNetworkReply *reply);
signals:
	void updata();
};

class IlnServiceClass :public QDialog
{
	Q_OBJECT
private:
	HttpOp *m_pPageInfoHp;
	HttpOp *m_pVcodeHp;
	HttpOp *m_pLoginHp;
	HttpOp *m_pBusinessHp;

	QNetworkCookieJar *m_pCookieJar;

	QAbstractListModel *m_pUserModel;
	QAbstractListModel *m_pCardModel;

	QString m_CSRFToken_HW;

	QDialog *m_pIlnCardClass;
	Ui::IlnServiceForm ui;
private:
	void initPage();
	QList<QVariantMap> parsePageContent(QString &content);
public:
	void setModel(UserModel *, int index = 0);
	void setCurrentIndex(int index);

	void show();
public:
	IlnServiceClass(QWidget *parent = 0);
	~IlnServiceClass();

private slots:
	void replyPageInfoSlot(QNetworkReply *reply);
	void replyVcodeSlot(QNetworkReply *reply);
	void replyLoginSlot(QNetworkReply *reply);
	void replyBusinessSlot(QNetworkReply *reply);

private slots:
	void usercomboBoxChangedSlot(int index);
	void cardcomboBoxChangedSlot(int index);



	void changeVcodeSlot();

	void tabChangedSlot(int index);

	void loginServiceSlot();
	void sendSmsSlot();

	void forceLogoutSlot();

	void getMyBusinessSlot();
};

#endif