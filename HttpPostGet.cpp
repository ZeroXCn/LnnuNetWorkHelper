#include "HttpPostGet.h"

HttpPostGet::HttpPostGet()
{
	m_socket = new QTcpSocket(this);
	QObject::connect(m_socket, SIGNAL(connected()), this, SLOT(onConnectedSlot()));
	QObject::connect(m_socket, SIGNAL(readyRead()), this, SLOT(onReadyReadSlot()));
}

HttpPostGet::~HttpPostGet()
{
	m_socket->deleteLater();
}

HttpPostGet *HttpPostGet::host(QString host, int  port)
{
	m_url = host;
	m_port = port;
	m_header = "";
	m_data = "";

	return this;
}
HttpPostGet *HttpPostGet::head(QString head)
{
	m_header.append(head);
	m_header.append("\r\n");
	return this;
}

HttpPostGet *HttpPostGet::head(QString key, QString value)
{
	m_header.append(key);
	m_header.append(": ");
	m_header.append(value);
	m_header.append("\r\n");

	return this;
}

HttpPostGet *HttpPostGet::data(QString data)
{
	m_data.append(data);
	head("Content-Length", QString("%1").arg(m_data.length()));
	m_header.append("\r\n");
	m_header.append(m_data);

	return this;

}
HttpPostGet *HttpPostGet::connect()
{

	m_socket->connectToHost(m_url, m_port);  //��������
	return this;
}
//����
void HttpPostGet::onConnectedSlot()
{
	
	//head("Host", QString("%1:%2").arg(m_url).arg(m_port));	//�ǳ���Ҫ
	m_header.append("\r\n");	//�ǳ���Ҫ,��Ϊͷ������
	qDebug() << m_header;
	m_socket->write(m_header);  //��������˷�������,httpͷ��
}

//��ȡ
void HttpPostGet::onReadyReadSlot()
{
	QByteArray *content = new QByteArray();
	content->append(m_socket->readAll());	//����һ��ȫ������
	m_socket->disconnectFromHost();
	emit finished(content);
}