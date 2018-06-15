#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include "mysql.h"
#include <iostream>
#include <QMessageBox>
#include <QString>
#include <QDebug>
using namespace std;
#include <QDialog>

namespace Ui {
class config;
}

class config : public QDialog
{
    Q_OBJECT

public:
    explicit config(QWidget *parent = 0);
    ~config();

private slots:
	void configshow();

signals:


private:
    Ui::config *ui;
	MYSQL db;
};

#endif // CONFIG_H
