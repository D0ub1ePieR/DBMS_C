#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <windows.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setWindowIcon(QIcon(":/image/ball.ico"));
    ui->setupUi(this);
}

void MainWindow::on_connect_clicked()
{
	this->close();
	emit index();
}

MainWindow::~MainWindow()
{
    delete ui;
}
