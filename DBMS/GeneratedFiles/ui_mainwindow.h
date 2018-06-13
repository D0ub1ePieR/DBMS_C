/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QWidget *centralWidget;
    QLabel *logo;
    QLabel *title;
    QLabel *label;
    QComboBox *source;
    QPushButton *connect;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(715, 566);
        MainWindow->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        logo = new QLabel(centralWidget);
        logo->setObjectName(QStringLiteral("logo"));
        logo->setGeometry(QRect(180, 120, 111, 61));
        logo->setStyleSheet(QStringLiteral("image: url(:/image/ball.ico);"));
        title = new QLabel(centralWidget);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(250, 130, 241, 41));
        title->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";\n"
"color: rgb(19, 153, 255);\n"
"margin: 0 auto;"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(250, 470, 171, 21));
        label->setStyleSheet(QString::fromUtf8("font: 9pt \"\346\226\271\346\255\243\345\247\232\344\275\223\";"));
        source = new QComboBox(centralWidget);
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/dbicon.ico"), QSize(), QIcon::Normal, QIcon::On);
        source->addItem(icon, QString());
        source->addItem(QString());
        source->addItem(QString());
        source->setObjectName(QStringLiteral("source"));
        source->setGeometry(QRect(210, 250, 251, 22));
        source->setEditable(true);
        connect = new QPushButton(centralWidget);
        connect->setObjectName(QStringLiteral("connect"));
        connect->setGeometry(QRect(250, 320, 161, 31));
        connect->setStyleSheet(QString::fromUtf8("background-color: rgb(196, 147, 255);\n"
"font: 11pt \"\351\273\221\344\275\223\";\n"
"border-color: rgb(255, 219, 88);\n"
"margin: 0 auto;"));
        MainWindow->setCentralWidget(centralWidget);
        source->raise();
        logo->raise();
        title->raise();
        label->raise();
        connect->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 715, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action);
        mainToolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\346\225\260\346\215\256\345\272\223\347\256\241\347\220\206\347\263\273\347\273\237        By:D0ub1e_PieR", nullptr));
        action->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        logo->setText(QString());
        title->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245\346\225\260\346\215\256\345\272\223", nullptr));
        label->setText(QApplication::translate("MainWindow", "Designed by D0ub1e_PieR", nullptr));
        source->setItemText(0, QApplication::translate("MainWindow", "\351\200\211\346\213\251\346\225\260\346\215\256\346\272\220", nullptr));
        source->setItemText(1, QApplication::translate("MainWindow", "dbserver", nullptr));
        source->setItemText(2, QApplication::translate("MainWindow", "localhost", nullptr));

        connect->setText(QApplication::translate("MainWindow", "\350\277\236 \346\216\245", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\350\217\234\345\215\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
