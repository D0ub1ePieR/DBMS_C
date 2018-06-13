#include "dbmsmain.h"
#include "ui_dbmsmain.h"

dbmsmain::dbmsmain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dbmsmain)
{
    ui->setupUi(this);
}

//接收从初始页面传来的信号
void dbmsmain::getindex()
{
	this->show();
}

//跳转至学生信息查询
void dbmsmain::on_info_clicked()
{
	this->close();
	emit goto_stuinfo();
}

//接收学生信息查询返回的信号
void dbmsmain::get_info()
{
	this->show();
}

dbmsmain::~dbmsmain()
{
    delete ui;
}
