#include <QAbstractListModel>
#include <QDateTime>
#include <QVector>

#ifndef CARDMODEL_H
#define CARDMODEL_H

class CardModel :public QAbstractListModel
{
public:
	class Card{
	public:
		QString offerName;
		QString effTime;
		QString expTime;
		QString price;
		QString offerHour;
		QString accuTime;
		QString freeTime;
		QString leftPercent;
		QString productID;
	};
private:
	QVector<Card *> mCardList;
public:
	CardModel();
	~CardModel();

	int rowCount(const QModelIndex &parent) const;
	QVariant data(const QModelIndex &index, int role) const;

public:
	void addData(Card *user);
	Card *getData(int index);
	void deleteData(int index);

	void clear();
};

#endif