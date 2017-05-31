#include <QTcpSocket>
#include <QUrl>
class HttpPostGet : public QObject{
	Q_OBJECT
private:
	QTcpSocket *m_socket;
	QString m_url; int m_port;
	QByteArray m_header;
	QByteArray m_data;
protected slots:
	void onConnectedSlot(); //∑¢ÀÕ
	void onReadyReadSlot();  //∂¡»°

signals:
	void finished(QByteArray *content);
public:
	HttpPostGet();
	~HttpPostGet();

	HttpPostGet *host(QString host, int  port);
	HttpPostGet *head(QString head);
	HttpPostGet *head(QString key,QString value);
	HttpPostGet *data(QString data);
	HttpPostGet *connect();
};