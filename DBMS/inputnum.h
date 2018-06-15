#ifndef INPUTNUM_H
#define INPUTNUM_H

#include <string>
#include <iostream>
#include <mysql.h>
using namespace std;
#include <QDialog>

namespace Ui {
class inputnum;
}

class inputnum : public QDialog
{
    Q_OBJECT

public:
    explicit inputnum(QWidget *parent = 0);
    ~inputnum();

private slots:
	void getmain();
	void on_enter_clicked();

signals:
	void sendnum(string number);

private:
    Ui::inputnum *ui;
	MYSQL db;
};

#endif // INPUTNUM_H
