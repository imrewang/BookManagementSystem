//#include "stdafx.h"
#include <iostream>
#include "mainfunction.h"
#include "subfunction.h"

using namespace std;
/*
��ʾ��ӭ��Ϣ
*/
void showwelcome(void)
{
    cout << "*********************************" << endl;
    cout << "*��ӭʹ��BookManagerͼ�����ϵͳ*" << endl;
    cout << "*          �汾 ��2022          *" << endl;
    cout << "*********************************" << endl;
}

/*
��ʾ�˵���,����ѡ��Ĳ˵�
*/
short showmenu(void)
{
    short selected = 0;
    //ѡ��ģ��
    cout << "��ѡ����Ҫʹ�õ�ģ�飺" << endl;
    cout << "1--ͼ��ά��" << endl;
    cout << "2--ͼ�����" << endl;
    cout << "3--��Աά��" << endl;
    cout << "0--�˳�" << endl;
    cout << "��ѡ��";
    cin >> selected;
    while (selected > 3 || selected < 0)
    {
        cout << "ѡ���������ѡ:";
        cin >> selected;
    }
    return selected;
}

/*
��ʾ�Ӳ˵���
*/
short showsubmenu(short menu)
{
    int selected = 0;
    switch (menu)
    {
    case 1:
        cout << "     ͼ��ά��" << endl;
        cout << "��ѡ����Ҫִ�еĹ��ܣ�" << endl;
        cout << "1--¼��" << endl;
        cout << "2--ɾ��" << endl;
        cout << "3--��ѯ" << endl;
        cout << "4--�޸�" << endl;
        cout << "5--�б�" << endl;
        cout << "0--�˳�" << endl;
        cout << "��ѡ��";
        cin >> selected;
        while (selected > 5 || selected < 0)
        {
            cout << "ѡ���������ѡ:";
            cin >> selected;
        }
        break;
    case 2:
        cout << "     ͼ�����" << endl;
        cout << "��ѡ����Ҫִ�еĹ��ܣ�" << endl;
        cout << "1--����" << endl;
        cout << "2--����" << endl;
        cout << "0--�˳�" << endl;
        cout << "��ѡ��";
        cin >> selected;
        while (selected > 2 || selected < 0)
        {
            cout << "ѡ���������ѡ:";
            cin >> selected;
        }
        if (selected != _QUIT_)
            selected += 5;
        break;
    case 3:
        cout << "     ��Աά��" << endl;
        cout << "��ѡ����Ҫִ�еĹ��ܣ�" << endl;
        cout << "1--ע��" << endl;
        cout << "2--ע��" << endl;
        cout << "3--��ѯ" << endl;
        cout << "4--�޸�" << endl;
        cout << "5--�б�" << endl;
        cout << "0--�˳�" << endl;
        cout << "��ѡ��";
        cin >> selected;
        while (selected > 5 || selected < 0)
        {
            cout << "ѡ���������ѡ:";
            cin >> selected;
        }
        if (selected != _QUIT_)
            selected += 7;
        break;
    default:
        selected = _QUIT_;
    }
    return selected;
}

/*
���ܵ��ú���,���ݲ˵�ѡ�������Ӧ�Ĺ��ܺ���
*/
void callsubtask(short selected)
{
    int rtn;
    switch (selected)
    {
    case 1:
        rtn = inputbook();
        break;
    case 2:
        rtn = deletebook();
        break;
    case 3:
        rtn = searchbook();
        break;
    case 4:
        rtn = modifybook();
        break;
    case 5:
        mmbook();
        break;
    case 6:
        rtn = lendbook();
        break;
    case 7:
        rtn = returnbook();
        break;
    case 8:
        rtn = inputmember();
        break;
    case 9:
        rtn = deletemember();
        break;
    case 10:
        rtn = searchmember();
        break;
    case 11:
        rtn = modifymember();
        break;
    case 12:
        listmember();
        break;
    }
}




