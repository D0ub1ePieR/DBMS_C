#include "dbmsmain.h"
#include "ui_dbmsmain.h"

dbmsmain::dbmsmain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dbmsmain)
{
    ui->setupUi(this);
}

void dbmsmain::getindex()
{
	this->show();
}

dbmsmain::~dbmsmain()
{
    delete ui;
}
