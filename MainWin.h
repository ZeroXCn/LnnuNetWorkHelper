#include "ui_mainwin.h"
#include "Keyword.h"
#ifndef MAINWIN_H
#define MAINWIN_H

#include "NetClass.h"

class MainWin : public QDialog
{
	Q_OBJECT

public:
	MainWin(QWidget *parent = 0);
	~MainWin();

private:
	NetClass *m_pIlnClass;
	NetClass *m_pLnnuClass;
	NetClass *m_pCmccClass;
	QWidget *m_pAboutClass;


	Ui::MainWin ui;
public:
	Ui::MainWin *getUi();

private:
	void initWinSize();
	void initDataBase();
	void initConfig();
private slots:
	void tabIndexChangedSlot(int index);
public slots:
	void saveFrameIndexSlot();
};

#endif // LNNUNETWORKHELPER_H
