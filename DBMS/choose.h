#ifndef CHOOSE_H
#define CHOOSE_H

#include "mysql.h"
#include <string>
#include <iostream>
using namespace std;
#include <QDialog>

namespace Ui {
class choose;
}

class choose : public QDialog
{
    Q_OBJECT

public:
    explicit choose(QWidget *parent = 0);
    ~choose();

private slots:
	void chooseshow(string number);
	void on_back_clicked();
	void on_select_clicked();

signals:
	void chooseback();

private:
    Ui::choose *ui;
	string number;
	MYSQL db;
};

#endif // CHOOSE_H
