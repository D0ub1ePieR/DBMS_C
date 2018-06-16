#include "config.h"
#include "ui_config.h"
#include <string>
#include "mysql.h"
#include <iostream>
#include <QMessageBox>
#include <QString>
#include <QDebug>
using namespace std;

config::config(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::config)
{
	//this->setWindowIcon(QIcon(":/image/ball.ico"));
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
	if (!mysql_options(&db, MYSQL_SET_CHARSET_NAME, "utf8"))
		cout << "mysql_options() succeed" << endl;
	else
	{
		cout << "mysql_options() failed" << endl;
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
	int inputflag;
	MYSQL_RES *res = NULL;
	MYSQL_ROW row = NULL;
}

config::~config()
{
    delete ui;
}
