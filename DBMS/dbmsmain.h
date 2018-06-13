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
	void getindex();		//���ճ�ʼҳ���ź�
	void on_info_clicked();
	void get_info();		//����ѧ����Ϣ��ѯ�����ź�

signals:
	void goto_stuinfo();	//��תѧ����Ϣ��ѯ�ź�
	void goto_stuclass();	//��תѧ���γ̲�ѯ�ź�
	void goto_stuchoose();	//��תѡ��ϵͳ�ź�
	void goto_config();		//��ת����ϵͳ�ź�

private:
    Ui::dbmsmain *ui;
};

#endif // DBMSMAIN_H
