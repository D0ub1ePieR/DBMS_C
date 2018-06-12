#include "mainwindow.h"
#include "dbmsmain.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	MainWindow w;
	dbmsmain dm;
    w.show();

	QObject::connect(&w,SIGNAL(index()),&dm,SLOT(getindex()));

    return a.exec();
}
