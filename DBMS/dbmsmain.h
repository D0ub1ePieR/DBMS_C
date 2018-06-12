#ifndef DBMSMAIN_H
#define DBMSMAIN_H

#include <QDialog>

namespace Ui {
class dbmsmain;
}

class dbmsmain : public QDialog
{
    Q_OBJECT

public:
    explicit dbmsmain(QWidget *parent = 0);
    ~dbmsmain();

private slots:
	void getindex();

private:
    Ui::dbmsmain *ui;
};

#endif // DBMSMAIN_H
