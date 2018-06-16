#ifndef CHECKLOG_H
#define CHECKLOG_H

#include <QDialog>

namespace Ui {
class checklog;
}

class checklog : public QDialog
{
    Q_OBJECT

public:
    explicit checklog(QWidget *parent = 0);
    ~checklog();

private slots:
	void login();
	void on_login_clicked();

signals:
	void loginsuccess();

private:
    Ui::checklog *ui;
};

#endif // CHECKLOG_H
