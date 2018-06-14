#include "choose.h"
#include "ui_choose.h"
#include <string>
#include "mysql.h"
#include <iostream>
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
void choose::on_back_clicked()
{
	this->close();
	emit chooseback();
}

void choose::on_select_clicked()
{
	;
}

choose::~choose()
{
    delete ui;
}
