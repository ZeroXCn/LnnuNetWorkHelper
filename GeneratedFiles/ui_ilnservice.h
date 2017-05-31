/********************************************************************************
** Form generated from reading UI file 'ilnservice.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ILNSERVICE_H
#define UI_ILNSERVICE_H

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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IlnServiceForm
{
public:
    QFrame *iln_service_login_frame;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *iln_service_user_cb;
    QLabel *label_2;
    QLineEdit *iln_service_password_le;
    QPushButton *iln_service_sms_pb;
    QLabel *label_3;
    QLineEdit *iln_service_vcode_le;
    QLabel *iln_service_vcodepic_la;
    QPushButton *iln_service_getpic_pb;
    QPushButton *iln_service_reset_pb;
    QLabel *iln_service_state_la;
    QPushButton *iln_service_login_pb;
    QFrame *iln_service_info_frame;
    QTabWidget *tabWidget;
    QWidget *tab;
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
    QWidget *tab_3;
    QPushButton *iln_service_forcelogout_pb;

    void setupUi(QWidget *IlnServiceForm)
    {
        if (IlnServiceForm->objectName().isEmpty())
            IlnServiceForm->setObjectName(QStringLiteral("IlnServiceForm"));
        IlnServiceForm->resize(346, 184);
        QIcon icon;
        icon.addFile(QStringLiteral(":/LnnuNetworkHelper/Network.ico"), QSize(), QIcon::Normal, QIcon::Off);
        IlnServiceForm->setWindowIcon(icon);
        iln_service_login_frame = new QFrame(IlnServiceForm);
        iln_service_login_frame->setObjectName(QStringLiteral("iln_service_login_frame"));
        iln_service_login_frame->setGeometry(QRect(10, 0, 331, 181));
        iln_service_login_frame->setFrameShape(QFrame::StyledPanel);
        iln_service_login_frame->setFrameShadow(QFrame::Raised);
        layoutWidget = new QWidget(iln_service_login_frame);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 10, 321, 161));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        iln_service_user_cb = new QComboBox(layoutWidget);
        iln_service_user_cb->setObjectName(QStringLiteral("iln_service_user_cb"));
        iln_service_user_cb->setEditable(true);

        gridLayout->addWidget(iln_service_user_cb, 0, 1, 1, 5);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        iln_service_password_le = new QLineEdit(layoutWidget);
        iln_service_password_le->setObjectName(QStringLiteral("iln_service_password_le"));
        iln_service_password_le->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(iln_service_password_le, 1, 1, 1, 3);

        iln_service_sms_pb = new QPushButton(layoutWidget);
        iln_service_sms_pb->setObjectName(QStringLiteral("iln_service_sms_pb"));

        gridLayout->addWidget(iln_service_sms_pb, 1, 4, 1, 2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        iln_service_vcode_le = new QLineEdit(layoutWidget);
        iln_service_vcode_le->setObjectName(QStringLiteral("iln_service_vcode_le"));

        gridLayout->addWidget(iln_service_vcode_le, 2, 1, 1, 2);

        iln_service_vcodepic_la = new QLabel(layoutWidget);
        iln_service_vcodepic_la->setObjectName(QStringLiteral("iln_service_vcodepic_la"));
        iln_service_vcodepic_la->setMinimumSize(QSize(78, 40));

        gridLayout->addWidget(iln_service_vcodepic_la, 2, 3, 1, 2);

        iln_service_getpic_pb = new QPushButton(layoutWidget);
        iln_service_getpic_pb->setObjectName(QStringLiteral("iln_service_getpic_pb"));

        gridLayout->addWidget(iln_service_getpic_pb, 2, 5, 1, 1);

        iln_service_reset_pb = new QPushButton(layoutWidget);
        iln_service_reset_pb->setObjectName(QStringLiteral("iln_service_reset_pb"));

        gridLayout->addWidget(iln_service_reset_pb, 3, 0, 1, 2);

        iln_service_state_la = new QLabel(layoutWidget);
        iln_service_state_la->setObjectName(QStringLiteral("iln_service_state_la"));

        gridLayout->addWidget(iln_service_state_la, 3, 2, 1, 2, Qt::AlignHCenter);

        iln_service_login_pb = new QPushButton(layoutWidget);
        iln_service_login_pb->setObjectName(QStringLiteral("iln_service_login_pb"));

        gridLayout->addWidget(iln_service_login_pb, 3, 4, 1, 2);

        iln_service_info_frame = new QFrame(IlnServiceForm);
        iln_service_info_frame->setObjectName(QStringLiteral("iln_service_info_frame"));
        iln_service_info_frame->setGeometry(QRect(10, 240, 331, 181));
        iln_service_info_frame->setFrameShape(QFrame::StyledPanel);
        iln_service_info_frame->setFrameShadow(QFrame::Raised);
        tabWidget = new QTabWidget(iln_service_info_frame);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 311, 161));
        tabWidget->setTabPosition(QTabWidget::North);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        layoutWidget_6 = new QWidget(tab);
        layoutWidget_6->setObjectName(QStringLiteral("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(10, 10, 291, 121));
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

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        iln_service_forcelogout_pb = new QPushButton(tab_3);
        iln_service_forcelogout_pb->setObjectName(QStringLiteral("iln_service_forcelogout_pb"));
        iln_service_forcelogout_pb->setGeometry(QRect(110, 60, 91, 23));
        tabWidget->addTab(tab_3, QString());
        QWidget::setTabOrder(iln_service_login_pb, iln_service_user_cb);
        QWidget::setTabOrder(iln_service_user_cb, iln_service_password_le);
        QWidget::setTabOrder(iln_service_password_le, iln_service_sms_pb);
        QWidget::setTabOrder(iln_service_sms_pb, iln_service_vcode_le);
        QWidget::setTabOrder(iln_service_vcode_le, iln_service_getpic_pb);
        QWidget::setTabOrder(iln_service_getpic_pb, iln_service_reset_pb);
        QWidget::setTabOrder(iln_service_reset_pb, tabWidget);
        QWidget::setTabOrder(tabWidget, iln_card_comboBox);
        QWidget::setTabOrder(iln_card_comboBox, iln_nowcard_checkBox);
        QWidget::setTabOrder(iln_nowcard_checkBox, iln_service_forcelogout_pb);

        retranslateUi(IlnServiceForm);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(IlnServiceForm);
    } // setupUi

    void retranslateUi(QWidget *IlnServiceForm)
    {
        IlnServiceForm->setWindowTitle(QApplication::translate("IlnServiceForm", "\347\210\261\350\276\275\345\256\201\346\234\215\345\212\241\344\270\255\345\277\203", 0));
        label->setText(QApplication::translate("IlnServiceForm", "\347\224\250\346\210\267\345\220\215:", 0));
        label_2->setText(QApplication::translate("IlnServiceForm", "\345\257\206\347\240\201:", 0));
        iln_service_sms_pb->setText(QApplication::translate("IlnServiceForm", "\347\237\255\344\277\241\345\257\206\347\240\201", 0));
        label_3->setText(QApplication::translate("IlnServiceForm", "\351\252\214\350\257\201\347\240\201:", 0));
        iln_service_vcodepic_la->setText(QString());
        iln_service_getpic_pb->setText(QApplication::translate("IlnServiceForm", "\346\215\242\344\270\200\345\274\240", 0));
        iln_service_reset_pb->setText(QApplication::translate("IlnServiceForm", "\351\207\215\347\275\256", 0));
        iln_service_state_la->setText(QString());
        iln_service_login_pb->setText(QApplication::translate("IlnServiceForm", "\347\231\273\351\231\206", 0));
        label_28->setText(QApplication::translate("IlnServiceForm", "\345\245\227\351\244\220:", 0));
        label_29->setText(QApplication::translate("IlnServiceForm", "\345\270\220\345\217\267:", 0));
        label_30->setText(QApplication::translate("IlnServiceForm", "\351\207\221\351\242\235:", 0));
        iln_price_label->setText(QString());
        label_31->setText(QApplication::translate("IlnServiceForm", "\346\227\266\351\225\277:", 0));
        iln_offerHour_label->setText(QString());
        label_32->setText(QApplication::translate("IlnServiceForm", "\345\211\251\344\275\231\346\227\266\351\225\277:", 0));
        iln_freeTime_label->setText(QString());
        iln_username_label->setText(QString());
        label_33->setText(QApplication::translate("IlnServiceForm", "\345\244\261\346\225\210\346\227\266\351\227\264:", 0));
        iln_expTime_label->setText(QString());
        label_34->setText(QApplication::translate("IlnServiceForm", "\345\267\262\347\224\250\346\227\266\351\225\277:", 0));
        iln_accuTime_label->setText(QString());
        label_35->setText(QApplication::translate("IlnServiceForm", "\347\224\237\346\225\210\346\227\266\351\227\264:", 0));
        iln_effTime_label->setText(QString());
        iln_nowcard_checkBox->setText(QString());
        iln_leftPercent_label->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("IlnServiceForm", "\346\210\221\347\232\204\344\270\232\345\212\241", 0));
        iln_service_forcelogout_pb->setText(QApplication::translate("IlnServiceForm", "\347\241\256\350\256\244\345\274\272\345\210\266\344\270\213\347\272\277", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("IlnServiceForm", "\345\274\272\345\210\266\344\270\213\347\272\277", 0));
    } // retranslateUi

};

namespace Ui {
    class IlnServiceForm: public Ui_IlnServiceForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ILNSERVICE_H
