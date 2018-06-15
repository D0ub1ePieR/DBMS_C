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
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_choose
{
public:
    QPushButton *back;
    QFrame *line;
    QLabel *label;
    QListWidget *nowclass;
    QListWidget *chooseclass;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *select;

    void setupUi(QDialog *choose)
    {
        if (choose->objectName().isEmpty())
            choose->setObjectName(QStringLiteral("choose"));
        choose->resize(692, 539);
        back = new QPushButton(choose);
        back->setObjectName(QStringLiteral("back"));
        back->setGeometry(QRect(400, 470, 93, 28));
        line = new QFrame(choose);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 60, 661, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(choose);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 20, 121, 41));
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        nowclass = new QListWidget(choose);
        nowclass->setObjectName(QStringLiteral("nowclass"));
        nowclass->setGeometry(QRect(50, 110, 191, 311));
        chooseclass = new QListWidget(choose);
        chooseclass->setObjectName(QStringLiteral("chooseclass"));
        chooseclass->setGeometry(QRect(440, 110, 191, 311));
        label_2 = new QLabel(choose);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(281, 330, 141, 41));
        label_2->setStyleSheet(QStringLiteral("image: url(:/image/left.ico);"));
        label_3 = new QLabel(choose);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(280, 140, 141, 41));
        label_3->setStyleSheet(QStringLiteral("image: url(:/image/right.ico);"));
        label_4 = new QLabel(choose);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(300, 300, 81, 16));
        label_4->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\215\216\346\226\207\346\226\260\351\255\217\";\n"
"color: rgb(255, 8, 8);"));
        label_5 = new QLabel(choose);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(300, 200, 81, 16));
        label_5->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\215\216\346\226\207\346\226\260\351\255\217\";\n"
"color: rgb(255, 8, 8);"));
        select = new QPushButton(choose);
        select->setObjectName(QStringLiteral("select"));
        select->setGeometry(QRect(210, 470, 93, 28));

        retranslateUi(choose);

        QMetaObject::connectSlotsByName(choose);
    } // setupUi

    void retranslateUi(QDialog *choose)
    {
        choose->setWindowTitle(QApplication::translate("choose", "\351\200\211\350\257\276\347\263\273\347\273\237", nullptr));
        back->setText(QApplication::translate("choose", "\350\277\224\345\233\236", nullptr));
        label->setText(QApplication::translate("choose", "\351\200\211\350\257\276\347\263\273\347\273\237", nullptr));
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QApplication::translate("choose", "\346\234\252\351\200\211\350\257\276\347\250\213", nullptr));
        label_5->setText(QApplication::translate("choose", "\345\267\262\351\200\211\350\257\276\347\250\213", nullptr));
        select->setText(QApplication::translate("choose", "\351\200\211\346\213\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class choose: public Ui_choose {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSE_H
