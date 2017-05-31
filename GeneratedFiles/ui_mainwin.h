/********************************************************************************
** Form generated from reading UI file 'mainwin.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIN_H
#define UI_MAINWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWin
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *logopic;
    QTabWidget *tabWidget;

    void setupUi(QDialog *MainWin)
    {
        if (MainWin->objectName().isEmpty())
            MainWin->setObjectName(QStringLiteral("MainWin"));
        MainWin->resize(352, 269);
        QIcon icon;
        icon.addFile(QStringLiteral(":/LnnuNetworkHelper/Network.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWin->setWindowIcon(icon);
        layoutWidget = new QWidget(MainWin);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 0, 333, 261));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        logopic = new QLabel(layoutWidget);
        logopic->setObjectName(QStringLiteral("logopic"));

        verticalLayout_3->addWidget(logopic);

        tabWidget = new QTabWidget(layoutWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));

        verticalLayout_3->addWidget(tabWidget);


        retranslateUi(MainWin);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWin);
    } // setupUi

    void retranslateUi(QDialog *MainWin)
    {
        MainWin->setWindowTitle(QApplication::translate("MainWin", "\350\276\275\345\270\210\347\275\221\347\273\234\347\231\273\351\231\206\345\212\251\346\211\213", 0));
        logopic->setText(QApplication::translate("MainWin", "<html><head/><body><p><img src=\":/LnnuNetworkHelper/logo.png\"/></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWin: public Ui_MainWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIN_H
