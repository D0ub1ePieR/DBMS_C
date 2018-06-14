#include "inputnum.h"
#include "ui_inputnum.h"
#include <string>
#include <iostream>
using namespace std;
#include <QMessageBox>

inputnum::inputnum(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inputnum)
{
    ui->setupUi(this);
}

//接收主页面跳转
void inputnum::getmain()
{
	this->show();
}

//确认登录
void inputnum::on_enter_clicked()
{
	if (ui->number->text() != NULL)
	{
		this->close();
		emit sendnum(ui->number->text().toStdString());
	}
	else
		QMessageBox::critical(0, "warning", QStringLiteral("请输入学号！"), QMessageBox::Cancel | QMessageBox::Default, 0);
}

inputnum::~inputnum()
{
    delete ui;
}
