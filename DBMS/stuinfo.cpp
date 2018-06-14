#include "stuinfo.h"
#include "ui_stuinfo.h"
#include <QMessageBox>
#include <QDebug>
#include <QStandardItemModel>
#include<mysql.h>
#include<iostream>
#include<string>
using namespace std;

stuinfo::stuinfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stuinfo)
{
    ui->setupUi(this);
}

//接收主页面跳转信号
void stuinfo::infoshow()
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
	qDebug() << "create success" << endl;
}

//发送返回信号
void stuinfo::on_back_clicked()
{
	this->close();
	emit infoback();
}

//查询按钮
void stuinfo::on_query_clicked()
{
	int inputflag = 0;		//是否选择了查询选项
	int i,rn;
	unsigned int fieldcount;
	string str,qstr="";
	//校验用户选择的查询信息
	if (ui->name->text() != "")
	{
		//按学生姓名查找
		qstr += " sname=\"" + ui->name->text().toStdString() + "\"";
		inputflag = 1;
	}
	if (ui->number->text() != "")
	{
		//按学生学号查找
		if (inputflag)
			qstr += " and";
		qstr += " snumber=" + ui->number->text().toStdString();
		inputflag = 1;
	}
	if (ui->dept->text() != "")
	{
		//按学生院系查找
		if (inputflag)
			qstr += " and";
		qstr += " sdept=\"" + ui->dept->text().toStdString() + "\"";
		inputflag = 1;
	}
	if (ui->man->isChecked() ^ ui->woman->isChecked())
	{
		//按照学生性别查找
		if (inputflag)
			qstr += " and";
		if (ui->man->isChecked())
			qstr += " ssex=\"M\"";
		if (ui->woman->isChecked())
			qstr += " ssex=\"F\"";
		inputflag = 1;
	}
	if (inputflag)
	{
		//构造查询sql语句
		str = "select * from student where" + qstr;
		qDebug() << QString::fromStdString(str) << endl;
		MYSQL_RES *res = NULL;		//查询返回结果实体
		MYSQL_ROW row = NULL;
									//发送sql查询请求
		if (!mysql_query(&db, str.c_str()))
		{
			QStandardItemModel *model = new QStandardItemModel();		//表格设置属性
			qDebug() << "select success " << endl;
			res = mysql_store_result(&db);		//获取结果返回
			fieldcount = mysql_num_fields(res);		//获取表的属性个数
			
			//设置表格抬头
			model->setColumnCount(fieldcount);		
			for (i = 0; i < fieldcount; i++)
				model->setHeaderData(i, Qt::Horizontal, QString::fromLocal8Bit(mysql_fetch_field_direct(res, i)->name));

			qDebug() << mysql_num_rows(res) << endl;
			row = mysql_fetch_row(res);
			rn = 0;		//记录行号
			//逐行获取数据添加至表格
			while (row != NULL)
			{
				for (i = 0; i < fieldcount; i++)
				{
					qDebug() << row[i] << endl;
					//设置文字
					model->setItem(rn, i, new QStandardItem(row[i]));
					//设置字符颜色 红色
					model->item(rn, 0)->setForeground(QBrush(QColor(255, 0, 0)));
					//设置字符位置 居中
					model->item(rn, i)->setTextAlignment(Qt::AlignCenter);
				}
				rn++;
				row = mysql_fetch_row(res);
			}
			//设置表格不可编辑，应用表格属性
			ui->showtable->setEditTriggers(QAbstractItemView::NoEditTriggers);
			ui->showtable->setModel(model);
		}
		else
		{
			QMessageBox::critical(0, "warning", QStringLiteral("查询失败！"), QMessageBox::Cancel | QMessageBox::Default, 0);
		}
	}
	else
	{
		//用户未选择查询选项
		QMessageBox::critical(0, "warning", QStringLiteral("请选择你要查找的数据!"), QMessageBox::Cancel | QMessageBox::Default, 0);
	}
}

stuinfo::~stuinfo()
{
    delete ui;
}
