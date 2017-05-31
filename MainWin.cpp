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

	//添加窗体
	ui.setupUi(this);
	ui.tabWidget->insertTab(0, m_pLnnuClass, QStringLiteral("LNNU-CMCC"));
	ui.tabWidget->insertTab(1, m_pIlnClass, QStringLiteral("i-LiaoNing"));
	ui.tabWidget->insertTab(2, m_pCmccClass, QStringLiteral("CMCC-WEB"));
	ui.tabWidget->insertTab(3, m_pAboutClass, QStringLiteral("关于"));


	connect(m_pIlnClass, SIGNAL(saveTabIndex()), this, SLOT(saveFrameIndexSlot()));
	connect(m_pLnnuClass, SIGNAL(saveTabIndex()), this, SLOT(saveFrameIndexSlot()));
	connect(m_pCmccClass, SIGNAL(saveTabIndex()), this, SLOT(saveFrameIndexSlot()));

	if(!SQLiteDB::isFileExist(Keyword::DATABASE_PATH))
		initDataBase();

	//////////////////
	//加载配置信息
	initConfig();

	//窗口调整
	initWinSize();

	//控件设置
	int latelyTab = Keyword::CONFIGMAP.value("latelyTab",0).toInt();
	ui.tabWidget->setCurrentIndex(latelyTab);
	tabIndexChangedSlot(latelyTab);

	//创建对象用于更新
	//槽函数放在这里连接-不然上面的语句会对此造成二次触发
	connect(ui.tabWidget, SIGNAL(currentChanged(int)), this, SLOT(tabIndexChangedSlot(int)));

}

MainWin::~MainWin()
{
	//解除信号,不然会出错
	disconnect(ui.tabWidget, SIGNAL(currentChanged(int)), this, SLOT(tabIndexChangedSlot(int)));
	
	delete m_pIlnClass;
	delete m_pLnnuClass;
	delete m_pCmccClass;
	delete m_pAboutClass;

}

//////////////////////////////////////////////////////////////////////////////////////////
void MainWin::initWinSize()
{


	//WIN10窗口控件大小有问题
	//高分辨率DPI设置超过100%就会有问题,非QT问题,与系统无关
	{
		//固定窗体大小
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
	//程序初始化信息加载
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
	//应该根据当前tabName设置比较好
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