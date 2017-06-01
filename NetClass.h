#include "UserModel.h"
#include "Keyword.h"
#include "HttpOp.h"
#include "SQLiteDB.h"
#include "Encryption.h"
#include "JsonHelper.h"
#include "NetWorkHelper.h"

#include <QList>
#include <QVariantMap>

#include <QComboBox>
#include <QLineEdit>
#include <QCheckBox>
#ifndef NETCLASS_H
#define NETCLASS_H

class NetClass : public QWidget
{
	Q_OBJECT
protected:
	QAbstractListModel *m_pUserModel;

	static bool g_isLogined;
public:
	static bool getLogined();
	static void setLogined(bool state);
public:
	NetClass(QWidget *parent = 0);
	~NetClass();

	QDialog *getDialog();
	QAbstractListModel *getModel();

	virtual int currentClass()=0;
public:
	//加密
	static QString encrypt(QString value, QString key);

	//解密
	static QString decrypt(QString value, QString key);

	//随机
	static QString randomNumber(int bit);

	//时间戳
	static QString systemTime_t();


	static void setLabelTextAndTip(QLabel *obj, QString str);
	static void setLabelPicture(QLabel *obj, QByteArray *data);
protected:

	void comboxChangedIndex(QComboBox *combo, QLineEdit *linedit,int index);
	void passwordTextEdit(QCheckBox *checkbox,const QString &);

	QAbstractListModel *loadUserData(QString type);
	QVariantMap readUserData(int index);
	int deleteUserData(int index);
	int insertUserData(QString username, QString password, QString type);

protected:
	QList<QVariantMap> loadDataFromDB(QString type);
	void deleteDataFromDB(QString username, QString type);
	void insertDataToDB(QString username,QString password, QString type);

protected:
	void saveCurrentTabIndex();
signals:
	void saveTabIndex();
};

#endif