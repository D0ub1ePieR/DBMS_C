#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <windows.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
	//设置窗口图标
    this->setWindowIcon(QIcon(":/image/ball.ico"));
    ui->setupUi(this);
}

void MainWindow::on_connect_clicked()
{
	if (0)
	{
		//未选择数据源
		QMessageBox::critical(0,"warning", QStringLiteral("请选择你连接的数据源"),QMessageBox::Cancel | QMessageBox::Default, 0);
	}
	else
	{
		//连接选择的数据源，关闭窗口跳转至dbms主页面
		this->close();
		emit index();
	}
}

MainWindow::~MainWindow()
{
    delete ui;
}
