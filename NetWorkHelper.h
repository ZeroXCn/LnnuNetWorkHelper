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
	//�ж�IP��ַ���˿��Ƿ�����
	static bool IPLive(QString ip, int port, int timeout);
	//�ж��Ƿ�ͨ����
	static bool IsWebOk();

	//��MD5
	static QString MD5(QString);

	//�ַ�����ȡ
	static QStringList SubString(QString org, QRegExp left, QRegExp right, bool leftminimal = false, bool rightminimal = false);
	static QStringList SubString(QString org, QString left, QString right);
	static QStringList SubString(QString org, QRegExp rx,bool minimal=false);
	//����(�첽)
	static int Sleep(int time);

	//����PIC
	static void setLabelPicture(QLabel *obj, QByteArray *data);
};

#endif