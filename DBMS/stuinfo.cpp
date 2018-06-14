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

//������ҳ����ת�ź�
void stuinfo::infoshow()
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
	if (!mysql_options(&db, MYSQL_SET_CHARSET_NAME, "utf8")) 
		cout << "mysql_options() succeed" << endl;
	else
	{
		cout << "mysql_options() failed" << endl;
		return;
	}
	qDebug() << "create success" << endl;
}

//���ͷ����ź�
void stuinfo::on_back_clicked()
{
	this->close();
	emit infoback();
}

//��ѯ��ť
void stuinfo::on_query_clicked()
{
	int inputflag = 0;		//�Ƿ�ѡ���˲�ѯѡ��
	int i,rn;
	unsigned int fieldcount;
	string str,qstr="";
	//У���û�ѡ��Ĳ�ѯ��Ϣ
	if (ui->name->text() != "")
	{
		//��ѧ����������
		qstr += " sname=\"" + ui->name->text().toStdString() + "\"";
		inputflag = 1;
	}
	if (ui->number->text() != "")
	{
		//��ѧ��ѧ�Ų���
		if (inputflag)
			qstr += " and";
		qstr += " snumber=" + ui->number->text().toStdString();
		inputflag = 1;
	}
	if (ui->dept->text() != "")
	{
		//��ѧ��Ժϵ����
		if (inputflag)
			qstr += " and";
		qstr += " sdept=\"" + ui->dept->text().toStdString() + "\"";
		inputflag = 1;
	}
	if (ui->man->isChecked() ^ ui->woman->isChecked())
	{
		//����ѧ���Ա����
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
		//�����ѯsql���
		str = "select * from student where" + qstr;
		qDebug() << QString::fromStdString(str) << endl;
		MYSQL_RES *res = NULL;		//��ѯ���ؽ��ʵ��
		MYSQL_ROW row = NULL;
									//����sql��ѯ����
		if (!mysql_query(&db, str.c_str()))
		{
			QStandardItemModel *model = new QStandardItemModel();		//�����������
			qDebug() << "select success " << endl;
			res = mysql_store_result(&db);		//��ȡ�������
			fieldcount = mysql_num_fields(res);		//��ȡ������Ը���
			
			//���ñ��̧ͷ
			model->setColumnCount(fieldcount);		
			for (i = 0; i < fieldcount; i++)
				model->setHeaderData(i, Qt::Horizontal, QString::fromLocal8Bit(mysql_fetch_field_direct(res, i)->name));

			qDebug() << mysql_num_rows(res) << endl;
			row = mysql_fetch_row(res);
			rn = 0;		//��¼�к�
			//���л�ȡ������������
			while (row != NULL)
			{
				for (i = 0; i < fieldcount; i++)
				{
					qDebug() << row[i] << endl;
					//��������
					model->setItem(rn, i, new QStandardItem(row[i]));
					//�����ַ���ɫ ��ɫ
					model->item(rn, 0)->setForeground(QBrush(QColor(255, 0, 0)));
					//�����ַ�λ�� ����
					model->item(rn, i)->setTextAlignment(Qt::AlignCenter);
				}
				rn++;
				row = mysql_fetch_row(res);
			}
			//���ñ�񲻿ɱ༭��Ӧ�ñ������
			ui->showtable->setEditTriggers(QAbstractItemView::NoEditTriggers);
			ui->showtable->setModel(model);
		}
		else
		{
			QMessageBox::critical(0, "warning", QStringLiteral("��ѯʧ�ܣ�"), QMessageBox::Cancel | QMessageBox::Default, 0);
		}
	}
	else
	{
		//�û�δѡ���ѯѡ��
		QMessageBox::critical(0, "warning", QStringLiteral("��ѡ����Ҫ���ҵ�����!"), QMessageBox::Cancel | QMessageBox::Default, 0);
	}
}

stuinfo::~stuinfo()
{
    delete ui;
}
