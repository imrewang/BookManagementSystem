#ifndef MAINFUNCTION_H_INCLUDED
#define MAINFUNCTION_H_INCLUDED
#define _QUIT_ 0
/*
��ʾ��ӭ��Ϣ
*/
void showwelcome(void);

/*
��ʾ�˵���,����ѡ��Ĳ˵�
*/
short showmenu(void);

/*
��ʾ�Ӳ˵���
*/
short showsubmenu(short menu);

/*
���ܵ��ú���,���ݲ˵�ѡ�������Ӧ�Ĺ��ܺ���
*/
void callsubtask(short selected);

#endif // MAINFUNCTION_H_INCLUDED