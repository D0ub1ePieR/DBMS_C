#include "stuinfo.h"
#include "ui_stuinfo.h"
#include <QMessageBox>
#include <QDebug>
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
	string str,qstr="";
	MYSQL db;
	//��ʼ�����ݿ��ʶ��
	if (mysql_init(&db) != NULL)
		cout << "success1" << endl;
	else
		QMessageBox::critical(0, "warning", QStringLiteral("�������ݿ�ʧ��!���������������!"), QMessageBox::Cancel | QMessageBox::Default, 0);
	//�������ݿ�
	if (mysql_real_connect(&db, "111.231.69.100", "double_pier", "dundun", "double_pier", 3306, NULL, 0) != NULL)
		cout << "success" << endl;
	else
		QMessageBox::critical(0, "warning", QStringLiteral("�޶�Ӧ���ݿ�!��˶����ݿ���!"), QMessageBox::Cancel | QMessageBox::Default, 0);;
	//У���û�ѡ��Ĳ�ѯ��Ϣ
	if (ui->name->text() != "")
	{
		//��ѧ����������
		qstr+="sname="+ui->name->text().toStdString();
		inputflag = 1;
	}
	if (ui->number->text() != "")
	{
		//��ѧ��ѧ�Ų���
		qstr += "snumber=" + ui->number->text().toStdString();
		inputflag = 1;
	}
	if (ui->dept->text() != "")
	{
		//��ѧ��Ժϵ����
		qstr += "sdept=" + ui->dept->text().toStdString();
		inputflag = 1;
	}
	if (ui->man->isChecked() ^ ui->woman->isChecked())
	{
		//����ѧ���Ա����
		if (ui->man->isChecked())
			qstr += "ssex=M";
		if (ui->woman->isChecked())
			qstr += "ssex=F";
		inputflag = 1;
	}
	if (inputflag)
	{
		//�����ѯsql���
		str = "select * from student where " + qstr;
		qDebug() << QString::fromStdString(str) << endl;
		MYSQL_RES *res = NULL;		//��ѯ���ؽ��ʵ��
		//����sql��ѯ����
		if (!mysql_query(&db, str.c_str()))
		{
			qDebug() << "select success " << endl;
			res = mysql_store_result(&db);
			qDebug() << "row :" << mysql_num_rows(res);
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
