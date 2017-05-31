/********************************************************************************
** Form generated from reading UI file 'ilnui.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ILNUI_H
#define UI_ILNUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IlnFrame
{
public:
    QFrame *iln_login_frame;
    QWidget *layoutWidget_5;
    QGridLayout *gridLayout_6;
    QLabel *label_13;
    QCheckBox *iln_keepinmine_checkBox;
    QLabel *label_14;
    QLabel *label_15;
    QPushButton *iln_login_pushbutton;
    QPushButton *iln_getsmspas_pushbutton;
    QComboBox *iln_user_comboBox;
    QLineEdit *iln_pass_le;
    QPushButton *iln_service_pushbutton;
    QPushButton *iln_user_delete_pushButton;
    QLabel *iln_state_label;
    QLineEdit *iln_smspas_le;
    QFrame *iln_info_frame;
    QPushButton *iln_logout_pushbutton;
    QWidget *layoutWidget_6;
    QGridLayout *gridLayout_7;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *iln_price_label;
    QLabel *label_31;
    QLabel *iln_offerHour_label;
    QLabel *label_32;
    QLabel *iln_freeTime_label;
    QComboBox *iln_card_comboBox;
    QLabel *iln_username_label;
    QLabel *label_33;
    QLabel *iln_expTime_label;
    QLabel *label_34;
    QLabel *iln_accuTime_label;
    QLabel *label_35;
    QLabel *iln_effTime_label;
    QCheckBox *iln_nowcard_checkBox;
    QLabel *iln_leftPercent_label;
    QPushButton *iln_recharge_pushButton;

    void setupUi(QWidget *IlnFrame)
    {
        if (IlnFrame->objectName().isEmpty())
            IlnFrame->setObjectName(QStringLiteral("IlnFrame"));
        IlnFrame->resize(333, 182);
        iln_login_frame = new QFrame(IlnFrame);
        iln_login_frame->setObjectName(QStringLiteral("iln_login_frame"));
        iln_login_frame->setGeometry(QRect(0, 0, 321, 171));
        iln_login_frame->setFrameShape(QFrame::StyledPanel);
        iln_login_frame->setFrameShadow(QFrame::Raised);
        layoutWidget_5 = new QWidget(iln_login_frame);
        layoutWidget_5->setObjectName(QStringLiteral("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(10, 20, 311, 151));
        gridLayout_6 = new QGridLayout(layoutWidget_5);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(layoutWidget_5);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_6->addWidget(label_13, 1, 0, 1, 1);

        iln_keepinmine_checkBox = new QCheckBox(layoutWidget_5);
        iln_keepinmine_checkBox->setObjectName(QStringLiteral("iln_keepinmine_checkBox"));

        gridLayout_6->addWidget(iln_keepinmine_checkBox, 1, 3, 1, 1);

        label_14 = new QLabel(layoutWidget_5);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_6->addWidget(label_14, 0, 0, 1, 1);

        label_15 = new QLabel(layoutWidget_5);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_6->addWidget(label_15, 2, 0, 1, 1);

        iln_login_pushbutton = new QPushButton(layoutWidget_5);
        iln_login_pushbutton->setObjectName(QStringLiteral("iln_login_pushbutton"));

        gridLayout_6->addWidget(iln_login_pushbutton, 3, 3, 1, 1);

        iln_getsmspas_pushbutton = new QPushButton(layoutWidget_5);
        iln_getsmspas_pushbutton->setObjectName(QStringLiteral("iln_getsmspas_pushbutton"));

        gridLayout_6->addWidget(iln_getsmspas_pushbutton, 2, 3, 1, 1);

        iln_user_comboBox = new QComboBox(layoutWidget_5);
        iln_user_comboBox->setObjectName(QStringLiteral("iln_user_comboBox"));
        iln_user_comboBox->setEditable(true);

        gridLayout_6->addWidget(iln_user_comboBox, 0, 1, 1, 2);

        iln_pass_le = new QLineEdit(layoutWidget_5);
        iln_pass_le->setObjectName(QStringLiteral("iln_pass_le"));
        iln_pass_le->setEchoMode(QLineEdit::Password);

        gridLayout_6->addWidget(iln_pass_le, 1, 1, 1, 2);

        iln_service_pushbutton = new QPushButton(layoutWidget_5);
        iln_service_pushbutton->setObjectName(QStringLiteral("iln_service_pushbutton"));

        gridLayout_6->addWidget(iln_service_pushbutton, 3, 0, 1, 1);

        iln_user_delete_pushButton = new QPushButton(layoutWidget_5);
        iln_user_delete_pushButton->setObjectName(QStringLiteral("iln_user_delete_pushButton"));

        gridLayout_6->addWidget(iln_user_delete_pushButton, 0, 3, 1, 1);

        iln_state_label = new QLabel(layoutWidget_5);
        iln_state_label->setObjectName(QStringLiteral("iln_state_label"));

        gridLayout_6->addWidget(iln_state_label, 3, 1, 1, 2, Qt::AlignHCenter);

        iln_smspas_le = new QLineEdit(layoutWidget_5);
        iln_smspas_le->setObjectName(QStringLiteral("iln_smspas_le"));

        gridLayout_6->addWidget(iln_smspas_le, 2, 1, 1, 2);

        iln_info_frame = new QFrame(IlnFrame);
        iln_info_frame->setObjectName(QStringLiteral("iln_info_frame"));
        iln_info_frame->setGeometry(QRect(10, 190, 311, 171));
        iln_info_frame->setFrameShape(QFrame::StyledPanel);
        iln_info_frame->setFrameShadow(QFrame::Raised);
        iln_logout_pushbutton = new QPushButton(iln_info_frame);
        iln_logout_pushbutton->setObjectName(QStringLiteral("iln_logout_pushbutton"));
        iln_logout_pushbutton->setGeometry(QRect(220, 140, 75, 23));
        layoutWidget_6 = new QWidget(iln_info_frame);
        layoutWidget_6->setObjectName(QStringLiteral("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(11, 10, 291, 121));
        gridLayout_7 = new QGridLayout(layoutWidget_6);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        label_28 = new QLabel(layoutWidget_6);
        label_28->setObjectName(QStringLiteral("label_28"));

        gridLayout_7->addWidget(label_28, 0, 0, 1, 1);

        label_29 = new QLabel(layoutWidget_6);
        label_29->setObjectName(QStringLiteral("label_29"));

        gridLayout_7->addWidget(label_29, 1, 0, 1, 1);

        label_30 = new QLabel(layoutWidget_6);
        label_30->setObjectName(QStringLiteral("label_30"));

        gridLayout_7->addWidget(label_30, 3, 0, 1, 1);

        iln_price_label = new QLabel(layoutWidget_6);
        iln_price_label->setObjectName(QStringLiteral("iln_price_label"));

        gridLayout_7->addWidget(iln_price_label, 3, 1, 1, 2);

        label_31 = new QLabel(layoutWidget_6);
        label_31->setObjectName(QStringLiteral("label_31"));

        gridLayout_7->addWidget(label_31, 3, 3, 1, 1);

        iln_offerHour_label = new QLabel(layoutWidget_6);
        iln_offerHour_label->setObjectName(QStringLiteral("iln_offerHour_label"));

        gridLayout_7->addWidget(iln_offerHour_label, 3, 4, 1, 2);

        label_32 = new QLabel(layoutWidget_6);
        label_32->setObjectName(QStringLiteral("label_32"));

        gridLayout_7->addWidget(label_32, 4, 3, 1, 1);

        iln_freeTime_label = new QLabel(layoutWidget_6);
        iln_freeTime_label->setObjectName(QStringLiteral("iln_freeTime_label"));

        gridLayout_7->addWidget(iln_freeTime_label, 4, 4, 1, 2);

        iln_card_comboBox = new QComboBox(layoutWidget_6);
        iln_card_comboBox->setObjectName(QStringLiteral("iln_card_comboBox"));

        gridLayout_7->addWidget(iln_card_comboBox, 0, 1, 1, 3);

        iln_username_label = new QLabel(layoutWidget_6);
        iln_username_label->setObjectName(QStringLiteral("iln_username_label"));

        gridLayout_7->addWidget(iln_username_label, 1, 1, 1, 3);

        label_33 = new QLabel(layoutWidget_6);
        label_33->setObjectName(QStringLiteral("label_33"));

        gridLayout_7->addWidget(label_33, 2, 3, 1, 1);

        iln_expTime_label = new QLabel(layoutWidget_6);
        iln_expTime_label->setObjectName(QStringLiteral("iln_expTime_label"));

        gridLayout_7->addWidget(iln_expTime_label, 2, 4, 1, 2);

        label_34 = new QLabel(layoutWidget_6);
        label_34->setObjectName(QStringLiteral("label_34"));

        gridLayout_7->addWidget(label_34, 4, 0, 1, 1);

        iln_accuTime_label = new QLabel(layoutWidget_6);
        iln_accuTime_label->setObjectName(QStringLiteral("iln_accuTime_label"));

        gridLayout_7->addWidget(iln_accuTime_label, 4, 1, 1, 2);

        label_35 = new QLabel(layoutWidget_6);
        label_35->setObjectName(QStringLiteral("label_35"));

        gridLayout_7->addWidget(label_35, 2, 0, 1, 1);

        iln_effTime_label = new QLabel(layoutWidget_6);
        iln_effTime_label->setObjectName(QStringLiteral("iln_effTime_label"));

        gridLayout_7->addWidget(iln_effTime_label, 2, 1, 1, 2);

        iln_nowcard_checkBox = new QCheckBox(layoutWidget_6);
        iln_nowcard_checkBox->setObjectName(QStringLiteral("iln_nowcard_checkBox"));

        gridLayout_7->addWidget(iln_nowcard_checkBox, 0, 4, 1, 1, Qt::AlignHCenter);

        iln_leftPercent_label = new QLabel(layoutWidget_6);
        iln_leftPercent_label->setObjectName(QStringLiteral("iln_leftPercent_label"));

        gridLayout_7->addWidget(iln_leftPercent_label, 0, 5, 1, 1, Qt::AlignHCenter);

        iln_recharge_pushButton = new QPushButton(iln_info_frame);
        iln_recharge_pushButton->setObjectName(QStringLiteral("iln_recharge_pushButton"));
        iln_recharge_pushButton->setGeometry(QRect(10, 140, 75, 23));
        QWidget::setTabOrder(iln_login_pushbutton, iln_user_comboBox);
        QWidget::setTabOrder(iln_user_comboBox, iln_pass_le);
        QWidget::setTabOrder(iln_pass_le, iln_smspas_le);
        QWidget::setTabOrder(iln_smspas_le, iln_getsmspas_pushbutton);
        QWidget::setTabOrder(iln_getsmspas_pushbutton, iln_keepinmine_checkBox);
        QWidget::setTabOrder(iln_keepinmine_checkBox, iln_user_delete_pushButton);
        QWidget::setTabOrder(iln_user_delete_pushButton, iln_service_pushbutton);
        QWidget::setTabOrder(iln_service_pushbutton, iln_logout_pushbutton);
        QWidget::setTabOrder(iln_logout_pushbutton, iln_card_comboBox);
        QWidget::setTabOrder(iln_card_comboBox, iln_nowcard_checkBox);

        retranslateUi(IlnFrame);

        QMetaObject::connectSlotsByName(IlnFrame);
    } // setupUi

    void retranslateUi(QWidget *IlnFrame)
    {
        IlnFrame->setWindowTitle(QApplication::translate("IlnFrame", "Form", 0));
        label_13->setText(QApplication::translate("IlnFrame", "\345\257\206\347\240\201:", 0));
        iln_keepinmine_checkBox->setText(QApplication::translate("IlnFrame", "\350\256\260\344\275\217\345\257\206\347\240\201", 0));
        label_14->setText(QApplication::translate("IlnFrame", "\347\224\250\346\210\267\345\220\215:", 0));
        label_15->setText(QApplication::translate("IlnFrame", "\347\237\255\344\277\241\345\257\206\347\240\201", 0));
        iln_login_pushbutton->setText(QApplication::translate("IlnFrame", "\347\231\273\351\231\206", 0));
        iln_getsmspas_pushbutton->setText(QApplication::translate("IlnFrame", "\350\216\267\345\217\226", 0));
        iln_user_comboBox->setCurrentText(QString());
        iln_pass_le->setText(QString());
        iln_service_pushbutton->setText(QApplication::translate("IlnFrame", "\346\234\215\345\212\241\344\270\255\345\277\203", 0));
        iln_user_delete_pushButton->setText(QApplication::translate("IlnFrame", "\345\210\240\351\231\244", 0));
        iln_state_label->setText(QString());
        iln_logout_pushbutton->setText(QApplication::translate("IlnFrame", "\347\231\273\345\207\272", 0));
        label_28->setText(QApplication::translate("IlnFrame", "\345\245\227\351\244\220:", 0));
        label_29->setText(QApplication::translate("IlnFrame", "\345\270\220\345\217\267:", 0));
        label_30->setText(QApplication::translate("IlnFrame", "\351\207\221\351\242\235:", 0));
        iln_price_label->setText(QString());
        label_31->setText(QApplication::translate("IlnFrame", "\346\227\266\351\225\277:", 0));
        iln_offerHour_label->setText(QString());
        label_32->setText(QApplication::translate("IlnFrame", "\345\211\251\344\275\231\346\227\266\351\225\277:", 0));
        iln_freeTime_label->setText(QString());
        iln_username_label->setText(QString());
        label_33->setText(QApplication::translate("IlnFrame", "\345\244\261\346\225\210\346\227\266\351\227\264:", 0));
        iln_expTime_label->setText(QString());
        label_34->setText(QApplication::translate("IlnFrame", "\345\267\262\347\224\250\346\227\266\351\225\277:", 0));
        iln_accuTime_label->setText(QString());
        label_35->setText(QApplication::translate("IlnFrame", "\347\224\237\346\225\210\346\227\266\351\227\264:", 0));
        iln_effTime_label->setText(QString());
        iln_nowcard_checkBox->setText(QString());
        iln_leftPercent_label->setText(QString());
        iln_recharge_pushButton->setText(QApplication::translate("IlnFrame", "\345\205\205\345\200\274", 0));
    } // retranslateUi

};

namespace Ui {
    class IlnFrame: public Ui_IlnFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ILNUI_H
