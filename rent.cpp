//#include "stdafx.h"
#include <iostream>
#include "mainfunction.h"

int main()
{
    short selected = 0;
    short selectedsub = 0;
    //��ʾ��ӭ��Ϣ
    showwelcome();
    do {
        selected = showmenu();//��ʾ�˵���
        do {
            selectedsub = showsubmenu(selected);//��ʾ�Ӳ˵���
            callsubtask(selectedsub);//���ܵ��ú���,���ݲ˵�ѡ�������Ӧ�Ĺ��ܺ���
        } while (selectedsub != _QUIT_);
    } while (selected != _QUIT_);
    return 0;
}