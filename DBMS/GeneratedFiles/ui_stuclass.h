/********************************************************************************
** Form generated from reading UI file 'stuclass.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUCLASS_H
#define UI_STUCLASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_stuclass
{
public:
    QFrame *line;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *number;
    QLabel *label_3;
    QComboBox *choice;
    QPushButton *back;
    QPushButton *query;
    QFrame *line_2;
    QTableView *showtable;

    void setupUi(QDialog *stuclass)
    {
        if (stuclass->objectName().isEmpty())
            stuclass->setObjectName(QStringLiteral("stuclass"));
        stuclass->resize(733, 564);
        line = new QFrame(stuclass);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(20, 70, 701, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(stuclass);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 20, 131, 51));
        label->setStyleSheet(QString::fromUtf8("font: 17pt \"\345\215\216\346\226\207\346\226\260\351\255\217\";"));
        label_2 = new QLabel(stuclass);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 110, 51, 21));
        label_2->setStyleSheet(QStringLiteral("font: 10pt \"Agency FB\";"));
        number = new QLineEdit(stuclass);
        number->setObjectName(QStringLiteral("number"));
        number->setGeometry(QRect(80, 110, 113, 21));
        label_3 = new QLabel(stuclass);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 160, 41, 21));
        label_3->setStyleSheet(QStringLiteral("font: 10pt \"Agency FB\";"));
        choice = new QComboBox(stuclass);
        choice->addItem(QString());
        choice->addItem(QString());
        choice->setObjectName(QStringLiteral("choice"));
        choice->setGeometry(QRect(80, 160, 111, 22));
        back = new QPushButton(stuclass);
        back->setObjectName(QStringLiteral("back"));
        back->setGeometry(QRect(600, 30, 93, 28));
        query = new QPushButton(stuclass);
        query->setObjectName(QStringLiteral("query"));
        query->setGeometry(QRect(540, 100, 161, 91));
        query->setStyleSheet(QString::fromUtf8("font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        line_2 = new QFrame(stuclass);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(10, 210, 711, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        showtable = new QTableView(stuclass);
        showtable->setObjectName(QStringLiteral("showtable"));
        showtable->setGeometry(QRect(50, 240, 641, 281));

        retranslateUi(stuclass);

        QMetaObject::connectSlotsByName(stuclass);
    } // setupUi

    void retranslateUi(QDialog *stuclass)
    {
        stuclass->setWindowTitle(QApplication::translate("stuclass", "\345\255\246\347\224\237\350\257\276\347\250\213\346\237\245\350\257\242", nullptr));
        label->setText(QApplication::translate("stuclass", "\346\210\220\347\273\251\346\237\245\350\257\242", nullptr));
        label_2->setText(QApplication::translate("stuclass", "\345\255\246\345\217\267", nullptr));
        label_3->setText(QApplication::translate("stuclass", "\350\257\276\347\250\213", nullptr));
        choice->setItemText(0, QApplication::translate("stuclass", "...", nullptr));
        choice->setItemText(1, QApplication::translate("stuclass", "ALL", nullptr));

        back->setText(QApplication::translate("stuclass", "\350\277\224\345\233\236", nullptr));
        query->setText(QApplication::translate("stuclass", "\345\274\200\345\220\257\n"
"\346\277\200\345\212\250\344\272\272\345\277\203\n"
"\347\232\204\346\227\266\345\210\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class stuclass: public Ui_stuclass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUCLASS_H
