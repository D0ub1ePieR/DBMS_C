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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_dbmsmain
{
public:
    QPushButton *info;
    QPushButton *grade;
    QPushButton *choose;
    QPushButton *config;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QDialog *dbmsmain)
    {
        if (dbmsmain->objectName().isEmpty())
            dbmsmain->setObjectName(QStringLiteral("dbmsmain"));
        dbmsmain->resize(669, 536);
        dbmsmain->setStyleSheet(QStringLiteral("background-color: rgb(255, 205, 236);"));
        info = new QPushButton(dbmsmain);
        info->setObjectName(QStringLiteral("info"));
        info->setGeometry(QRect(150, 260, 141, 51));
        info->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\232\266\344\271\246\";\n"
"background-color: rgb(255, 244, 249);"));
        grade = new QPushButton(dbmsmain);
        grade->setObjectName(QStringLiteral("grade"));
        grade->setGeometry(QRect(410, 260, 141, 51));
        grade->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\232\266\344\271\246\";\n"
"background-color: rgb(255, 247, 249);"));
        choose = new QPushButton(dbmsmain);
        choose->setObjectName(QStringLiteral("choose"));
        choose->setGeometry(QRect(150, 380, 141, 51));
        choose->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\232\266\344\271\246\";\n"
"background-color: rgb(255, 244, 249);"));
        config = new QPushButton(dbmsmain);
        config->setObjectName(QStringLiteral("config"));
        config->setGeometry(QRect(410, 380, 141, 51));
        config->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\232\266\344\271\246\";\n"
"background-color: rgb(255, 244, 249);"));
        label = new QLabel(dbmsmain);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 270, 31, 31));
        label->setStyleSheet(QStringLiteral("image:url(:/image/infomation_128px_526982_easyicon.net.ico);"));
        label_2 = new QLabel(dbmsmain);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(370, 270, 31, 31));
        label_2->setStyleSheet(QStringLiteral("image : url(:/image/curriculum_128px_1206171_easyicon.net.ico);"));
        label_3 = new QLabel(dbmsmain);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(110, 390, 31, 31));
        label_3->setStyleSheet(QStringLiteral("image: url(:/image/Courses_128px_1185938_easyicon.net.ico);"));
        label_4 = new QLabel(dbmsmain);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(370, 390, 31, 31));
        label_4->setStyleSheet(QStringLiteral("image: url(:/image/administration_48px_26809_easyicon.net.ico);"));
        label_5 = new QLabel(dbmsmain);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(230, 110, 271, 71));
        label_5->setStyleSheet(QString::fromUtf8("\n"
"font: 48pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));

        retranslateUi(dbmsmain);

        QMetaObject::connectSlotsByName(dbmsmain);
    } // setupUi

    void retranslateUi(QDialog *dbmsmain)
    {
        dbmsmain->setWindowTitle(QApplication::translate("dbmsmain", "\345\255\246\347\224\237\344\277\241\346\201\257\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        info->setText(QApplication::translate("dbmsmain", "\345\255\246\347\224\237\344\277\241\346\201\257\346\237\245\350\257\242", nullptr));
        grade->setText(QApplication::translate("dbmsmain", "\345\255\246\347\224\237\350\257\276\347\250\213\346\237\245\350\257\242", nullptr));
        choose->setText(QApplication::translate("dbmsmain", "\351\200\211\350\257\276\347\263\273\347\273\237", nullptr));
        config->setText(QApplication::translate("dbmsmain", "\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QApplication::translate("dbmsmain", "Welcome", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dbmsmain: public Ui_dbmsmain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBMSMAIN_H
