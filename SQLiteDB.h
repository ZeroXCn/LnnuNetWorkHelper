#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
#include <QString>

#ifndef SQLITEDB_H
#define SQLITEDB_H

class SQLiteDB{
private:
	QSqlDatabase *pDatabase;
	QString m_dpPath;
public:
	class SqlQuery :public QSqlQuery
	{

	};
public:
	static bool isFileExist(QString path);
	static void createFile(QString path);
public:
	SQLiteDB(QString dbpath);
	SQLiteDB(QString dbpath, QString dbname, QString dbpsw);

	~SQLiteDB();
public:

	bool isTableExist(QString tablename);

	bool isOpen();

	bool open();
	void close();
public:
	SqlQuery exec(QString sql);


};

#endif