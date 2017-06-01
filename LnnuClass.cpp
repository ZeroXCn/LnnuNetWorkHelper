#include "LnnuClass.h"

LnnuClass::LnnuClass(QWidget *parent) :
	NetClass(parent)
{
	ui.setupUi(this);

	init();

}
LnnuClass::~LnnuClass()
{

	m_pCookieJar->deleteLater();
	delete m_pLoginHp;
	delete m_pConnectHp;
	delete m_pVCodeHp;
	delete m_pInfoHp;

	delete m_loginKeyMap;
	delete m_infoResultMap;

}

void LnnuClass::init()
{
	//��������

	m_pCookieJar = new QNetworkCookieJar();
	m_pLoginHp = new HttpOp();
	m_pConnectHp = new HttpOp();
	m_pVCodeHp = new HttpOp();
	m_pInfoHp = new HttpOp();

	m_loginKeyMap = new QVariantMap();
	m_infoResultMap = new QVariantMap();

	//����COOKieJAr
	m_pLoginHp->setCookieJar(m_pCookieJar);
	m_pConnectHp->setCookieJar(m_pCookieJar);
	m_pVCodeHp->setCookieJar(m_pCookieJar);
	m_pInfoHp->setCookieJar(m_pCookieJar);
	
	//���Ӳ�
	connect(m_pLoginHp, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyLoginSlot(QNetworkReply *)));
	connect(m_pVCodeHp, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyVCodeSlot(QNetworkReply *)));
	connect(m_pInfoHp, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyInfoSlot(QNetworkReply *)));
	connect(m_pConnectHp, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyConnectSlot(QNetworkReply *)));

	connect(ui.lnnu_connect_pushbutton, SIGNAL(clicked()), this, SLOT(connectSlot()));

	connect(ui.lnnu_login_pushbutton, SIGNAL(clicked()), this, SLOT(sendLoginInfo()));
	connect(ui.lnnu_logout_pushbutton, SIGNAL(clicked()), this, SLOT(sendLogOutInfo()));
	connect(ui.lnnu_getcode_pushbutton, SIGNAL(clicked()), this, SLOT(sendGetPictureInfo()));
	connect(ui.lnnu_regetinfo_pushButton, SIGNAL(clicked()), this, SLOT(sendGetInfo()));

	connect(ui.lnnu_buypackage_pushButton, SIGNAL(clicked()), this, SLOT(buypackageSlot()));
	connect(ui.lnnu_detail_pushbutton, SIGNAL(clicked()), this, SLOT(detailSlot()));

	connect(ui.lnnu_user_delete_pushButton, SIGNAL(clicked()), this, SLOT(DelUserButtonSlot()));

	connect(ui.lnnu_user_comboBox, SIGNAL(activated(int)), this, SLOT(LnnuComboBoxChangedSlot(int)));
	connect(ui.lnnu_pass_le, SIGNAL(textEdited(const QString &)), this, SLOT(pawEditSlot(const QString &)));

	//��������
	ui.lnnu_user_comboBox->setModel(loadUserData("lnnu"));
	LnnuComboBoxChangedSlot(0);

	//���ÿؼ�����
	ui.lnnu_login_frame->setVisible(true);
	ui.lnnu_info_frame->setVisible(false);

	ui.lnnu_code_le->setEnabled(false);

	//���ÿؼ�λ��
	ui.lnnu_info_frame->setGeometry(ui.lnnu_login_frame->geometry());
}

int LnnuClass::currentClass()
{
	//��ʼ�� 
	setLabelTextAndTip(ui.lnnu_state_label, "");
	ui.lnnu_code_le->setEnabled(false);
	ui.lnnu_login_pushbutton->setEnabled(false);

	//��ȡ��֤��
	//BUG:������TRUE�ж�,�����ʼ��Ĭ��ȫΪFALSE
	if (ui.lnnu_info_frame->isVisible() == false)
		sendGetPictureInfo();

	return 1;
}
//
void LnnuClass::sendLoginInfo()
{
	//�״η���
	m_pLoginHp->setUrlCount(0);
	//ȡ�ÿؼ�����
	QString uesrname = ui.lnnu_user_comboBox->currentText();
	QString password = ui.lnnu_pass_le->text();
	QString code = ui.lnnu_code_le->text();
	QString passmd5 = NetWorkHelper::MD5(password);
	QString checkcode = (*m_loginKeyMap)["checkcode"].toString();
	
	QString postdata = QString("account=%1&password=%2&code=%3&checkcode=%4").arg(uesrname).arg(passmd5).arg(code).arg(checkcode);

	m_pLoginHp->url(Keyword::LNNU_INFO_URL)
		->cookie()
		->data(postdata)
		->mode(HttpOp::POST)->send();
}


