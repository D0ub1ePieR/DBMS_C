#include "stuinfo.h"
#include "ui_stuinfo.h"

stuinfo::stuinfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stuinfo)
{
    ui->setupUi(this);
}

stuinfo::~stuinfo()
{
    delete ui;
}
