/********************************************************************************
** Form generated from reading UI file 'ilncard.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ILNCARD_H
#define UI_ILNCARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IlnCardForm
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *iln_card_number_le;
    QLabel *label_2;
    QLineEdit *iln_card_vcode_le;
    QLabel *iln_card_picture;
    QPushButton *iln_card_reget_button;
    QSpacerItem *horizontalSpacer;
    QPushButton *iln_card_active_button;

    void setupUi(QWidget *IlnCardForm)
    {
        if (IlnCardForm->objectName().isEmpty())
            IlnCardForm->setObjectName(QStringLiteral("IlnCardForm"));
        IlnCardForm->resize(307, 103);
        QIcon icon;
        icon.addFile(QStringLiteral(":/LnnuNetworkHelper/Network.ico"), QSize(), QIcon::Normal, QIcon::Off);
        IlnCardForm->setWindowIcon(icon);
        layoutWidget = new QWidget(IlnCardForm);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 291, 87));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        iln_card_number_le = new QLineEdit(layoutWidget);
        iln_card_number_le->setObjectName(QStringLiteral("iln_card_number_le"));

        gridLayout->addWidget(iln_card_number_le, 0, 1, 1, 3);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        iln_card_vcode_le = new QLineEdit(layoutWidget);
        iln_card_vcode_le->setObjectName(QStringLiteral("iln_card_vcode_le"));

        gridLayout->addWidget(iln_card_vcode_le, 1, 1, 1, 1);

        iln_card_picture = new QLabel(layoutWidget);
        iln_card_picture->setObjectName(QStringLiteral("iln_card_picture"));
        iln_card_picture->setMinimumSize(QSize(70, 30));

        gridLayout->addWidget(iln_card_picture, 1, 2, 1, 1);

        iln_card_reget_button = new QPushButton(layoutWidget);
        iln_card_reget_button->setObjectName(QStringLiteral("iln_card_reget_button"));

        gridLayout->addWidget(iln_card_reget_button, 1, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(218, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 3);

        iln_card_active_button = new QPushButton(layoutWidget);
        iln_card_active_button->setObjectName(QStringLiteral("iln_card_active_button"));

        gridLayout->addWidget(iln_card_active_button, 2, 3, 1, 1);


        retranslateUi(IlnCardForm);

        QMetaObject::connectSlotsByName(IlnCardForm);
    } // setupUi

    void retranslateUi(QWidget *IlnCardForm)
    {
        IlnCardForm->setWindowTitle(QApplication::translate("IlnCardForm", "\347\210\261\350\276\275\345\256\201\346\234\215\345\212\241\346\277\200\346\264\273", 0));
        label->setText(QApplication::translate("IlnCardForm", "\345\272\217\345\210\227\345\217\267:", 0));
#ifndef QT_NO_TOOLTIP
        iln_card_number_le->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        iln_card_number_le->setInputMask(QString());
        iln_card_number_le->setText(QString());
        iln_card_number_le->setPlaceholderText(QApplication::translate("IlnCardForm", "\350\257\267\350\276\223\345\205\24512\344\275\215\347\232\204\345\272\217\345\210\227\345\217\267", 0));
        label_2->setText(QApplication::translate("IlnCardForm", "\351\252\214\350\257\201\347\240\201:", 0));
        iln_card_picture->setText(QString());
        iln_card_reget_button->setText(QApplication::translate("IlnCardForm", "\346\215\242\344\270\200\345\274\240", 0));
        iln_card_active_button->setText(QApplication::translate("IlnCardForm", "\346\277\200\346\264\273", 0));
    } // retranslateUi

};

namespace Ui {
    class IlnCardForm: public Ui_IlnCardForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ILNCARD_H
