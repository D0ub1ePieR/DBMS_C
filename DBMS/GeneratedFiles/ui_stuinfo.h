/********************************************************************************
** Form generated from reading UI file 'stuinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUINFO_H
#define UI_STUINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_stuinfo
{
public:
    QLabel *label;
    QFrame *line;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_6;
    QLineEdit *number;
    QLineEdit *name;
    QLineEdit *dept;
    QCheckBox *man;
    QCheckBox *woman;
    QFrame *line_2;
    QLabel *label_7;
    QTableView *showtable;
    QLabel *label_8;
    QPushButton *query;
    QPushButton *back;
    QLabel *label_5;

    void setupUi(QDialog *stuinfo)
    {
        if (stuinfo->objectName().isEmpty())
            stuinfo->setObjectName(QStringLiteral("stuinfo"));
        stuinfo->resize(730, 568);
        stuinfo->setStyleSheet(QLatin1String("background-color: rgb(246, 255, 247);\n"
""));
        label = new QLabel(stuinfo);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 20, 101, 31));
        label->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\346\226\271\346\255\243\345\205\260\344\272\255\350\266\205\347\273\206\351\273\221\347\256\200\344\275\223\";\n"
""));
        line = new QFrame(stuinfo);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 50, 711, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(stuinfo);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 80, 41, 16));
        label_2->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_3 = new QLabel(stuinfo);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 120, 41, 16));
        label_3->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_4 = new QLabel(stuinfo);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 160, 41, 16));
        label_4->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_6 = new QLabel(stuinfo);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(410, 80, 41, 21));
        label_6->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        number = new QLineEdit(stuinfo);
        number->setObjectName(QStringLiteral("number"));
        number->setGeometry(QRect(90, 80, 113, 21));
        number->setStyleSheet(QStringLiteral("background-color: rgb(253, 253, 253);"));
        name = new QLineEdit(stuinfo);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(90, 120, 113, 21));
        name->setStyleSheet(QStringLiteral("background-color: rgb(253, 253, 253);"));
        dept = new QLineEdit(stuinfo);
        dept->setObjectName(QStringLiteral("dept"));
        dept->setGeometry(QRect(460, 80, 181, 21));
        dept->setStyleSheet(QStringLiteral("background-color: rgb(253, 253, 253);"));
        man = new QCheckBox(stuinfo);
        man->setObjectName(QStringLiteral("man"));
        man->setGeometry(QRect(100, 160, 51, 19));
        woman = new QCheckBox(stuinfo);
        woman->setObjectName(QStringLiteral("woman"));
        woman->setGeometry(QRect(160, 160, 41, 19));
        line_2 = new QFrame(stuinfo);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(10, 190, 711, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_7 = new QLabel(stuinfo);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(390, 160, 211, 16));
        label_7->setStyleSheet(QStringLiteral("color: rgb(255, 19, 11);"));
        showtable = new QTableView(stuinfo);
        showtable->setObjectName(QStringLiteral("showtable"));
        showtable->setGeometry(QRect(30, 220, 661, 321));
        showtable->setStyleSheet(QStringLiteral("background-color: rgb(253, 253, 253);"));
        label_8 = new QLabel(stuinfo);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(30, 20, 31, 31));
        label_8->setStyleSheet(QString::fromUtf8("image:url(:/image/\346\243\222\346\243\222\347\263\226.ico)"));
        query = new QPushButton(stuinfo);
        query->setObjectName(QStringLiteral("query"));
        query->setGeometry(QRect(550, 137, 161, 41));
        query->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\347\273\206\351\273\221\";"));
        back = new QPushButton(stuinfo);
        back->setObjectName(QStringLiteral("back"));
        back->setGeometry(QRect(620, 10, 93, 28));
        label_5 = new QLabel(stuinfo);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(310, 10, 301, 31));
        label_5->setStyleSheet(QString::fromUtf8("font: 18pt \"\351\232\266\344\271\246\";\n"
"color: rgb(255, 125, 65);"));

        retranslateUi(stuinfo);

        QMetaObject::connectSlotsByName(stuinfo);
    } // setupUi

    void retranslateUi(QDialog *stuinfo)
    {
        stuinfo->setWindowTitle(QApplication::translate("stuinfo", "\345\255\246\347\224\237\344\277\241\346\201\257\346\237\245\350\257\242", nullptr));
        label->setText(QApplication::translate("stuinfo", "\344\277\241\346\201\257\346\237\245\350\257\242", nullptr));
        label_2->setText(QApplication::translate("stuinfo", "\345\255\246\345\217\267", nullptr));
        label_3->setText(QApplication::translate("stuinfo", "\345\247\223\345\220\215", nullptr));
        label_4->setText(QApplication::translate("stuinfo", "\346\200\247\345\210\253", nullptr));
        label_6->setText(QApplication::translate("stuinfo", "\351\231\242\347\263\273", nullptr));
        man->setText(QApplication::translate("stuinfo", "\347\224\267", nullptr));
        woman->setText(QApplication::translate("stuinfo", "\345\245\263", nullptr));
        label_7->setText(QApplication::translate("stuinfo", "*\344\273\245\344\270\212\351\200\211\351\241\271\345\235\207\351\235\236\345\277\205\351\241\273", nullptr));
        label_8->setText(QString());
        query->setText(QApplication::translate("stuinfo", "\345\274\200\345\247\213\346\237\245\350\257\242", nullptr));
        back->setText(QApplication::translate("stuinfo", "\350\277\224\345\233\236", nullptr));
        label_5->setText(QApplication::translate("stuinfo", "\346\262\241\346\234\211\347\276\216\345\267\245\357\274\214\345\217\252\346\203\263\350\267\263\346\262\263", nullptr));
    } // retranslateUi

};

namespace Ui {
    class stuinfo: public Ui_stuinfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUINFO_H
