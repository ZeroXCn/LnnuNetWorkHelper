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

	m_socket->connectToHost(m_url, m_port);  //连接主机
	return this;
}
//发送
void HttpPostGet::onConnectedSlot()
{
	
	//head("Host", QString("%1:%2").arg(m_url).arg(m_port));	//非常重要
	m_header.append("\r\n");	//非常重要,作为头部结束
	qDebug() << m_header;
	m_socket->write(m_header);  //向服务器端发送数据,http头部
}

//读取
void HttpPostGet::onReadyReadSlot()
{
	QByteArray *content = new QByteArray();
	content->append(m_socket->readAll());	//不能一次全部读完
	m_socket->disconnectFromHost();
	emit finished(content);
}