#include "mainwindow.h"
#include "dbmsmain.h"
#include "stuinfo.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	MainWindow w;
	dbmsmain dm;
	stuinfo info;
    w.show();

	QObject::connect(&w,SIGNAL(index()),&dm,SLOT(getindex()));		//初始窗口跳转至主页面
	QObject::connect(&dm, SIGNAL(goto_stuinfo()), &info, SLOT(infoshow()));		//主页面跳转至学生信息查询页面
	QObject::connect(&dm, SIGNAL(goto_stuclass()), &dm, SLOT(getindex()));
	QObject::connect(&dm, SIGNAL(goto_stuchoose()), &dm, SLOT(getindex())); 
	QObject::connect(&dm, SIGNAL(goto_config()), &dm, SLOT(getindex()));
	QObject::connect(&info, SIGNAL(infoback()), &dm, SLOT(get_info()));		//学生信息返回跳转

    return a.exec();
}