void  LnnuClass::sendLogOutInfo()
{
	//ע��
	sendDisConnectInfo();
//	HttpOp::post(Keyword::LNNU_LOGOUT_URL,"");

	//���ص���½����
	ui.lnnu_login_frame->setVisible(true);
	ui.lnnu_info_frame->setVisible(false);

	//���»�ȡ��֤��
	currentClass();
	//sendGetPictureInfo();


	//���ÿؼ�
	setLabelTextAndTip(ui.lnnu_state_label, QStringLiteral("ע���ɹ�"));
	setLogined(false);

}

void LnnuClass::sendGetPictureInfo()
{
	m_pVCodeHp->setUrlCount(0);
	m_pVCodeHp->url(Keyword::LNNU_INFO_INDEX_URL)
		->mode(HttpOp::GET)->send();
}

void LnnuClass::sendGetInfo()
{
	m_pInfoHp->setUrlCount(0);
	//��ȡ��½��Ϣ
	QString url = Keyword::LNNU_INFO_JSON_URL +"0."+randomNumber(18);
		m_pInfoHp->url(url)
		->cookie()
		->mode(HttpOp::GET)->send();


}
void LnnuClass::connectSlot()
{
	QString text = ui.lnnu_connect_pushbutton->text();
	if (text == QStringLiteral("ֱ������")){
		sendConnectInfo();
	}
	else {
		sendDisConnectInfo();
	}
}

void  LnnuClass::sendConnectInfo()
{

	QString uesrname = ui.lnnu_user_comboBox->currentText();
	QString password = ui.lnnu_pass_le->text();
	m_pConnectHp->url(Keyword::LNNU_LOGIN_URL)
		->data("DDDDD=%2C0%2C" + uesrname + "&upass=" + password)
		->mode(HttpOp::POST)->send();
}


void  LnnuClass::sendDisConnectInfo()
{
	//����ע����Ϣ
	m_pConnectHp->url(Keyword::LNNU_LOGOUT_URL)
		->mode(HttpOp::POST)->send();

}

void LnnuClass::buypackageSlot()
{
	LnnuPayPackageClass dialog(this);

	dialog.setCookieJar(m_pCookieJar);

	dialog.exec();
}
void LnnuClass::detailSlot()
{
	//��ȡ��½��Ϣ
	QString url1 = Keyword::LNNU_INFO_JSON_URL + "0." + randomNumber(18);
	QString url2 = Keyword::LNNU_INFO_GET_URL;
	QString data1 = QString(HttpOp::get(url1, m_pInfoHp->getCookiesList()));
	QString data2 = QString(HttpOp::get(url2, m_pInfoHp->getCookiesList()));

	QVariantMap ResultMap1 = JsonHelper::fromJson(data1);
	QVariantMap resultNode = ResultMap1["note"].toMap();
	
	QString monleft = NetWorkHelper::SubString(data2, "id=\"noteLeftFlow\">", "</span>").value(0, "");
	QString orgmonUse = NetWorkHelper::SubString(data2, QRegExp(QStringLiteral("<td>����������MB��</td>([\\s\\S]*)</td>"))).value(0, "");
	QString orgmonTime = NetWorkHelper::SubString(data2, QRegExp(QStringLiteral("<td>����ʱ�������ӣ�</td>([\\s\\S]*)</td>"))).value(0, "");
	QString orgmonFree = NetWorkHelper::SubString(data2, QRegExp(QStringLiteral("<td>ʱ��/�����Ʒѣ�Ԫ��</td>([\\s\\S]*)</td>"))).value(0, "");
	QString orgAddress = NetWorkHelper::SubString(data2, QRegExp(QStringLiteral("<td>��װ��ַ</td>([\\s\\S]*)</td>"))).value(0, "");

	QString monUse = NetWorkHelper::SubString(orgmonUse, QRegExp("(\\d+\\.\\d+)")).value(0, "");
	QString monFree = NetWorkHelper::SubString(orgmonFree, QRegExp("(\\d+\\.\\d+)")).value(0, "");
	QString monTime = NetWorkHelper::SubString(orgmonTime, QRegExp("(\\d+)")).value(1, "");
	QString Address = NetWorkHelper::SubString(orgAddress, QRegExp("(\\d+)")).value(1, "");

	QString message = QStringLiteral("�ʺ�:%1\n��������:%2 MB(ʣ%3 MB)\n����ʱ��(����):%4\n�����Ʒ�:%5\nʣ����:%6(��%7 MB)\n�����豸:%8\n��������:%9\n��װ��ַ:%10\n��ǰ״̬:%11")
		.arg(resultNode["welcome"].toString())
		.arg(monUse).arg(monleft)
		.arg(monTime)
		.arg(monFree)
		.arg(resultNode["leftmoeny"].toString()).arg(resultNode["leftFlow"].toString())
		.arg(resultNode["onlinestate"].toString())
		.arg(NetWorkHelper::SubString(resultNode["overdate"].toString(), QRegExp("(\\d*)-(\\d*)-(\\d*)")).value(0, ""))
		.arg(Address)
		.arg(resultNode["status"].toString());
	QMessageBox::information(this, Keyword::LNH_NAME, message);
}
//////////////////////////
void LnnuClass::delUser()
{
	QString uesrname = ui.lnnu_user_comboBox->currentText();
	QString type = "lnnu";
	int currentId = ui.lnnu_user_comboBox->currentIndex();
	int haveId = ui.lnnu_user_comboBox->count();
	if (currentId == -1){
		LnnuComboBoxChangedSlot(-1); 
		return; 
	}

	//�����ݿ���ɾ��������MOdel
	deleteUserData(currentId);
	
	LnnuComboBoxChangedSlot(haveId - 1);
}

