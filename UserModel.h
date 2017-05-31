#include <QAbstractListModel>
#include <QDateTime>
#include <QVector>

#ifndef USERMODEL_H
#define USERMODEL_H

class UserModel :public QAbstractListModel
{
public:
	class User{
	public:
		QString mUsername;
		QString mPassword;
		QString mType;
		QDateTime mLately;
	};
private:
	QVector<User *> mUserList;
public:
	UserModel();
	~UserModel();

	int rowCount(const QModelIndex &parent) const;
	QVariant data(const QModelIndex &index, int role) const;

public:
	void addData(User *user);
	User *getData(int index);
	QVector<User *>::iterator getData(QString id);
	User *getData(QString id, QString type);
	int index(QString id, QString type);
	void deleteData(int index);

	void clear();
};

#endif