#include "mainwin.h"

#include "IlnClass.h"
#include "LnnuClass.h"
#include "CmccClass.h"
#include "AboutClass.h" 


MainWin::MainWin(QWidget *parent)
	: QDialog(parent)
{

	m_pIlnClass = new IlnClass();
	m_pLnnuClass = new LnnuClass();
	m_pCmccClass = new CmccClass();
	m_pAboutClass = new AboutClass();

	//��Ӵ���
	ui.setupUi(this);
	ui.tabWidget->insertTab(0, m_pLnnuClass, QStringLiteral("LNNU-CMCC"));
	ui.tabWidget->insertTab(1, m_pIlnClass, QStringLiteral("i-LiaoNing"));
	ui.tabWidget->insertTab(2, m_pCmccClass, QStringLiteral("CMCC-WEB"));
	ui.tabWidget->insertTab(3, m_pAboutClass, QStringLiteral("����"));


	connect(m_pIlnClass, SIGNAL(saveTabIndex()), this, SLOT(saveFrameIndexSlot()));
	connect(m_pLnnuClass, SIGNAL(saveTabIndex()), this, SLOT(saveFrameIndexSlot()));
	connect(m_pCmccClass, SIGNAL(saveTabIndex()), this, SLOT(saveFrameIndexSlot()));

	if(!SQLiteDB::isFileExist(Keyword::DATABASE_PATH))
		initDataBase();

	//////////////////
	//����������Ϣ
	initConfig();

	//���ڵ���
	initWinSize();

	//�ؼ�����
	int latelyTab = Keyword::CONFIGMAP.value("latelyTab",0).toInt();
	ui.tabWidget->setCurrentIndex(latelyTab);
	tabIndexChangedSlot(latelyTab);

	//�����������ڸ���
	//�ۺ���������������-��Ȼ���������Դ���ɶ��δ���
	connect(ui.tabWidget, SIGNAL(currentChanged(int)), this, SLOT(tabIndexChangedSlot(int)));

}

MainWin::~MainWin()
{
	//����ź�,��Ȼ�����
	disconnect(ui.tabWidget, SIGNAL(currentChanged(int)), this, SLOT(tabIndexChangedSlot(int)));
	
	delete m_pIlnClass;
	delete m_pLnnuClass;
	delete m_pCmccClass;
	delete m_pAboutClass;

}

//////////////////////////////////////////////////////////////////////////////////////////
void MainWin::initWinSize()
{


	//WIN10���ڿؼ���С������
	//�߷ֱ���DPI���ó���100%�ͻ�������,��QT����,��ϵͳ�޹�
	{
		//�̶������С
		setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
		setFixedSize(width(), height());
	}
	//setLayout(ui.verticalLayout_3);

}
void MainWin::initDataBase()
{
	SQLiteDB database(Keyword::DATABASE_PATH);
	if (database.open()){
		
		database.exec(
			"CREATE TABLE user( \n"
			"username STRING NOT NULL, \n"
			"password STRING, \n"
			"type     STRING NOT NULL, \n"
			"lately   TIME   NOT NULL \n"
			"DEFAULT(datetime(CURRENT_TIMESTAMP, 'localtime')), \n"
			"date     TIME   DEFAULT(datetime(CURRENT_TIMESTAMP, 'localtime')) \n"
			"NOT NULL, \n"
			"PRIMARY KEY (username,type) \n"
			"); "

			);
		
		database.exec(
			"CREATE TABLE config( \n"
			"keyword STRING NOT NULL \n"
			"PRIMARY KEY, \n"
			"value   STRING \n"
			");"
	
			);	
		database.exec("REPLACE INTO config(keyword,value) VALUES('latelyTab','0');");
		database.exec("REPLACE INTO config(keyword,value) VALUES('getNews','1');");
	}
	database.close();
}


void MainWin::initConfig()
{
	//�����ʼ����Ϣ����
	SQLiteDB userdb(Keyword::DATABASE_PATH);
	SQLiteDB::SqlQuery sqlquery = userdb.exec(QString("select * from %1").arg(Keyword::DATABASE_CONFIG_TABLE));
	while (sqlquery.next())
	{
		QString keyword = sqlquery.value("keyword").toString();
		QString value = sqlquery.value("value").toString();
		Keyword::CONFIGMAP[keyword] = value;
	}
	userdb.close();
}

Ui::MainWin *MainWin::getUi()
{
	return &ui;
}

void MainWin::tabIndexChangedSlot(int index)
{
	//Ӧ�ø��ݵ�ǰtabName���ñȽϺ�
	switch (index)
	{
	case 0:
		((LnnuClass *)m_pLnnuClass)->currentClass();
		break;
	case 1:
		((IlnClass *)m_pIlnClass)->currentClass();
		break;
	case 2:
		((CmccClass *)m_pCmccClass)->currentClass();
		break;
	case 3:
		((AboutClass *)m_pAboutClass)->currentClass();
		break;
	default:break;
	}
}


void MainWin::saveFrameIndexSlot()
{
	int index = ui.tabWidget->currentIndex();
	SQLiteDB userdb(Keyword::DATABASE_PATH);
	userdb.exec(QString("REPLACE INTO %1(keyword,value) VALUES('%2','%3');").arg(Keyword::DATABASE_CONFIG_TABLE).arg("latelyTab").arg(index));
	userdb.close();
}