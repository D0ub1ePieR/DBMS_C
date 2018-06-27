#include "mainwindow.h"
#include "dbmsmain.h"
#include "stuinfo.h"
#include "stuclass.h"
#include "choose.h"
#include "inputnum.h"
#include "config.h"
#include "checklog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	MainWindow w;
	dbmsmain dm;
	stuinfo info;
	stuclass cl;
	inputnum in;
	choose ch;
	checklog log;
	config cf;
    w.show();

	QObject::connect(&w,SIGNAL(index()),&dm,SLOT(getindex()));		//初始窗口跳转至主页面
	QObject::connect(&dm, SIGNAL(goto_stuinfo()), &info, SLOT(infoshow()));		//主页面跳转至学生信息查询页面
	QObject::connect(&dm, SIGNAL(goto_stuclass()), &cl, SLOT(classshow()));		//主页面跳转至学生课程查询页面
	QObject::connect(&dm, SIGNAL(goto_stuchoose()), &in, SLOT(getmain()));	//主页面跳转至选课页面
	QObject::connect(&in, SIGNAL(sendnum(string)), &ch, SLOT(chooseshow(string)));		//选课系统学号输入
	QObject::connect(&ch, SIGNAL(refresh(string)), &ch, SLOT(chooseshow(string)));		//选课系统自动刷新
	QObject::connect(&cf, SIGNAL(configrefresh()), &cf, SLOT(configshow()));		//系统管理页面自动刷新
	QObject::connect(&dm, SIGNAL(goto_config()), &log, SLOT(login()));			//系统管理页面跳转登录
	QObject::connect(&log, SIGNAL(loginsuccess()), &cf, SLOT(configshow()));	//主页面跳转至管理系统
	QObject::connect(&info, SIGNAL(infoback()), &dm, SLOT(get_info()));		//学生信息返回跳转
	QObject::connect(&cl,SIGNAL(classback()),&dm, SLOT(get_grade()));		//学生课程返回跳转
	QObject::connect(&ch, SIGNAL(chooseback()), &dm, SLOT(get_choose()));	//选课返回跳转
	QObject::connect(&cf, SIGNAL(configback()), &dm, SLOT(get_config()));	//管理系统返回跳转

    return a.exec();
}
