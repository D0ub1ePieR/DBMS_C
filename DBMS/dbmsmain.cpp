#include "dbmsmain.h"
#include "ui_dbmsmain.h"

dbmsmain::dbmsmain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dbmsmain)
{
    ui->setupUi(this);
}

//���մӳ�ʼҳ�洫�����ź�
void dbmsmain::getindex()
{
	this->show();
}

//��ת��ѧ����Ϣ��ѯ
void dbmsmain::on_info_clicked()
{
	this->close();
	emit goto_stuinfo();
}

//����ѧ����Ϣ��ѯ���ص��ź�
void dbmsmain::get_info()
{
	this->show();
}

dbmsmain::~dbmsmain()
{
    delete ui;
}
