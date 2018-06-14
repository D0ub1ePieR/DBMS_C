/********************************************************************************
** Form generated from reading UI file 'inputnum.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTNUM_H
#define UI_INPUTNUM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_inputnum
{
public:
    QLabel *label;
    QLineEdit *number;
    QPushButton *enter;

    void setupUi(QDialog *inputnum)
    {
        if (inputnum->objectName().isEmpty())
            inputnum->setObjectName(QStringLiteral("inputnum"));
        inputnum->resize(400, 142);
        label = new QLabel(inputnum);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 40, 121, 21));
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));
        number = new QLineEdit(inputnum);
        number->setObjectName(QStringLiteral("number"));
        number->setGeometry(QRect(170, 40, 191, 21));
        enter = new QPushButton(inputnum);
        enter->setObjectName(QStringLiteral("enter"));
        enter->setGeometry(QRect(150, 90, 93, 28));

        retranslateUi(inputnum);

        QMetaObject::connectSlotsByName(inputnum);
    } // setupUi

    void retranslateUi(QDialog *inputnum)
    {
        inputnum->setWindowTitle(QApplication::translate("inputnum", "\347\231\273\345\275\225", nullptr));
        label->setText(QApplication::translate("inputnum", "\350\257\267\350\276\223\345\205\245\345\255\246\345\217\267", nullptr));
        enter->setText(QApplication::translate("inputnum", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class inputnum: public Ui_inputnum {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTNUM_H
