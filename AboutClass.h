#include <QtWidgets/QDialog>
#include "Keyword.h"
#include "JsonHelper.h"
#include "ui_about.h"
#include "HttpOp.h"

#include <QMessageBox>
#ifndef ABOUTCLASS_H
#define ABOUTCLASS_H

class AboutClass : public QWidget
{
	Q_OBJECT
public:
	AboutClass(QWidget *parent = 0);
	~AboutClass();
private:
	Ui::AboutForm ui;

	HttpOp *m_pSoftwareInfo;

	bool isOneInit;
protected:
	void infoparse(QByteArray content);
private slots:
	void replySoftwareInfoSlot(QNetworkReply *reply);

public:
	void currentClass();

};
#endif