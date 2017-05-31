#include <QString>
#include <QTcpSocket>
#include <QCryptographicHash>
#include <QEventLoop>
#include <QTimer>
#include <QLabel>

#ifndef NETWORKHELPER_H
#define NETWORKHELPER_H

class NetWorkHelper{
public:
	//判断IP地址及端口是否在线
	static bool IPLive(QString ip, int port, int timeout);
	//判断是否通外网
	static bool IsWebOk();

	//求MD5
	static QString MD5(QString);

	//字符串截取
	static QStringList SubString(QString org, QRegExp left, QRegExp right, bool leftminimal = false, bool rightminimal = false);
	static QStringList SubString(QString org, QString left, QString right);
	static QStringList SubString(QString org, QRegExp rx,bool minimal=false);
	//休眠(异步)
	static int Sleep(int time);

	//设置PIC
	static void setLabelPicture(QLabel *obj, QByteArray *data);
};

#endif