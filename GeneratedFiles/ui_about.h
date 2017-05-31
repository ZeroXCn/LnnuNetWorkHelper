/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AboutForm
{
public:
    QLabel *body_label;

    void setupUi(QWidget *AboutForm)
    {
        if (AboutForm->objectName().isEmpty())
            AboutForm->setObjectName(QStringLiteral("AboutForm"));
        AboutForm->resize(312, 175);
        body_label = new QLabel(AboutForm);
        body_label->setObjectName(QStringLiteral("body_label"));
        body_label->setGeometry(QRect(0, 10, 311, 161));

        retranslateUi(AboutForm);

        QMetaObject::connectSlotsByName(AboutForm);
    } // setupUi

    void retranslateUi(QWidget *AboutForm)
    {
        AboutForm->setWindowTitle(QApplication::translate("AboutForm", "Form", 0));
        body_label->setText(QApplication::translate("AboutForm", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">%1</span></p><p align=\"center\">\347\211\210\346\234\254\345\217\267:%2 <br/>\345\210\235\350\241\267\346\230\257\347\224\250\346\235\245\346\226\271\344\276\277\345\220\214\345\255\246\344\273\254\347\232\204\346\227\245\345\270\270\344\270\212\347\275\221,\344\273\245\345\217\212\344\277\241\346\201\257\347\232\204\346\237\245\347\234\213<br/>\345\217\252\350\246\201\350\276\223\345\205\245\346\255\243\347\241\256\347\232\204\344\277\241\346\201\257\345\260\261\345\217\257\344\273\245\347\224\250\346\235\245\347\231\273\351\231\206\344\272\206 <br/>\345\246\202\346\236\234\347\250\213\345\272\217\346\234\211BUG\350\257\267\345\217\212\346\227\266\345\217\215\351\246\210\347\273\231\346\210\221\343\200\202 <br/>\350\201\224\347\263\273\351\202\256\347\256\261:<a href=\"mailto:cnscj@qq.com\"><span style=\" text-decoration: underline; color:#0000ff;\">cnscj@qq.com</span></a><br/>\345\216\206\345\217\262\347\211\210\346\234\254:<a href=\"ht"
                        "tp://pan.baidu.com/s/1i4PjOPZ\"><span style=\" text-decoration: underline; color:#0000ff;\">http://pan.baidu.com/s/1i4PjOPZ</span></a><br/>GitHub\345\274\200\346\272\220:<a href=\"https://github.com/ZeroXCn/LnnuNetWorkHelper\"><span style=\" text-decoration: underline; color:#0000ff;\">http://dwz.cn/5Y53kT</span></a><br/>by ZeroX <br/>%3 </p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class AboutForm: public Ui_AboutForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
