#include "inputnum.h"
#include "ui_inputnum.h"
#include <string>
#include <iostream>
using namespace std;
#include <QMessageBox>

inputnum::inputnum(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inputnum)
{
    ui->setupUi(this);
}

//������ҳ����ת
void inputnum::getmain()
{
	this->show();
}

//ȷ�ϵ�¼
void inputnum::on_enter_clicked()
{
	if (ui->number->text() != NULL)
	{
		this->close();
		emit sendnum(ui->number->text().toStdString());
	}
	else
		QMessageBox::critical(0, "warning", QStringLiteral("������ѧ�ţ�"), QMessageBox::Cancel | QMessageBox::Default, 0);
}

inputnum::~inputnum()
{
    delete ui;
}
