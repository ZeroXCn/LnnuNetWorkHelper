#include "CardModel.h"

CardModel::CardModel()
{

}

CardModel::~CardModel()
{
	clear();

}

int CardModel::rowCount(const QModelIndex &parent) const
{
	return mCardList.size();
}

QVariant CardModel::data(const QModelIndex& index, int role /* = Qt::DisplayRole */) const
{
	if (!index.isValid())
		return QVariant();

	int s4Row = index.row();
	if (s4Row >= mCardList.size())
		return QVariant();

	if (role == Qt::DisplayRole)
		return (mCardList.at(s4Row))->offerName;

	return QVariant();
}

void CardModel::addData(Card *card)
{
	mCardList.push_back(card);
}
CardModel::Card *CardModel::getData(int index)
{
	if (index >= mCardList.size() || index < 0) return NULL;

	return mCardList.at(index);
}


void CardModel::deleteData(int index)
{
	if (index >= mCardList.size() || index < 0) return;
	delete *(mCardList.begin() + index);
	mCardList.erase(mCardList.begin() + index);
}

void CardModel::clear()
{
	for (int i = 0; i < mCardList.size(); i++)
		delete mCardList.at(i);
	mCardList.clear();
}