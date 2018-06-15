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

//������ҳ����ת
void choose::chooseshow(string number)
{
	this->show();
	this->number = number;
	ui->nowclass->setUpdatesEnabled(true);
	ui->nowclass->clear();
	ui->chooseclass->clear();
	//��ʼ�����ݿ��ʶ��
	if (mysql_init(&db) != NULL)
		cout << "success1" << endl;
	else
		QMessageBox::critical(0, "warning", QStringLiteral("�������ݿ�ʧ��!���������������!"), QMessageBox::Cancel | QMessageBox::Default, 0);
	//�������ݿ�
	if (mysql_real_connect(&db, "111.231.69.100", "double_pier", "dundun", "double_pier", 3306, NULL, 0) != NULL)
		cout << "success" << endl;
	else
		QMessageBox::critical(0, "warning", QStringLiteral("�޶�Ӧ���ݿ�!��˶����ݿ���!"), QMessageBox::Cancel | QMessageBox::Default, 0);
	//�������ֱ��� ��û��ʲô����
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
		QMessageBox::critical(0, "warning", QStringLiteral("��ѯʧ�ܣ�"), QMessageBox::Cancel | QMessageBox::Default, 0);
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
		QMessageBox::critical(0, "warning", QStringLiteral("��ѯʧ�ܣ�"), QMessageBox::Cancel | QMessageBox::Default, 0);
		exit(0);
	}
}

//������ҳ��
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
		QMessageBox::critical(0, "warning", QStringLiteral("��ѡ����Ҫѡ��Ŀγ�!"), QMessageBox::Cancel | QMessageBox::Default, 0);
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
				QMessageBox::critical(0, "warning", QStringLiteral("��ѡ�����޿γ̣�"), QMessageBox::Cancel | QMessageBox::Default, 0);
			}
			else
			{
				//qDebug() << row[0] << row[1] << row[2] << endl;
				str = "insert into sc values (\"" + this->number + "\",\"" + cnumber[ui->chooseclass->currentRow()] + "\",NULL)";
				if (!mysql_query(&db, str.c_str()))
				{
					QMessageBox::critical(0, "warning", QStringLiteral("ѡ�γɹ���"), QMessageBox::Cancel | QMessageBox::Default, 0);
					emit refresh(this->number);
				}
				else
				{
					QMessageBox::critical(0, "warning", QStringLiteral("ѡ��ʧ�ܣ�"), QMessageBox::Cancel | QMessageBox::Default, 0);
				}
			}
		}
		else
		{
			QMessageBox::critical(0, "warning", QStringLiteral("��ѯʧ�ܣ�"), QMessageBox::Cancel | QMessageBox::Default, 0);
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
