/********************************************************************************
** Form generated from reading UI file 'checklog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKLOG_H
#define UI_CHECKLOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_checklog
{
public:
    QLabel *label;
    QLineEdit *username;
    QLineEdit *password;
    QLabel *label_2;
    QPushButton *login;

    void setupUi(QDialog *checklog)
    {
        if (checklog->objectName().isEmpty())
            checklog->setObjectName(QStringLiteral("checklog"));
        checklog->resize(434, 238);
        label = new QLabel(checklog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 60, 61, 21));
        label->setStyleSheet(QStringLiteral("font: 11pt \"Agency FB\";"));
        username = new QLineEdit(checklog);
        username->setObjectName(QStringLiteral("username"));
        username->setGeometry(QRect(200, 60, 113, 21));
        password = new QLineEdit(checklog);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(200, 110, 113, 21));
        label_2 = new QLabel(checklog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(120, 110, 61, 21));
        label_2->setStyleSheet(QStringLiteral("font: 11pt \"Agency FB\";"));
        login = new QPushButton(checklog);
        login->setObjectName(QStringLiteral("login"));
        login->setGeometry(QRect(160, 170, 93, 28));

        retranslateUi(checklog);

        QMetaObject::connectSlotsByName(checklog);
    } // setupUi

    void retranslateUi(QDialog *checklog)
    {
        checklog->setWindowTitle(QApplication::translate("checklog", "\350\257\267\347\231\273\345\275\225", nullptr));
        label->setText(QApplication::translate("checklog", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_2->setText(QApplication::translate("checklog", "\345\257\206\347\240\201", nullptr));
        login->setText(QApplication::translate("checklog", "\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class checklog: public Ui_checklog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKLOG_H