void LnnuClass::alterUser()
{
	QString uesrname = ui.lnnu_user_comboBox->currentText();
	QString password = ui.lnnu_pass_le->text();
	QString type = "lnnu";

	if (!ui.lnnu_keepinmine_checkBox->isChecked())password = "";

	//���ݱ���
	int index = insertUserData(uesrname, password, type);

	LnnuComboBoxChangedSlot(index);

}


////////////////////////////
void LnnuClass::replyConnectSlot(QNetworkReply *reply)
{
	//������Ҫ�ж�--��������Ϣ
	QVariant replycode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
	if (302 == replycode.toInt())
	{
		//��ҳ�ض���
		QVariant redirectionUrl = reply->attribute(QNetworkRequest::RedirectionTargetAttribute);

		m_pConnectHp->url(redirectionUrl.toString())
					->mode(HttpOp::GET)->send();
	}
	else if (200 == replycode.toInt()){
		//��ȡ�����Ϣ
		QString content = QString::fromLocal8Bit(reply->readAll());
		QStringList list = NetWorkHelper::SubString(content, QRegExp("newComm\\.setNessArg\\('"), QRegExp("'\\);"));
		QString pageType = list[1];

		if (pageType == "pc_3"){
			//��������-���û��ѡ,��ֻ�����ʺ�
			alterUser();
			setLogined(true);

			setLabelTextAndTip(ui.lnnu_state_label, QStringLiteral("��½�ɹ�"));
			ui.lnnu_connect_pushbutton->setText(QStringLiteral("ֱ��ע��"));

		}
		else{
			QString urlStr = reply->url().toString();
			int stateCode = NetWorkHelper::SubString(urlStr, QRegExp("ACLogOut="), QRegExp("(&|$)"))[0].toInt();
			if (stateCode == 1){	//ע���ɹ�
				setLabelTextAndTip(ui.lnnu_state_label, QStringLiteral("ע���ɹ�"));
				ui.lnnu_connect_pushbutton->setText(QStringLiteral("ֱ������"));
			}
			else if (stateCode == 6){
				setLabelTextAndTip(ui.lnnu_state_label, QStringLiteral("�û������������"));
			}
			//else if (stateCode == 7){
			//	//��ȡѧ����Ϣ
			//	ui.iliaoningtab->setEnabled(false);

			//	ui.lnnu_login_frame->setVisible(false);
			//	ui.lnnu_info_frame->setVisible(true);
			//}
			//��������7,����Ѿ���������Ȼ�ᴥ������7(��������Դ�)

			else setLabelTextAndTip(ui.lnnu_state_label,QStringLiteral("��½�쳣"));

		}
	}
	reply->deleteLater();
}

