#include "aboutclass.h"

AboutClass::AboutClass(QWidget *parent): 
QWidget(parent)
{
	//添加窗体
	ui.setupUi(this);
	//初始化内容
	ui.body_label->setText(ui.body_label->text().arg(Keyword::LNH_NAME).arg(Keyword::LNH_VERSION_STR).arg(Keyword::LNH_LASTTIME_STR));
	//创建对象用于更新
	m_pSoftwareInfo = new HttpOp();
	connect(m_pSoftwareInfo, SIGNAL(finished(QNetworkReply *)), this, SLOT(replySoftwareInfoSlot(QNetworkReply *)));

	isOneInit = true;
}
AboutClass::~AboutClass()
{
	delete m_pSoftwareInfo;
}

void AboutClass::currentClass()
{
	if (isOneInit){
		int getNews = Keyword::CONFIGMAP.value("getNews", 1).toInt();
		if (getNews == 1){
			m_pSoftwareInfo->url(Keyword::LNH_GETINFO_URL)
				->mode(HttpOp::POST)->send();
		}
		isOneInit = false;
	}
	
}

void AboutClass::replySoftwareInfoSlot(QNetworkReply *reply)
{
	QVariant replycode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
	if (replycode.toInt() == 200)
	{
		QByteArray content = reply->readAll();
		if (!content.isEmpty())
		{
			infoparse(content);
		}
	}
	reply->deleteLater();
}

void AboutClass::infoparse(QByteArray content)
{
	QString  pageContent = QString(content);
	QVariantMap infomap = JsonHelper::fromJson(pageContent);

	QString code = infomap["RequestCode"].toString();
	if (code == "1")
	{
		QString requestBody = infomap["RequestBody"].toString();
		if (!requestBody.isEmpty())
			ui.body_label->setText(requestBody);

		QStringList messages = infomap["Messages"].toStringList();
		for (int i = 0; i < messages.size(); i++)
			QMessageBox::information(this, Keyword::LNH_NAME, messages[i]);

		QString newVersionStr = infomap["NewVersionStr"].toString();
		QString downloadStr = infomap["DownLoad"].toString();
		float newVersionNum = infomap["NewVersionNum"].toFloat();
		if (Keyword::LNH_VERSION_NUM < newVersionNum)
			QMessageBox::information(this, Keyword::LNH_NAME, QString(QStringLiteral("发现新版本\n当前版本:%1\n最新版本:%2\n下载地址:%3")).arg(Keyword::LNH_VERSION_STR).arg(newVersionStr).arg(downloadStr));

	}
}
