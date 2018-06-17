/********************************************************************************
** Form generated from reading UI file 'config.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIG_H
#define UI_CONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_config
{
public:
    QFrame *line;
    QPushButton *back;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *number;
    QLabel *label_4;
    QLineEdit *name;
    QLabel *label_5;
    QLineEdit *age;
    QLabel *label_6;
    QLineEdit *dept;
    QCheckBox *woman;
    QLabel *label_7;
    QCheckBox *man;
    QPushButton *add;
    QFrame *line_2;
    QLabel *label_8;
    QTableWidget *showtable;
    QPushButton *fix;
    QPushButton *delete_2;

    void setupUi(QDialog *config)
    {
        if (config->objectName().isEmpty())
            config->setObjectName(QStringLiteral("config"));
        config->resize(751, 603);
        line = new QFrame(config);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 50, 741, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        back = new QPushButton(config);
        back->setObjectName(QStringLiteral("back"));
        back->setGeometry(QRect(600, 10, 101, 31));
        label = new QLabel(config);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 131, 41));
        label->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_2 = new QLabel(config);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 90, 81, 31));
        label_2->setStyleSheet(QString::fromUtf8("font: 25 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));
        label_3 = new QLabel(config);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(60, 140, 41, 21));
        number = new QLineEdit(config);
        number->setObjectName(QStringLiteral("number"));
        number->setGeometry(QRect(100, 140, 101, 21));
        label_4 = new QLabel(config);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(250, 140, 31, 16));
        name = new QLineEdit(config);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(290, 140, 113, 21));
        label_5 = new QLabel(config);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(60, 180, 41, 16));
        age = new QLineEdit(config);
        age->setObjectName(QStringLiteral("age"));
        age->setGeometry(QRect(100, 180, 101, 21));
        label_6 = new QLabel(config);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(250, 180, 41, 16));
        dept = new QLineEdit(config);
        dept->setObjectName(QStringLiteral("dept"));
        dept->setGeometry(QRect(290, 180, 113, 21));
        woman = new QCheckBox(config);
        woman->setObjectName(QStringLiteral("woman"));
        woman->setGeometry(QRect(570, 140, 41, 19));
        label_7 = new QLabel(config);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(450, 140, 41, 16));
        label_7->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        man = new QCheckBox(config);
        man->setObjectName(QStringLiteral("man"));
        man->setGeometry(QRect(510, 140, 51, 19));
        add = new QPushButton(config);
        add->setObjectName(QStringLiteral("add"));
        add->setGeometry(QRect(480, 180, 93, 28));
        line_2 = new QFrame(config);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(0, 220, 741, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_8 = new QLabel(config);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 250, 171, 31));
        label_8->setStyleSheet(QString::fromUtf8("font: 25 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));
        showtable = new QTableWidget(config);
        showtable->setObjectName(QStringLiteral("showtable"));
        showtable->setGeometry(QRect(40, 300, 651, 261));
        fix = new QPushButton(config);
        fix->setObjectName(QStringLiteral("fix"));
        fix->setGeometry(QRect(250, 250, 93, 28));
        delete_2 = new QPushButton(config);
        delete_2->setObjectName(QStringLiteral("delete_2"));
        delete_2->setGeometry(QRect(410, 250, 93, 28));

        retranslateUi(config);

        QMetaObject::connectSlotsByName(config);
    } // setupUi

    void retranslateUi(QDialog *config)
    {
        config->setWindowTitle(QApplication::translate("config", "\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        back->setText(QApplication::translate("config", "\350\277\224\345\233\236", nullptr));
        label->setText(QApplication::translate("config", "\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        label_2->setText(QApplication::translate("config", "\346\267\273\345\212\240\345\255\246\347\224\237", nullptr));
        label_3->setText(QApplication::translate("config", "\345\255\246\345\217\267", nullptr));
        label_4->setText(QApplication::translate("config", "\345\247\223\345\220\215", nullptr));
        label_5->setText(QApplication::translate("config", "\345\271\264\351\276\204", nullptr));
        label_6->setText(QApplication::translate("config", "\351\231\242\347\263\273", nullptr));
        woman->setText(QApplication::translate("config", "\345\245\263", nullptr));
        label_7->setText(QApplication::translate("config", "\346\200\247\345\210\253", nullptr));
        man->setText(QApplication::translate("config", "\347\224\267", nullptr));
        add->setText(QApplication::translate("config", "\346\267\273\345\212\240", nullptr));
        label_8->setText(QApplication::translate("config", "\344\277\256\346\224\271\345\210\240\351\231\244\345\255\246\347\224\237\344\277\241\346\201\257", nullptr));
        fix->setText(QApplication::translate("config", "\344\277\256\346\224\271\351\200\211\344\270\255\350\241\214", nullptr));
        delete_2->setText(QApplication::translate("config", "\345\210\240\351\231\244\351\200\211\344\270\255\350\241\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class config: public Ui_config {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIG_H
