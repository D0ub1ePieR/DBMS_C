#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setWindowIcon(QIcon(":/image/ball.ico"));
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
