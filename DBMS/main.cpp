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

	QObject::connect(&w,SIGNAL(index()),&dm,SLOT(getindex()));		//��ʼ������ת����ҳ��
	QObject::connect(&dm, SIGNAL(goto_stuinfo()), &info, SLOT(infoshow()));		//��ҳ����ת��ѧ����Ϣ��ѯҳ��
	QObject::connect(&dm, SIGNAL(goto_stuclass()), &dm, SLOT(getindex()));
	QObject::connect(&dm, SIGNAL(goto_stuchoose()), &dm, SLOT(getindex())); 
	QObject::connect(&dm, SIGNAL(goto_config()), &dm, SLOT(getindex()));
	QObject::connect(&info, SIGNAL(infoback()), &dm, SLOT(get_info()));		//ѧ����Ϣ������ת

    return a.exec();
}
