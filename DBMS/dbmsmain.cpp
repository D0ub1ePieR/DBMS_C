#include "dbmsmain.h"
#include "ui_dbmsmain.h"

dbmsmain::dbmsmain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dbmsmain)
{
	this->setWindowIcon(QIcon(":/image/ball.ico"));
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

//��ת��ѧ���γ̲�ѯ
void dbmsmain::on_grade_clicked()
{
	this->close();
	emit goto_stuclass();
}

//��ת��ѡ��ҳ��
void dbmsmain::on_choose_clicked()
{
	this->close();
	emit goto_stuchoose();
}

//����ѡ�η����ź�
void dbmsmain::get_choose()
{
	this->show();
}

//����ѧ���γ̲�ѯ���ض��ź�
void dbmsmain::get_grade()
{
	this->show();
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
