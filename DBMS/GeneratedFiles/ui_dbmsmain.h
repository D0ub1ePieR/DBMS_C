/********************************************************************************
** Form generated from reading UI file 'dbmsmain.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBMSMAIN_H
#define UI_DBMSMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_dbmsmain
{
public:

    void setupUi(QDialog *dbmsmain)
    {
        if (dbmsmain->objectName().isEmpty())
            dbmsmain->setObjectName(QStringLiteral("dbmsmain"));
        dbmsmain->resize(400, 300);

        retranslateUi(dbmsmain);

        QMetaObject::connectSlotsByName(dbmsmain);
    } // setupUi

    void retranslateUi(QDialog *dbmsmain)
    {
        dbmsmain->setWindowTitle(QApplication::translate("dbmsmain", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dbmsmain: public Ui_dbmsmain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBMSMAIN_H
