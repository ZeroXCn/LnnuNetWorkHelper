#include "NetClass.h"
#include "ui_lnnuui.h"
#include "ui_lnnupaypackage.h"

#include <QMessageBox>
#ifndef LNNUCLASS_H
#define LNNUCLASS_H

#include "HttpOp.h"
#include "Keyword.h"
class LnnuClass :public NetClass
{
	Q_OBJECT
private:
	HttpOp *m_pConnectHp;
	HttpOp *m_pLoginHp;
	HttpOp *m_pVCodeHp;
	HttpOp *m_pInfoHp;

	QNetworkCookieJar *m_pCookieJar;

	QVariantMap	*m_loginKeyMap;
	QVariantMap	*m_infoResultMap;

	Ui::LnnuFrame ui;
private slots:
	void replyLoginSlot(QNetworkReply *reply);
	void replyConnectSlot(QNetworkReply *reply);

	void replyVCodeSlot(QNetworkReply *reply);
	void replyInfoSlot(QNetworkReply *reply);
public slots:
	void sendLoginInfo();
	void sendLogOutInfo();

	void sendGetPictureInfo();
	void sendGetInfo();
private slots:
	void connectSlot();

	void buypackageSlot();
	void detailSlot();
private:
	void sendConnectInfo();
	void sendDisConnectInfo();
private:
	void delUser();
	void alterUser();
private slots:
	void LnnuComboBoxChangedSlot(int index);
	void DelUserButtonSlot();
public:
	void init();
	int currentClass();

	LnnuClass(QWidget *parent = 0);
	~LnnuClass();
};

class LnnuPayPackageClass :public QDialog
{
	Q_OBJECT
private:
	QNetworkCookieJar *m_pCookieJar;

	Ui::PayPackageDialog ui;
public:
	LnnuPayPackageClass(QWidget *parent = 0);
	~LnnuPayPackageClass();

	void setCookieJar(QNetworkCookieJar *);

private slots:
	void postPayActionSlot();
};

#endif