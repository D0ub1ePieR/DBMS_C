#ifndef STUINFO_H
#define STUINFO_H

#include <QDialog>
#include<mysql.h>
#include<iostream>
#include<string>
using namespace std;

namespace Ui {
class stuinfo;
}

class stuinfo : public QDialog
{
    Q_OBJECT

public:
    explicit stuinfo(QWidget *parent = 0);
    ~stuinfo();

private slots:
	void infoshow();			//������ҳ����ת
	void on_query_clicked();	
	void on_back_clicked();

signals:
	void infoback();			//���ͷ����ź�

private:
    Ui::stuinfo *ui;
	MYSQL db;
};

#endif // STUINFO_H
