#include "checklog.h"
#include "ui_checklog.h"
#include <QMessageBox>

checklog::checklog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::checklog)
{
	this->setWindowIcon(QIcon(":/image/ball.ico"));
    ui->setupUi(this);
}

//������ҳ����ת
void checklog::login()
{
	this->show();
}

//��½�ɹ�
void checklog::on_login_clicked()
{
	if (ui->username->text().toStdString() == "admin" && ui->password->text().toStdString() == "admin")
	{
		emit loginsuccess();
		this->close();
	}
	else
		QMessageBox::critical(0, "warning", QStringLiteral("��������ȷ���û���������!"), QMessageBox::Cancel | QMessageBox::Default, 0);
}

checklog::~checklog()
{
    delete ui;
}