void LnnuClass::replyVCodeSlot(QNetworkReply *reply)
{
	int nCount = m_pVCodeHp->getUrlCount();
	QVariant replycode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
	if (replycode != 200 ){
		if (replycode  == 0)
			setLabelTextAndTip(ui.lnnu_state_label, QStringLiteral("�����쳣!"));
		else
			setLabelTextAndTip(ui.lnnu_state_label, QStringLiteral("��Ϣ��ȡʧ��,�������л�ѡ�."));
		reply->deleteLater();
		return;
	}

	if (nCount == 1){
		//ȡ��Code,����ǳ���Ҫ,������ܵ�½����
		QString url = Keyword::LNNU_INFO_RANDOM_URL + "0." + randomNumber(16);
		m_pVCodeHp->url(url)
			->mode(HttpOp::GET)->send();

	}
	else if (nCount == 2){
		QByteArray pic = reply->readAll();

		ui.lnnu_code_pic->clear();
		NetWorkHelper::setLabelPicture(ui.lnnu_code_pic, &pic);

		m_pVCodeHp->url(Keyword::LNNU_INFO_INDEX_URL)
			->mode(HttpOp::GET)->send();

	}
	else if (nCount == 3){
		//ȡ����ҳ����
		QString pageContent = reply->readAll();

		QString refereurl = m_pVCodeHp->getRequest()->url().toString();
		QString checkcode = NetWorkHelper::SubString(pageContent, "checkcode=\"", "\";").value(0, "");

		(*m_loginKeyMap)["checkcode"] = checkcode;

		ui.lnnu_login_pushbutton->setEnabled(true);
		
	}
	reply->deleteLater();
}
void LnnuClass::replyLoginSlot(QNetworkReply *reply)
{
	int nCount = m_pLoginHp->getUrlCount();
	if (nCount == 1){
		//�����￪ʼ���ֵ�����ʧ�ܻ��ǳɹ�
		QString pageContent = reply->readAll();
		if (pageContent.isEmpty()){
			setLabelTextAndTip(ui.lnnu_state_label,QStringLiteral("�����쳣!"));
			return;//����
		}
		//ȡ��ҳ�淴�����
		QStringList keyContent = NetWorkHelper::SubString(pageContent, QRegExp("<div id=\"fielderror2\"(.*)>"), QRegExp("</div>"));
		if (keyContent.isEmpty()) //��ʾ�ɹ�
		{
			//��������-���û��ѡ,��ֻ�����ʺ�
			alterUser();
			setLogined(true);

			//���ӻ�����--����ɹ�����Ͳ���Ҫ��ô�ಽ��
			//sendConnectInfo();
			QString uesrname = ui.lnnu_user_comboBox->currentText();
			QString password = ui.lnnu_pass_le->text();
			HttpOp::post(Keyword::LNNU_LOGIN_URL, QString("DDDDD=%2C0%2C" + uesrname + "&upass=" + password));
				

			//��ȡ��Ϣ
			sendGetInfo();

			//���ÿؼ�
			setLabelTextAndTip(ui.lnnu_state_label,QStringLiteral("��½�ɹ�"));

		}
		else{
			int maxtry = NetWorkHelper::SubString(pageContent, "(trytimes)>=", ")").value(0,"6").toInt();
			QString message = NetWorkHelper::SubString(keyContent.value(0,""), "nbsp;", "&lt;").value(0, QStringLiteral("��½�쳣"));

			if (message.indexOf(QStringLiteral("���벻��ȷ")) != -1){
				QStringList number = NetWorkHelper::SubString(message, QRegExp("(\\d+)"));
				QString str = QString(QStringLiteral("���벻��ȷ:%1/%2")).arg(number[0]).arg(number[1]);

				if (number[0].toInt() >= maxtry+1){
					ui.lnnu_code_le->setEnabled(true);
				}

				setLabelTextAndTip(ui.lnnu_state_label,str);

			}
			else if (message.indexOf(QStringLiteral("��֤�����")) != -1){
				ui.lnnu_code_le->setEnabled(true);
				setLabelTextAndTip(ui.lnnu_state_label,message);
			}
			else
				setLabelTextAndTip(ui.lnnu_state_label,message);

			//���»�ȡ��֤��
			sendGetPictureInfo();
		}
	
	}
	

	reply->deleteLater();
}

