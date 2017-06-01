#include "NetClass.h"
#include "ui_cmccweb.h"

#include <QMessageBox>
#ifndef CMCCCLASS_H
#define CMCCCLASS_H

class CmccClass :public NetClass
{
	Q_OBJECT
private:

	HttpOp *m_pPageInfoHp;
	HttpOp *m_pLoginHp;
	HttpOp *m_pLogOutHp;
	HttpOp *m_pVcodeHp;

	QNetworkCookieJar *m_pCookieJar;

	QVariantMap *m_pInfoKey;
	QVariantMap *m_pLogoutKey;

	Ui::CmccForm ui;
public:
	CmccClass(QWidget *parent = 0);
	~CmccClass();
public:
	int currentClass();
private:
	void initPageInfo();


	void delUser();
	void alterUser();
private slots:

	void replyPageInfoSlot(QNetworkReply *reply);
	void replyLoginSlot(QNetworkReply *reply);
	void replyLogoutSlot(QNetworkReply *reply);
	void replyVcodeSlot(QNetworkReply *reply);
private slots :
	void comboboxChangedSlot(int index);
	void pawEditSlot(const QString &);
private slots:
	void deleteUserSlot();
	void loginSlot();
	void logoutSlot();
	void getsmsSlot();

	void getVcodeSlot();
};

#endif