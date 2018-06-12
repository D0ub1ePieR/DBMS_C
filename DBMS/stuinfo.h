#ifndef STUINFO_H
#define STUINFO_H

#include <QDialog>

namespace Ui {
class stuinfo;
}

class stuinfo : public QDialog
{
    Q_OBJECT

public:
    explicit stuinfo(QWidget *parent = 0);
    ~stuinfo();

private:
    Ui::stuinfo *ui;
};

#endif // STUINFO_H