void LnnuClass::replyInfoSlot(QNetworkReply *reply)
{
	int nCount = m_pInfoHp->getUrlCount();
	if (nCount == 1)
	{
		QString jsoncontent = reply->readAll();

		*m_infoResultMap = JsonHelper::fromJson(jsoncontent);

		//��ȡ�û���Ϣ
		m_pInfoHp->url(Keyword::LNNU_INFO_GET_URL)
			->cookie()
			->mode(HttpOp::GET)->send();
	}
	else if (nCount == 2){

		QString pageContent = reply->readAll();
		QString monleft = NetWorkHelper::SubString(pageContent, "id=\"noteLeftFlow\">", "</span>").value(0, "");
		QString orgmonUse = NetWorkHelper::SubString(pageContent, QRegExp(QStringLiteral("<td>����������MB��</td>([\\s\\S]*)</td>"))).value(0, "");
		QString monUse = NetWorkHelper::SubString(orgmonUse, QRegExp("(\\d+\\.\\d+)")).value(0, "");
		
		QVariantMap resultNode = (*m_infoResultMap)["note"].toMap();
		ui.lnnu_uerename_label->setText(resultNode["welcome"].toString());
		ui.lnnu_userrest_label->setText(QString(QStringLiteral("%1 MB(ʣ%2 MB)")).arg(monUse).arg(monleft));
		ui.lnnu_restmoney_label->setText(QString(QStringLiteral("%1(��%2 MB)")).arg(resultNode["leftmoeny"].toString()).arg(resultNode["leftFlow"].toString()));
		ui.lnnu_onlinenumber_label->setText(resultNode["onlinestate"].toString());
		ui.lnnu_deadline_label->setText(NetWorkHelper::SubString(resultNode["overdate"].toString(), QRegExp("(\\d*)-(\\d*)-(\\d*)")).value(0, ""));
		ui.lnnu_nowstate_label->setText(resultNode["status"].toString());

		//��Ϣ�Ʒ�ת
		ui.lnnu_login_frame->setVisible(false);
		ui.lnnu_info_frame->setVisible(true);
	}
	reply->deleteLater();

}

void LnnuClass::LnnuComboBoxChangedSlot(int index)
{
	if (index < 0){
		ui.lnnu_user_comboBox->setCurrentText("");
		ui.lnnu_pass_le->setText("");
		ui.lnnu_keepinmine_checkBox->setChecked(false);
		return;
	}

	QVariantMap user = readUserData(index);
	ui.lnnu_user_comboBox->setCurrentText(user.value("username","").toString());
	ui.lnnu_pass_le->setText(user.value("password", "").toString());

	ui.lnnu_keepinmine_checkBox->setChecked(!ui.lnnu_pass_le->text().isEmpty());

}

void LnnuClass::pawEditSlot(const QString &text)
{
	passwordTextEdit(ui.lnnu_keepinmine_checkBox, text);
}

void LnnuClass::DelUserButtonSlot()
{
	delUser();
}


LnnuPayPackageClass::LnnuPayPackageClass(QWidget *parent) :
	QDialog(parent)
{
	ui.setupUi(this);
	m_pCookieJar = NULL;

	connect(ui.buyButton, SIGNAL(clicked()), this, SLOT(postPayActionSlot()));

	//�����Ի����С
	setFixedSize(width(), height());
}
LnnuPayPackageClass::~LnnuPayPackageClass()
{

}

void LnnuPayPackageClass::setCookieJar(QNetworkCookieJar *jar)
{
	m_pCookieJar = jar;
}

void LnnuPayPackageClass::postPayActionSlot()
{
	QByteArray data;
	if (ui.radioButton->isChecked())
		data = "hidpckselect=207&pckid=207";
	else 
		data = "hidpckselect=208&pckid=208";

	QNetworkReply *reply=HttpOp::post(Keyword::LNNU_PAY_SAVEPACKAGE_URL, m_pCookieJar, data);
	QString replyContent = reply->readAll();

	if (!replyContent.isEmpty())
	{
		QString result = NetWorkHelper::SubString(replyContent, QStringLiteral("<strong>��ʾ��</strong>����״̬��"), "\r\n").value(0, QStringLiteral("Ҳ��ɹ���,ֻ�ǳ���û������"));

		QMessageBox::information(this, Keyword::LNH_NAME, result);

		//���¸���������
		((LnnuClass *)this->parent())->sendGetInfo();
	}else
		QMessageBox::information(this, Keyword::LNH_NAME, QStringLiteral("�����쳣,������"));

	reply->deleteLater();
}