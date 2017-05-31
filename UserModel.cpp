#include "UserModel.h"

UserModel::UserModel()
{

}

UserModel::~UserModel()
{
	clear();
	
}

int UserModel::rowCount(const QModelIndex &parent) const
{
	return mUserList.size();
}

QVariant UserModel::data(const QModelIndex& index, int role /* = Qt::DisplayRole */) const
{
	if (!index.isValid())
		return QVariant();

	int s4Row = index.row();
	if (s4Row >= mUserList.size())
		return QVariant();

	if (role == Qt::DisplayRole)
		return (mUserList.at(s4Row))->mUsername;

	return QVariant();
}

void UserModel::addData(User *user)
{
	mUserList.push_back(user);
}
UserModel::User *UserModel::getData(int index)
{
	if (index >= mUserList.size() || index < 0) return NULL;

	return mUserList.at(index);
}


void UserModel::deleteData(int index)
{
	if (index >= mUserList.size() || index < 0) return ;
	delete *(mUserList.begin() + index);
	mUserList.erase(mUserList.begin() + index);
}

QVector<UserModel::User *>::iterator UserModel::getData(QString id)
{
	QVector<User *>::iterator it=NULL;
	for (it = mUserList.begin(); it != mUserList.end();it++)
		if ((*it)->mUsername == id) break;
	return it;
}

UserModel::User *UserModel::getData(QString id, QString type)
{
	QVector<User *>::iterator it = NULL;
	for (it = mUserList.begin(); it != mUserList.end(); it++)
	if ((*it)->mUsername == id && (*it)->mType == type) break;
	if (it != mUserList.end())return *it;
	return NULL;
}

int UserModel::index(QString id, QString type)
{
	int index = 0;
	;
	for (QVector<User *>::iterator it = mUserList.begin(); it != mUserList.end(); it++,index++)
	if ((*it)->mUsername == id && (*it)->mType == type) break;

	if (mUserList.size() <= 0)return -1;
	else return index;
}

void UserModel::clear()
{
	for (int i = 0; i < mUserList.size(); i++)
		delete mUserList.at(i);
	mUserList.clear();
}