#include "inputnum.h"
#include "ui_inputnum.h"
#include <string>
#include <iostream>
#include <mysql.h>
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
	//初始化数据库标识符
	if (mysql_init(&db) != NULL)
		cout << "success1" << endl;
	else
		QMessageBox::critical(0, "warning", QStringLiteral("连接数据库失败!请检查你的网络设置!"), QMessageBox::Cancel | QMessageBox::Default, 0);
	//连接数据库
	if (mysql_real_connect(&db, "111.231.69.100", "double_pier", "dundun", "double_pier", 3306, NULL, 0) != NULL)
		cout << "success" << endl;
	else
		QMessageBox::critical(0, "warning", QStringLiteral("无对应数据库!请核对数据库名!"), QMessageBox::Cancel | QMessageBox::Default, 0);
	//设置文字编码 并没有什么卵用
	if (!mysql_options(&db, MYSQL_SET_CHARSET_NAME, "utf8"))
		cout << "mysql_options() succeed" << endl;
	else
	{
		cout << "mysql_options() failed" << endl;
		return;
	}
}

//确认登录
void inputnum::on_enter_clicked()
{
	if (ui->number->text() != NULL)
	{
		this->close();
		MYSQL_RES *res = NULL;
		MYSQL_ROW row = NULL;
		
		string str = "select * from student where snumber=\"" + ui->number->text().toStdString() + "\"";
		if (!mysql_query(&db, str.c_str()))
		{
			res = mysql_store_result(&db);
			row = mysql_fetch_row(res);
			if (row != NULL)
				emit sendnum(ui->number->text().toStdString());
			else
				QMessageBox::critical(0, "warning", QStringLiteral("无此学号！"), QMessageBox::Cancel | QMessageBox::Default, 0);
		}
	}
	else
		QMessageBox::critical(0, "warning", QStringLiteral("请输入学号！"), QMessageBox::Cancel | QMessageBox::Default, 0);
}

inputnum::~inputnum()
{
    delete ui;
}
