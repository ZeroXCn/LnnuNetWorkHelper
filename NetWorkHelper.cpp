#include "NetWorkHelper.h"


//�ж�IP��ַ���˿��Ƿ�����
bool NetWorkHelper::IPLive(QString ip, int port, int timeout = 1000) {
	QTcpSocket tcpClient;
	tcpClient.abort();
	tcpClient.connectToHost(ip, port);
	//100����û�����������жϲ�����
	return tcpClient.waitForConnected(timeout);
}
//�ж��Ƿ�ͨ����
bool NetWorkHelper::IsWebOk() {
	//�ܽ�ͨ�ٶ�IP˵������ͨ����
	return IPLive("115.239.211.112", 80);
}


QString NetWorkHelper::MD5(QString str)
{
	QByteArray md5str = QCryptographicHash::hash(str.toLatin1(), QCryptographicHash::Md5);
	return QString(md5str.toHex());
}

QStringList NetWorkHelper::SubString(QString org, QRegExp left, QRegExp right, bool leftminimal , bool rightminimal)
{
	QStringList list;
	left.setMinimal(leftminimal); right.setMinimal(rightminimal);//�Ƿ��̰��ƥ��

	int leftpos = 0, rightpos = 0;
	while (1)
	{
		leftpos = org.indexOf(left, leftpos);
		if (leftpos != -1)
		{
			rightpos = org.indexOf(right, leftpos + left.matchedLength());
			if (rightpos != -1){
				list << org.mid(leftpos + left.matchedLength(), rightpos - leftpos - left.matchedLength());
				leftpos = rightpos + right.matchedLength();
			}
			else break;
		}
		else break;
	}
	return list;
}

QStringList NetWorkHelper::SubString(QString org, QString left, QString right)
{
	QStringList list;
	int leftpos = 0, rightpos = 0;
	while (1)
	{
		if (left.isEmpty())
			leftpos = leftpos;
		else
			leftpos = org.indexOf(left, leftpos);

		if (leftpos != -1)
		{
			if (right.isEmpty())
				rightpos = org.size();
			else
				rightpos = org.indexOf(right, leftpos + left.size());
			
			if (rightpos != -1){
				list << org.mid(leftpos + left.size(), rightpos - leftpos - left.size());
				leftpos = rightpos + right.size();
			}
			else break;
		}
		else break;
	}
	return list;
}

QStringList NetWorkHelper::SubString(QString org, QRegExp rx, bool minimal)
{
	rx.setMinimal(minimal);
	QStringList list; int pos = 0;
	while ((pos = rx.indexIn(org, pos)) != -1) {
		list << rx.cap(0);
		pos += rx.matchedLength();
	}

	return list;
}


int NetWorkHelper::Sleep(int time)
{
	QEventLoop eventloop;
	QTimer::singleShot(time, &eventloop, SLOT(quit()));
	eventloop.exec();

	return 1;
}

void NetWorkHelper::setLabelPicture(QLabel *obj, QByteArray *data)
{
	QPixmap imageresult;//
	imageresult.loadFromData(*data);
	obj->clear();//���
	obj->setPixmap(imageresult);//���ص�Label��ǩ
	obj->show();//��ʾ
}