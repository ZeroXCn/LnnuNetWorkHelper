#include "SQLiteDB.h"
bool SQLiteDB::isFileExist(QString path)
{
	QFile dbFile(path);
	bool exist = dbFile.exists();
	dbFile.close();
	return exist;
}
void SQLiteDB::createFile(QString path)
{
	QFile dbFile(path);
	dbFile.open(QIODevice::Append);//WriteOnly
	dbFile.close();
}

SQLiteDB::SQLiteDB(QString dbpath)
{
	//������ݿ��������������ݿ����ơ����ݿ��¼�û���������
	pDatabase = new QSqlDatabase();
	if (QSqlDatabase::contains("qt_sql_default_connection"))
		*pDatabase = QSqlDatabase::database("qt_sql_default_connection");
	else
		*pDatabase = QSqlDatabase::addDatabase("QSQLITE");
	pDatabase->setDatabaseName(dbpath);
	m_dpPath = dbpath;

	if (isFileExist(dbpath)) pDatabase->open();
}
SQLiteDB::SQLiteDB(QString dbpath, QString dbname, QString dbpsw)
{
	//������ݿ��������������ݿ����ơ����ݿ��¼�û���������
	pDatabase = new QSqlDatabase();
	if (QSqlDatabase::contains("qt_sql_default_connection"))
		*pDatabase = QSqlDatabase::database("qt_sql_default_connection");
	else
		*pDatabase = QSqlDatabase::addDatabase("QSQLITE");
	pDatabase->setDatabaseName(dbpath);
	pDatabase->setUserName(dbname);
	pDatabase->setPassword(dbpsw);
	m_dpPath = dbpath;
}

SQLiteDB::~SQLiteDB()
{
	close();
	delete pDatabase;
}

bool SQLiteDB::isTableExist(QString tablename)
{
	QSqlQuery query;
	bool isTableExist = query.exec(QString("select count(*) from %1").arg(tablename));
	if (!isTableExist){
		return false;
	}
	else{
		return true;
	}
}


bool SQLiteDB::isOpen()
{
	return pDatabase->isOpen();
}
bool SQLiteDB::open()
{
	//���Open���Զ������ļ�
	return pDatabase->open();
}


void SQLiteDB::close()
{
	pDatabase->close();
}


SQLiteDB::SqlQuery SQLiteDB::exec(QString sql)
{
	SqlQuery query;
	query.exec(sql);
	return query;
}