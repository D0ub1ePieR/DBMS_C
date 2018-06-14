#include "dbmsmain.h"
#include "ui_dbmsmain.h"

dbmsmain::dbmsmain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dbmsmain)
{
	this->setWindowIcon(QIcon(":/image/ball.ico"));
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

//跳转至学生课程查询
void dbmsmain::on_grade_clicked()
{
	this->close();
	emit goto_stuclass();
}

//接收学生课程查询返回额信号
void dbmsmain::get_grade()
{
	this->show();
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
