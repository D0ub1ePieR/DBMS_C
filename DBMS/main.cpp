#include "mainwindow.h"
#include "dbmsmain.h"
#include "stuinfo.h"
#include "stuclass.h"
#include "choose.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	MainWindow w;
	dbmsmain dm;
	stuinfo info;
	stuclass cl;
	choose ch;
    w.show();

	QObject::connect(&w,SIGNAL(index()),&dm,SLOT(getindex()));		//��ʼ������ת����ҳ��
	QObject::connect(&dm, SIGNAL(goto_stuinfo()), &info, SLOT(infoshow()));		//��ҳ����ת��ѧ����Ϣ��ѯҳ��
	QObject::connect(&dm, SIGNAL(goto_stuclass()), &cl, SLOT(classshow()));		//��ҳ����ת��ѧ���γ̲�ѯҳ��
	QObject::connect(&dm, SIGNAL(goto_stuchoose()), &ch, SLOT(chooseshow()));	//��ҳ����ת��ѡ��ҳ��
	QObject::connect(&dm, SIGNAL(goto_config()), &dm, SLOT(getindex()));
	QObject::connect(&info, SIGNAL(infoback()), &dm, SLOT(get_info()));		//ѧ����Ϣ������ת
	QObject::connect(&cl,SIGNAL(classback()),&dm, SLOT(get_grade()));		//ѧ���γ̷�����ת
	QObject::connect(&ch, SIGNAL(chooseback()), &dm, SLOT(get_choose()));	//ѡ�η�����ת

    return a.exec();
}
