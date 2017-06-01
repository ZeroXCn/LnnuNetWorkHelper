/********************************************************************************
** Form generated from reading UI file 'cmccweb.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CMCCWEB_H
#define UI_CMCCWEB_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CmccForm
{
public:
    QFrame *cmcc_info_frame;
    QPushButton *cmcc_logout_pb;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLabel *cmcc_username_lb;
    QLabel *label_3;
    QLabel *cmcc_useMB_lb;
    QLabel *label_2;
    QLabel *cmcc_useType_lb;
    QFrame *cmcc_login_frame;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QComboBox *cmcc_username_cb;
    QPushButton *cmcc_deleteuser_pb;
    QLabel *label_5;
    QPushButton *cmcc_sms_pb;
    QLabel *label_6;
    QLineEdit *cmcc_vcode_le;
    QLabel *cmcc_vcodepic_la;
    QPushButton *cmcc_changevcode_pb;
    QPushButton *cmcc_login_pb;
    QLabel *cmcc_state_la;
    QCheckBox *cmcc_remember_cb;
    QLineEdit *cmcc_password_le;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *CmccForm)
    {
        if (CmccForm->objectName().isEmpty())
            CmccForm->setObjectName(QStringLiteral("CmccForm"));
        CmccForm->resize(330, 172);
        QIcon icon;
        icon.addFile(QStringLiteral(":/LnnuNetworkHelper/Network.ico"), QSize(), QIcon::Normal, QIcon::Off);
        CmccForm->setWindowIcon(icon);
        cmcc_info_frame = new QFrame(CmccForm);
        cmcc_info_frame->setObjectName(QStringLiteral("cmcc_info_frame"));
        cmcc_info_frame->setGeometry(QRect(10, 260, 311, 171));
        cmcc_info_frame->setFrameShape(QFrame::StyledPanel);
        cmcc_info_frame->setFrameShadow(QFrame::Raised);
        cmcc_logout_pb = new QPushButton(cmcc_info_frame);
        cmcc_logout_pb->setObjectName(QStringLiteral("cmcc_logout_pb"));
        cmcc_logout_pb->setGeometry(QRect(220, 130, 75, 23));
        layoutWidget = new QWidget(cmcc_info_frame);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 40, 291, 81));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1, Qt::AlignRight);

        cmcc_username_lb = new QLabel(layoutWidget);
        cmcc_username_lb->setObjectName(QStringLiteral("cmcc_username_lb"));

        gridLayout_2->addWidget(cmcc_username_lb, 0, 1, 1, 2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1, Qt::AlignRight);

        cmcc_useMB_lb = new QLabel(layoutWidget);
        cmcc_useMB_lb->setObjectName(QStringLiteral("cmcc_useMB_lb"));

        gridLayout_2->addWidget(cmcc_useMB_lb, 2, 1, 1, 2);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1, Qt::AlignRight);

        cmcc_useType_lb = new QLabel(layoutWidget);
        cmcc_useType_lb->setObjectName(QStringLiteral("cmcc_useType_lb"));

        gridLayout_2->addWidget(cmcc_useType_lb, 1, 1, 1, 2);

        cmcc_login_frame = new QFrame(CmccForm);
        cmcc_login_frame->setObjectName(QStringLiteral("cmcc_login_frame"));
        cmcc_login_frame->setGeometry(QRect(10, 0, 311, 171));
        cmcc_login_frame->setFrameShape(QFrame::StyledPanel);
        cmcc_login_frame->setFrameShadow(QFrame::Raised);
        layoutWidget1 = new QWidget(cmcc_login_frame);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 292, 151));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        cmcc_username_cb = new QComboBox(layoutWidget1);
        cmcc_username_cb->setObjectName(QStringLiteral("cmcc_username_cb"));
        cmcc_username_cb->setEditable(true);

        gridLayout->addWidget(cmcc_username_cb, 0, 1, 1, 3);

        cmcc_deleteuser_pb = new QPushButton(layoutWidget1);
        cmcc_deleteuser_pb->setObjectName(QStringLiteral("cmcc_deleteuser_pb"));

        gridLayout->addWidget(cmcc_deleteuser_pb, 0, 4, 1, 1);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        cmcc_sms_pb = new QPushButton(layoutWidget1);
        cmcc_sms_pb->setObjectName(QStringLiteral("cmcc_sms_pb"));

        gridLayout->addWidget(cmcc_sms_pb, 1, 4, 1, 1);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        cmcc_vcode_le = new QLineEdit(layoutWidget1);
        cmcc_vcode_le->setObjectName(QStringLiteral("cmcc_vcode_le"));

        gridLayout->addWidget(cmcc_vcode_le, 2, 1, 1, 2);

        cmcc_vcodepic_la = new QLabel(layoutWidget1);
        cmcc_vcodepic_la->setObjectName(QStringLiteral("cmcc_vcodepic_la"));
        cmcc_vcodepic_la->setMinimumSize(QSize(64, 20));

        gridLayout->addWidget(cmcc_vcodepic_la, 2, 3, 1, 1);

        cmcc_changevcode_pb = new QPushButton(layoutWidget1);
        cmcc_changevcode_pb->setObjectName(QStringLiteral("cmcc_changevcode_pb"));

        gridLayout->addWidget(cmcc_changevcode_pb, 2, 4, 1, 1);

        cmcc_login_pb = new QPushButton(layoutWidget1);
        cmcc_login_pb->setObjectName(QStringLiteral("cmcc_login_pb"));

        gridLayout->addWidget(cmcc_login_pb, 3, 4, 1, 1);

        cmcc_state_la = new QLabel(layoutWidget1);
        cmcc_state_la->setObjectName(QStringLiteral("cmcc_state_la"));

        gridLayout->addWidget(cmcc_state_la, 3, 1, 1, 3);

        cmcc_remember_cb = new QCheckBox(layoutWidget1);
        cmcc_remember_cb->setObjectName(QStringLiteral("cmcc_remember_cb"));

        gridLayout->addWidget(cmcc_remember_cb, 1, 3, 1, 1, Qt::AlignHCenter);

        cmcc_password_le = new QLineEdit(layoutWidget1);
        cmcc_password_le->setObjectName(QStringLiteral("cmcc_password_le"));
        cmcc_password_le->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(cmcc_password_le, 1, 1, 1, 2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 0, 1, 1);

        QWidget::setTabOrder(cmcc_login_pb, cmcc_username_cb);
        QWidget::setTabOrder(cmcc_username_cb, cmcc_password_le);
        QWidget::setTabOrder(cmcc_password_le, cmcc_vcode_le);
        QWidget::setTabOrder(cmcc_vcode_le, cmcc_deleteuser_pb);
        QWidget::setTabOrder(cmcc_deleteuser_pb, cmcc_remember_cb);
        QWidget::setTabOrder(cmcc_remember_cb, cmcc_sms_pb);
        QWidget::setTabOrder(cmcc_sms_pb, cmcc_changevcode_pb);

        retranslateUi(CmccForm);

        QMetaObject::connectSlotsByName(CmccForm);
    } // setupUi

    void retranslateUi(QWidget *CmccForm)
    {
        CmccForm->setWindowTitle(QApplication::translate("CmccForm", "CmccForm", 0));
        cmcc_logout_pb->setText(QApplication::translate("CmccForm", "\347\231\273\345\207\272", 0));
        label->setText(QApplication::translate("CmccForm", "\345\270\220\345\217\267:", 0));
        cmcc_username_lb->setText(QString());
        label_3->setText(QApplication::translate("CmccForm", "\346\234\254\346\234\210\345\267\262\347\224\250:", 0));
        cmcc_useMB_lb->setText(QString());
        label_2->setText(QApplication::translate("CmccForm", "\345\245\227\351\244\220\347\261\273\345\236\213:", 0));
        cmcc_useType_lb->setText(QString());
        label_4->setText(QApplication::translate("CmccForm", "\347\224\250\346\210\267\345\220\215:", 0));
        cmcc_deleteuser_pb->setText(QApplication::translate("CmccForm", "\345\210\240\351\231\244", 0));
        label_5->setText(QApplication::translate("CmccForm", "\345\257\206\347\240\201:", 0));
        cmcc_sms_pb->setText(QApplication::translate("CmccForm", "\347\237\255\344\277\241\345\257\206\347\240\201", 0));
        label_6->setText(QApplication::translate("CmccForm", "\351\252\214\350\257\201\347\240\201:", 0));
        cmcc_vcodepic_la->setText(QString());
        cmcc_changevcode_pb->setText(QApplication::translate("CmccForm", "\346\215\242\344\270\200\345\274\240", 0));
        cmcc_login_pb->setText(QApplication::translate("CmccForm", "\347\231\273\351\231\206", 0));
        cmcc_state_la->setText(QString());
#ifndef QT_NO_TOOLTIP
        cmcc_remember_cb->setToolTip(QApplication::translate("CmccForm", "\350\256\260\344\275\217\345\257\206\347\240\201", 0));
#endif // QT_NO_TOOLTIP
        cmcc_remember_cb->setText(QApplication::translate("CmccForm", "\350\256\260\344\275\217", 0));
    } // retranslateUi

};

namespace Ui {
    class CmccForm: public Ui_CmccForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CMCCWEB_H
