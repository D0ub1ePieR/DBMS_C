#include "config.h"
#include "ui_config.h"
#include <string>
#include "mysql.h"
#include <iostream>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QString>
#include <QDebug>
using namespace std;

config::config(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::config)
{
	this->setWindowIcon(QIcon(":/image/ball.ico"));
    ui->setupUi(this);
}

void config::configshow()
{
	this->show();
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
	/*if (!mysql_options(&db, MYSQL_SET_CHARSET_NAME, "utf8"))
		cout << "mysql_options() succeed" << endl;
	else
	{
		cout << "mysql_options() failed" << endl;
		return;
	}*/

	qDebug() << "init success" << endl;

	//��ʾ������Ϣ
	MYSQL_RES *res = NULL;
	MYSQL_ROW row = NULL;
	unsigned int fieldcount;
	int i,rn;
	string str = "select * from student";
	if (!mysql_query(&db, str.c_str()))
	{
		res = mysql_store_result(&db);
		fieldcount = mysql_num_fields(res);
		ui->showtable->setColumnCount(fieldcount);		//���ñ������
		ui->showtable->setRowCount(1);		//���ñ������
		for (i = 0; i < fieldcount; i++)
		{
			//���ñ�ͷ
			ui->showtable->setItem(0, i,new QTableWidgetItem(mysql_fetch_field_direct(res, i)->name));
			ui->showtable->item(0, i)->setTextAlignment(Qt::AlignCenter);
		}
		row = mysql_fetch_row(res);
		rn = 1;
		while (row != NULL)
		{
			ui->showtable->setRowCount(rn + 1);		//��������
			for (i = 0; i < fieldcount; i++)
			{
				//��������
				ui->showtable->setItem(rn, i, new QTableWidgetItem(row[i]));
				//�����ַ�λ�� ����
				ui->showtable->item(rn, i)->setTextAlignment(Qt::AlignCenter);
			}
			rn++;
			row = mysql_fetch_row(res);
		}
	}
	else
	{
		QMessageBox::critical(0, "warning", QStringLiteral("��ѯʧ��!"), QMessageBox::Cancel | QMessageBox::Default, 0);
		return;
	}
}

//������ҳ��
void config::on_back_clicked()
{
	this->close();
	emit configback();
}

//���ѧ��
void config::on_add_clicked()
{
	string number, name, sex, dept, age;
	MYSQL_RES *res = NULL;
	MYSQL_ROW row = NULL;

	if (ui->number->text() != "")
		number = ui->number->text().toStdString();
	else
	{
		QMessageBox::critical(0, "warning", QStringLiteral("������ѧ��ѧ��!"), QMessageBox::Cancel | QMessageBox::Default, 0);
		return;
	}
	if (ui->name->text() != "")
		name = ui->name->text().toStdString();
	else
	{
		QMessageBox::critical(0, "warning", QStringLiteral("������ѧ������!"), QMessageBox::Cancel | QMessageBox::Default, 0);
		return;
	}
	if (ui->dept->text() != "")
		dept = ui->dept->text().toStdString();
	else
	{
		QMessageBox::critical(0, "warning", QStringLiteral("������ѧ��Ժϵ!"), QMessageBox::Cancel | QMessageBox::Default, 0);
		return;
	}
	if (ui->man->isChecked() ^ ui->woman->isChecked())
		if (ui->man->isChecked())
			sex = "M";
		else
			sex = "F";
	else
	{
		QMessageBox::critical(0, "warning", QStringLiteral("������ѧ���Ա�!"), QMessageBox::Cancel | QMessageBox::Default, 0);
		return;
	}
	if (ui->age->text() != "")
		age = ui->age->text().toStdString();
	else
	{
		QMessageBox::critical(0, "warning", QStringLiteral("������ѧ������!"), QMessageBox::Cancel | QMessageBox::Default, 0);
		return;
	}

	string str = "select * from student where snumber=\"" + number + "\" or sname=\"" + name + "\"";
	qDebug() << QString::fromStdString(str) << endl;
	if (!mysql_query(&db, str.c_str()))
	{
		res = mysql_store_result(&db);
		row = mysql_fetch_row(res);
		if (row != NULL)
		{
			QMessageBox::critical(0, "warning", QStringLiteral("���и�ѧ�Ż�������!"), QMessageBox::Cancel | QMessageBox::Default, 0);
			return;
		}
		else
		{
			str = "insert into student values (\"" + number + "\",\"" + name + "\",\"" + sex + "\",\"" + age + "\",\"" + dept + "\")";
			qDebug() << QString::fromStdString(str) << endl;
			if (!mysql_query(&db, str.c_str()))
			{
				QMessageBox::critical(0, "warning", QStringLiteral("��ӳɹ�!"), QMessageBox::Cancel | QMessageBox::Default, 0);
				this->close();
				mysql_close(&db);
				emit configrefresh();
			}
			else
			{
				QMessageBox::critical(0, "warning", QStringLiteral("��ѯʧ��!"), QMessageBox::Cancel | QMessageBox::Default, 0);
				return;
			}
		}
	}
	else
	{
		QMessageBox::critical(0, "warning", QStringLiteral("��ѯʧ��!"), QMessageBox::Cancel | QMessageBox::Default, 0);
		return;
	}
}

//�޸�ѧ����Ϣ
void config::on_fix_clicked()
{
	MYSQL_RES *res = NULL;
	MYSQL_ROW row = NULL;
	qDebug() << ui->showtable->currentRow() << endl;
	int cur_row;
	string number, name, sex, age, dept;
	cur_row = ui->showtable->currentRow();
	if (cur_row==0)
	{
		QMessageBox::critical(0, "warning", QStringLiteral("��ѡ��ϸ������!"), QMessageBox::Cancel | QMessageBox::Default, 0);
		return;
	}
	number = ui->showtable->item(cur_row, 0)->text().toStdString();
	name = ui->showtable->item(cur_row, 1)->text().toStdString();
	sex = ui->showtable->item(cur_row, 2)->text().toStdString();
	age = ui->showtable->item(cur_row, 3)->text().toStdString();
	dept = ui->showtable->item(cur_row, 4)->text().toStdString();
	
}

//ɾ��ѧ����Ϣ
void config::on_delete_clicked()
{
	;
}

config::~config()
{
    delete ui;
}
