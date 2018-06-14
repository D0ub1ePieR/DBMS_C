/********************************************************************************
** Form generated from reading UI file 'choose.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSE_H
#define UI_CHOOSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_choose
{
public:
    QPushButton *back;

    void setupUi(QDialog *choose)
    {
        if (choose->objectName().isEmpty())
            choose->setObjectName(QStringLiteral("choose"));
        choose->resize(400, 300);
        back = new QPushButton(choose);
        back->setObjectName(QStringLiteral("back"));
        back->setGeometry(QRect(250, 40, 93, 28));

        retranslateUi(choose);

        QMetaObject::connectSlotsByName(choose);
    } // setupUi

    void retranslateUi(QDialog *choose)
    {
        choose->setWindowTitle(QApplication::translate("choose", "\351\200\211\350\257\276\347\263\273\347\273\237", nullptr));
        back->setText(QApplication::translate("choose", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class choose: public Ui_choose {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSE_H
