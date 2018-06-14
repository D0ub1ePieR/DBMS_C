#include "stuclass.h"
#include "ui_stuclass.h"
#include <QMessageBox>
#include <QDebug>
#include <QStandardItemModel>
#include<mysql.h>
#include<iostream>
#include<string>
using namespace std;

stuclass::stuclass(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stuclass)
{
	this->setWindowIcon(QIcon(":/image/ball.ico"));
    ui->setupUi(this);
}

void stuclass::classshow()
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
	MYSQL_RES *res = NULL;
	MYSQL_ROW row = NULL;
	string str = "select cname from class,sc where class.cnumber=sc.cnumber group by cname";
	if (!mysql_query(&db, str.c_str()))
	{
		res = mysql_store_result(&db);
		row = mysql_fetch_row(res);
		while (row != NULL)
		{
			ui->choice->addItem(row[0]);
			row = mysql_fetch_row(res);
		}
	}
	qDebug() << "create success" << endl;
}

void stuclass::on_query_clicked()
{
	int inputflag = 0;
	int i, rn;
	unsigned int fieldcount = 5;
	string str, qstr = "";

	//��ѧ�Ų�ѯѡ��
	if (ui->number->text() != "")
	{
		qstr += " and snumber=\"" + ui->number->text().toStdString() + "\"";
		inputflag = 1;
	}
	//���γ̲�ѯѡ��
	if (ui->choice->currentIndex() != 0)
	{
		inputflag = 1;
		if (ui->choice->currentIndex() != 1)
			qstr += " and cname=\"" + ui->choice->currentText().toStdString() + "\"";
	}

	if (inputflag)
	{
		str = "select snumber,sc.cnumber,cname,grade,ccredit from sc,class where class.cnumber=sc.cnumber" + qstr;
		MYSQL_RES *res = NULL;
		MYSQL_ROW row = NULL;

		if (!mysql_query(&db, str.c_str()))
		{
			QStandardItemModel *model = new QStandardItemModel();
			res = mysql_store_result(&db);
			
			model->setColumnCount(fieldcount);
			for (i = 0; i < fieldcount; i++)
				model->setHeaderData(i, Qt::Horizontal, QString::fromLocal8Bit(mysql_fetch_field_direct(res, i)->name));

			row = mysql_fetch_row(res);
			rn = 0;
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

void stuclass::on_back_clicked()
{
	this->close();
	emit classback();
}

stuclass::~stuclass()
{
    delete ui;
}
