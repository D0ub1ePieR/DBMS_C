#include "choose.h"
#include "ui_choose.h"

choose::choose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::choose)
{
	this->setWindowIcon(QIcon(":/image/ball.ico"));
    ui->setupUi(this);
}

void choose::chooseshow()
{
	this->show();
}

void choose::on_back_clicked()
{
	this->close();
	emit chooseback();
}

choose::~choose()
{
    delete ui;
}
