#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <windows.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
	//���ô���ͼ��
    this->setWindowIcon(QIcon(":/image/ball.ico"));
    ui->setupUi(this);
}

void MainWindow::on_connect_clicked()
{
	if (0)
	{
		//δѡ������Դ
		QMessageBox::critical(0,"warning", QStringLiteral("��ѡ�������ӵ�����Դ"),QMessageBox::Cancel | QMessageBox::Default, 0);
	}
	else
	{
		//����ѡ�������Դ���رմ�����ת��dbms��ҳ��
		this->close();
		emit index();
	}
}

MainWindow::~MainWindow()
{
    delete ui;
}
