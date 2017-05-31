/********************************************************************************
** Form generated from reading UI file 'lnnupaypackage.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LNNUPAYPACKAGE_H
#define UI_LNNUPAYPACKAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PayPackageDialog
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QPushButton *buyButton;
    QSpacerItem *horizontalSpacer;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *PayPackageDialog)
    {
        if (PayPackageDialog->objectName().isEmpty())
            PayPackageDialog->setObjectName(QStringLiteral("PayPackageDialog"));
        PayPackageDialog->resize(201, 109);
        QIcon icon;
        icon.addFile(QStringLiteral(":/LnnuNetworkHelper/Network.ico"), QSize(), QIcon::Normal, QIcon::Off);
        PayPackageDialog->setWindowIcon(icon);
        layoutWidget = new QWidget(PayPackageDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 158, 69));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        radioButton = new QRadioButton(layoutWidget);
        buttonGroup = new QButtonGroup(PayPackageDialog);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(radioButton);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setChecked(true);

        gridLayout->addWidget(radioButton, 0, 0, 1, 2);

        radioButton_2 = new QRadioButton(layoutWidget);
        buttonGroup->addButton(radioButton_2);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        gridLayout->addWidget(radioButton_2, 1, 0, 1, 2);

        buyButton = new QPushButton(layoutWidget);
        buyButton->setObjectName(QStringLiteral("buyButton"));

        gridLayout->addWidget(buyButton, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);


        retranslateUi(PayPackageDialog);

        QMetaObject::connectSlotsByName(PayPackageDialog);
    } // setupUi

    void retranslateUi(QDialog *PayPackageDialog)
    {
        PayPackageDialog->setWindowTitle(QApplication::translate("PayPackageDialog", "\346\227\266\351\225\277\345\214\205\346\215\242\350\264\255", 0));
        radioButton->setText(QApplication::translate("PayPackageDialog", "1\345\205\203\345\214\205200MB", 0));
        radioButton_2->setText(QApplication::translate("PayPackageDialog", "5\345\205\203\345\214\2051000MB", 0));
        buyButton->setText(QApplication::translate("PayPackageDialog", "\350\264\255\344\271\260", 0));
    } // retranslateUi

};

namespace Ui {
    class PayPackageDialog: public Ui_PayPackageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LNNUPAYPACKAGE_H
