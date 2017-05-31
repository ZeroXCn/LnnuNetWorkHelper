/********************************************************************************
** Form generated from reading UI file 'lnnuui.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LNNUUI_H
#define UI_LNNUUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LnnuFrame
{
public:
    QFrame *lnnu_info_frame;
    QPushButton *lnnu_logout_pushbutton;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QVBoxLayout *verticalLayout_2;
    QLabel *lnnu_uerename_label;
    QLabel *lnnu_userrest_label;
    QLabel *lnnu_restmoney_label;
    QLabel *lnnu_onlinenumber_label;
    QLabel *lnnu_deadline_label;
    QLabel *lnnu_nowstate_label;
    QPushButton *lnnu_regetinfo_pushButton;
    QPushButton *lnnu_buypackage_pushButton;
    QPushButton *lnnu_detail_pushbutton;
    QFrame *lnnu_login_frame;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout;
    QCheckBox *lnnu_keepinmine_checkBox;
    QPushButton *lnnu_getcode_pushbutton;
    QLabel *lnnu_code_pic;
    QPushButton *lnnu_user_delete_pushButton;
    QLabel *label_14;
    QLineEdit *lnnu_code_le;
    QLineEdit *lnnu_pass_le;
    QPushButton *lnnu_connect_pushbutton;
    QPushButton *lnnu_login_pushbutton;
    QComboBox *lnnu_user_comboBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *lnnu_state_label;

    void setupUi(QWidget *LnnuFrame)
    {
        if (LnnuFrame->objectName().isEmpty())
            LnnuFrame->setObjectName(QStringLiteral("LnnuFrame"));
        LnnuFrame->resize(334, 193);
        QIcon icon;
        icon.addFile(QStringLiteral(":/LnnuNetworkHelper/Network.ico"), QSize(), QIcon::Normal, QIcon::Off);
        LnnuFrame->setWindowIcon(icon);
        lnnu_info_frame = new QFrame(LnnuFrame);
        lnnu_info_frame->setObjectName(QStringLiteral("lnnu_info_frame"));
        lnnu_info_frame->setGeometry(QRect(10, 240, 321, 181));
        lnnu_info_frame->setFrameShape(QFrame::StyledPanel);
        lnnu_info_frame->setFrameShadow(QFrame::Raised);
        lnnu_logout_pushbutton = new QPushButton(lnnu_info_frame);
        lnnu_logout_pushbutton->setObjectName(QStringLiteral("lnnu_logout_pushbutton"));
        lnnu_logout_pushbutton->setGeometry(QRect(20, 150, 61, 23));
        layoutWidget = new QWidget(lnnu_info_frame);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(17, 31, 301, 118));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout->addWidget(label_6, 0, Qt::AlignRight);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout->addWidget(label_7);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout->addWidget(label_10);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        verticalLayout->addWidget(label_11);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout->addWidget(label_12);

        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));

        verticalLayout->addWidget(label_13);


        formLayout->setLayout(0, QFormLayout::LabelRole, verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lnnu_uerename_label = new QLabel(layoutWidget);
        lnnu_uerename_label->setObjectName(QStringLiteral("lnnu_uerename_label"));

        verticalLayout_2->addWidget(lnnu_uerename_label);

        lnnu_userrest_label = new QLabel(layoutWidget);
        lnnu_userrest_label->setObjectName(QStringLiteral("lnnu_userrest_label"));

        verticalLayout_2->addWidget(lnnu_userrest_label);

        lnnu_restmoney_label = new QLabel(layoutWidget);
        lnnu_restmoney_label->setObjectName(QStringLiteral("lnnu_restmoney_label"));

        verticalLayout_2->addWidget(lnnu_restmoney_label);

        lnnu_onlinenumber_label = new QLabel(layoutWidget);
        lnnu_onlinenumber_label->setObjectName(QStringLiteral("lnnu_onlinenumber_label"));

        verticalLayout_2->addWidget(lnnu_onlinenumber_label);

        lnnu_deadline_label = new QLabel(layoutWidget);
        lnnu_deadline_label->setObjectName(QStringLiteral("lnnu_deadline_label"));

        verticalLayout_2->addWidget(lnnu_deadline_label);

        lnnu_nowstate_label = new QLabel(layoutWidget);
        lnnu_nowstate_label->setObjectName(QStringLiteral("lnnu_nowstate_label"));

        verticalLayout_2->addWidget(lnnu_nowstate_label);


        formLayout->setLayout(0, QFormLayout::FieldRole, verticalLayout_2);

        lnnu_regetinfo_pushButton = new QPushButton(lnnu_info_frame);
        lnnu_regetinfo_pushButton->setObjectName(QStringLiteral("lnnu_regetinfo_pushButton"));
        lnnu_regetinfo_pushButton->setGeometry(QRect(250, 150, 61, 23));
        lnnu_buypackage_pushButton = new QPushButton(lnnu_info_frame);
        lnnu_buypackage_pushButton->setObjectName(QStringLiteral("lnnu_buypackage_pushButton"));
        lnnu_buypackage_pushButton->setGeometry(QRect(90, 150, 61, 23));
        lnnu_detail_pushbutton = new QPushButton(lnnu_info_frame);
        lnnu_detail_pushbutton->setObjectName(QStringLiteral("lnnu_detail_pushbutton"));
        lnnu_detail_pushbutton->setGeometry(QRect(180, 150, 61, 23));
        lnnu_login_frame = new QFrame(LnnuFrame);
        lnnu_login_frame->setObjectName(QStringLiteral("lnnu_login_frame"));
        lnnu_login_frame->setGeometry(QRect(0, 0, 331, 191));
        lnnu_login_frame->setFrameShape(QFrame::StyledPanel);
        lnnu_login_frame->setFrameShadow(QFrame::Raised);
        layoutWidget_2 = new QWidget(lnnu_login_frame);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 10, 311, 171));
        gridLayout = new QGridLayout(layoutWidget_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lnnu_keepinmine_checkBox = new QCheckBox(layoutWidget_2);
        lnnu_keepinmine_checkBox->setObjectName(QStringLiteral("lnnu_keepinmine_checkBox"));

        gridLayout->addWidget(lnnu_keepinmine_checkBox, 1, 4, 1, 2);

        lnnu_getcode_pushbutton = new QPushButton(layoutWidget_2);
        lnnu_getcode_pushbutton->setObjectName(QStringLiteral("lnnu_getcode_pushbutton"));

        gridLayout->addWidget(lnnu_getcode_pushbutton, 2, 5, 1, 1);

        lnnu_code_pic = new QLabel(layoutWidget_2);
        lnnu_code_pic->setObjectName(QStringLiteral("lnnu_code_pic"));
        lnnu_code_pic->setEnabled(true);
        lnnu_code_pic->setMinimumSize(QSize(60, 20));

        gridLayout->addWidget(lnnu_code_pic, 2, 2, 1, 3);

        lnnu_user_delete_pushButton = new QPushButton(layoutWidget_2);
        lnnu_user_delete_pushButton->setObjectName(QStringLiteral("lnnu_user_delete_pushButton"));

        gridLayout->addWidget(lnnu_user_delete_pushButton, 0, 4, 1, 2);

        label_14 = new QLabel(layoutWidget_2);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout->addWidget(label_14, 2, 0, 1, 1);

        lnnu_code_le = new QLineEdit(layoutWidget_2);
        lnnu_code_le->setObjectName(QStringLiteral("lnnu_code_le"));

        gridLayout->addWidget(lnnu_code_le, 2, 1, 1, 1);

        lnnu_pass_le = new QLineEdit(layoutWidget_2);
        lnnu_pass_le->setObjectName(QStringLiteral("lnnu_pass_le"));
        lnnu_pass_le->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lnnu_pass_le, 1, 1, 1, 3);

        lnnu_connect_pushbutton = new QPushButton(layoutWidget_2);
        lnnu_connect_pushbutton->setObjectName(QStringLiteral("lnnu_connect_pushbutton"));

        gridLayout->addWidget(lnnu_connect_pushbutton, 3, 0, 1, 1);

        lnnu_login_pushbutton = new QPushButton(layoutWidget_2);
        lnnu_login_pushbutton->setObjectName(QStringLiteral("lnnu_login_pushbutton"));

        gridLayout->addWidget(lnnu_login_pushbutton, 3, 4, 1, 2);

        lnnu_user_comboBox = new QComboBox(layoutWidget_2);
        lnnu_user_comboBox->setObjectName(QStringLiteral("lnnu_user_comboBox"));
        lnnu_user_comboBox->setEditable(true);

        gridLayout->addWidget(lnnu_user_comboBox, 0, 1, 1, 3);

        label = new QLabel(layoutWidget_2);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(layoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lnnu_state_label = new QLabel(layoutWidget_2);
        lnnu_state_label->setObjectName(QStringLiteral("lnnu_state_label"));
        lnnu_state_label->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(lnnu_state_label, 3, 1, 1, 3, Qt::AlignHCenter);

        QWidget::setTabOrder(lnnu_login_pushbutton, lnnu_user_comboBox);
        QWidget::setTabOrder(lnnu_user_comboBox, lnnu_pass_le);
        QWidget::setTabOrder(lnnu_pass_le, lnnu_code_le);
        QWidget::setTabOrder(lnnu_code_le, lnnu_getcode_pushbutton);
        QWidget::setTabOrder(lnnu_getcode_pushbutton, lnnu_keepinmine_checkBox);
        QWidget::setTabOrder(lnnu_keepinmine_checkBox, lnnu_user_delete_pushButton);
        QWidget::setTabOrder(lnnu_user_delete_pushButton, lnnu_connect_pushbutton);
        QWidget::setTabOrder(lnnu_connect_pushbutton, lnnu_logout_pushbutton);
        QWidget::setTabOrder(lnnu_logout_pushbutton, lnnu_regetinfo_pushButton);

        retranslateUi(LnnuFrame);

        QMetaObject::connectSlotsByName(LnnuFrame);
    } // setupUi

    void retranslateUi(QWidget *LnnuFrame)
    {
        LnnuFrame->setWindowTitle(QApplication::translate("LnnuFrame", "Form", 0));
        lnnu_logout_pushbutton->setText(QApplication::translate("LnnuFrame", "\347\231\273\345\207\272", 0));
        label_6->setText(QApplication::translate("LnnuFrame", "\345\270\220\345\217\267:", 0));
        label_7->setText(QApplication::translate("LnnuFrame", "\346\234\254\346\234\210\345\267\262\347\224\250:", 0));
        label_10->setText(QApplication::translate("LnnuFrame", "\345\211\251\344\275\231\351\207\221\351\242\235:", 0));
        label_11->setText(QApplication::translate("LnnuFrame", "\345\234\250\347\272\277\350\256\276\345\244\207:", 0));
        label_12->setText(QApplication::translate("LnnuFrame", "\345\210\260\346\234\237\346\227\245\346\234\237:", 0));
        label_13->setText(QApplication::translate("LnnuFrame", "\345\275\223\345\211\215\347\212\266\346\200\201:", 0));
        lnnu_uerename_label->setText(QString());
        lnnu_userrest_label->setText(QString());
        lnnu_restmoney_label->setText(QString());
        lnnu_onlinenumber_label->setText(QString());
        lnnu_deadline_label->setText(QString());
        lnnu_nowstate_label->setText(QString());
        lnnu_regetinfo_pushButton->setText(QApplication::translate("LnnuFrame", "\345\210\267\346\226\260", 0));
        lnnu_buypackage_pushButton->setText(QApplication::translate("LnnuFrame", "\350\264\255\344\271\260", 0));
        lnnu_detail_pushbutton->setText(QApplication::translate("LnnuFrame", "\350\257\246\347\273\206", 0));
        lnnu_keepinmine_checkBox->setText(QApplication::translate("LnnuFrame", "\350\256\260\344\275\217\345\257\206\347\240\201", 0));
        lnnu_getcode_pushbutton->setText(QApplication::translate("LnnuFrame", "\345\210\267\346\226\260", 0));
        lnnu_code_pic->setText(QString());
        lnnu_user_delete_pushButton->setText(QApplication::translate("LnnuFrame", "\345\210\240\351\231\244", 0));
        label_14->setText(QApplication::translate("LnnuFrame", "\351\252\214\350\257\201\347\240\201:", 0));
        lnnu_pass_le->setText(QString());
        lnnu_connect_pushbutton->setText(QApplication::translate("LnnuFrame", "\347\233\264\346\216\245\350\201\224\347\275\221", 0));
        lnnu_login_pushbutton->setText(QApplication::translate("LnnuFrame", "\347\231\273\351\231\206", 0));
        lnnu_user_comboBox->setCurrentText(QString());
        label->setText(QApplication::translate("LnnuFrame", "\345\255\246\345\217\267:", 0));
        label_2->setText(QApplication::translate("LnnuFrame", "\345\257\206\347\240\201:", 0));
        lnnu_state_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LnnuFrame: public Ui_LnnuFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LNNUUI_H
