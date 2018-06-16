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

//接收主页面跳转
void checklog::login()
{
	this->show();
}

//登陆成功
void checklog::on_login_clicked()
{
	if (ui->username->text().toStdString() == "admin" && ui->password->text().toStdString() == "admin")
	{
		emit loginsuccess();
		this->close();
	}
	else
		QMessageBox::critical(0, "warning", QStringLiteral("请输入正确的用户名和密码!"), QMessageBox::Cancel | QMessageBox::Default, 0);
}

checklog::~checklog()
{
    delete ui;
}
