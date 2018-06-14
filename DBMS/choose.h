#ifndef CHOOSE_H
#define CHOOSE_H

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
	void chooseshow();
	void on_back_clicked();

signals:
	void chooseback();

private:
    Ui::choose *ui;
};

#endif // CHOOSE_H
