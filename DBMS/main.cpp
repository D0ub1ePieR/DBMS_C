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

	QObject::connect(&w,SIGNAL(index()),&dm,SLOT(getindex()));		//��ʼ������ת����ҳ��
	QObject::connect(&dm, SIGNAL(goto_stuinfo()), &info, SLOT(infoshow()));		//��ҳ����ת��ѧ����Ϣ��ѯҳ��
	QObject::connect(&dm, SIGNAL(goto_stuclass()), &cl, SLOT(classshow()));		//��ҳ����ת��ѧ���γ̲�ѯҳ��
	QObject::connect(&dm, SIGNAL(goto_stuchoose()), &in, SLOT(getmain()));	//��ҳ����ת��ѡ��ҳ��
	QObject::connect(&in, SIGNAL(sendnum(string)), &ch, SLOT(chooseshow(string)));		//ѡ��ϵͳѧ������
	QObject::connect(&ch, SIGNAL(refresh(string)), &ch, SLOT(chooseshow(string)));		//ѡ��ϵͳ�Զ�ˢ��
	QObject::connect(&cf, SIGNAL(configrefresh()), &cf, SLOT(configshow()));		//ϵͳ����ҳ���Զ�ˢ��
	QObject::connect(&dm, SIGNAL(goto_config()), &log, SLOT(login()));			//ϵͳ����ҳ����ת��¼
	QObject::connect(&log, SIGNAL(loginsuccess()), &cf, SLOT(configshow()));	//��ҳ����ת������ϵͳ
	QObject::connect(&info, SIGNAL(infoback()), &dm, SLOT(get_info()));		//ѧ����Ϣ������ת
	QObject::connect(&cl,SIGNAL(classback()),&dm, SLOT(get_grade()));		//ѧ���γ̷�����ת
	QObject::connect(&ch, SIGNAL(chooseback()), &dm, SLOT(get_choose()));	//ѡ�η�����ת
	QObject::connect(&cf, SIGNAL(configback()), &dm, SLOT(get_config()));	//����ϵͳ������ת

    return a.exec();
}
