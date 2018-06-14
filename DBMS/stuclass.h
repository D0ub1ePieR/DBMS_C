#ifndef STUCLASS_H
#define STUCLASS_H
#include <QDialog>
#include<mysql.h>
#include<iostream>
#include<string>
using namespace std;

namespace Ui {
class stuclass;
}

class stuclass : public QDialog
{
    Q_OBJECT

public:
    explicit stuclass(QWidget *parent = 0);
    ~stuclass();

private slots:
	void classshow();
	void on_back_clicked();

signals:
	void classback();

private:
    Ui::stuclass *ui;
	MYSQL db;
};

#endif // STUCLASS_H
