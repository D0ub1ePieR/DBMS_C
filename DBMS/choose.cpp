#include "choose.h"
#include "ui_choose.h"
#include <string>
#include "mysql.h"
#include <iostream>
#include <QMessageBox>
#include <QString>
#include <QDebug>
using namespace std;

choose::choose(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::choose)
{
	this->setWindowIcon(QIcon(":/image/ball.ico"));
	ui->setupUi(this);
}

//接收主页面跳转
void choose::chooseshow(string number)
{
	this->show();
	this->number = number;
	ui->nowclass->setUpdatesEnabled(true);
	ui->nowclass->clear();
	ui->chooseclass->clear();
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

	MYSQL_RES *res = NULL;
	MYSQL_ROW row = NULL;
	cnn = 0;
	string str = "select cname from sc,class where sc.cnumber=class.cnumber and sc.snumber=\"" + number + "\"";
	if (!mysql_query(&db,str.c_str()))
	{
		res = mysql_store_result(&db);

		row = mysql_fetch_row(res);
		while (row != NULL)
		{
			ui->nowclass->addItem(row[0]);
			row = mysql_fetch_row(res);
		}

	}
	else
	{
		QMessageBox::critical(0, "warning", QStringLiteral("查询失败！"), QMessageBox::Cancel | QMessageBox::Default, 0);
		exit(0);
	}

	str = "select cname,cnumber from class where not exists (select * from sc where class.cnumber=sc.cnumber and sc.snumber=\"" + number + "\")";
	if (!mysql_query(&db, str.c_str()))
	{
		res = mysql_store_result(&db);
		row = mysql_fetch_row(res);
		while (row != NULL)
		{
			ui->chooseclass->addItem(row[0]);
			cn[cnn] = row[0];
			cnumber[cnn++] = row[1];
			row = mysql_fetch_row(res);
		}
	}
	else
	{
		QMessageBox::critical(0, "warning", QStringLiteral("查询失败！"), QMessageBox::Cancel | QMessageBox::Default, 0);
		exit(0);
	}
}

//返回主页面
void choose::on_back_clicked()
{
	this->close();
	emit chooseback();
}

void choose::on_select_clicked()
{
	MYSQL_RES *res = NULL;
	MYSQL_ROW row = NULL;

	if (ui->chooseclass->currentRow()==-1)
		QMessageBox::critical(0, "warning", QStringLiteral("请选择你要选择的课程!"), QMessageBox::Cancel | QMessageBox::Default, 0);
	else
	{
		string classname = cn[ui->chooseclass->currentRow()];
		string str = "select * from sc where sc.snumber=\"" + this->number + "\" and sc.cnumber=(select cprenum from class where class.cname=\"" + classname + "\")";
		qDebug() << QString::fromStdString(str) << endl;
		if (!mysql_query(&db, str.c_str()))
		{
			res = mysql_store_result(&db);
			row = mysql_fetch_row(res);
			if (row == NULL)
			{
				QMessageBox::critical(0, "warning", QStringLiteral("请选择先修课程！"), QMessageBox::Cancel | QMessageBox::Default, 0);
			}
			else
			{
				//qDebug() << row[0] << row[1] << row[2] << endl;
				str = "insert into sc values (\"" + this->number + "\",\"" + cnumber[ui->chooseclass->currentRow()] + "\",NULL)";
				if (!mysql_query(&db, str.c_str()))
				{
					QMessageBox::critical(0, "warning", QStringLiteral("选课成功！"), QMessageBox::Cancel | QMessageBox::Default, 0);
					emit refresh(this->number);
				}
				else
				{
					QMessageBox::critical(0, "warning", QStringLiteral("选课失败！"), QMessageBox::Cancel | QMessageBox::Default, 0);
				}
			}
		}
		else
		{
			QMessageBox::critical(0, "warning", QStringLiteral("查询失败！"), QMessageBox::Cancel | QMessageBox::Default, 0);
			exit(0);
		}
		//qDebug() << QString::fromStdString(str) << endl;
	}
	//qDebug() << ui->chooseclass->currentRow();
}

choose::~choose()
{
    delete ui;
}
