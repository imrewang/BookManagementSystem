//#include "stdafx.h"
#include <iostream>
#include "mainfunction.h"
#include "subfunction.h"

using namespace std;
/*
显示欢迎信息
*/
void showwelcome(void)
{
    cout << "*********************************" << endl;
    cout << "*欢迎使用BookManager图书管理系统*" << endl;
    cout << "*          版本 ：2022          *" << endl;
    cout << "*********************************" << endl;
}

/*
显示菜单项,返回选择的菜单
*/
short showmenu(void)
{
    short selected = 0;
    //选择模块
    cout << "请选择你要使用的模块：" << endl;
    cout << "1--图书维护" << endl;
    cout << "2--图书借阅" << endl;
    cout << "3--会员维护" << endl;
    cout << "0--退出" << endl;
    cout << "请选择：";
    cin >> selected;
    while (selected > 3 || selected < 0)
    {
        cout << "选择错误！请重选:";
        cin >> selected;
    }
    return selected;
}

/*
显示子菜单项
*/
short showsubmenu(short menu)
{
    int selected = 0;
    switch (menu)
    {
    case 1:
        cout << "     图书维护" << endl;
        cout << "请选择你要执行的功能：" << endl;
        cout << "1--录入" << endl;
        cout << "2--删除" << endl;
        cout << "3--查询" << endl;
        cout << "4--修改" << endl;
        cout << "5--列表" << endl;
        cout << "0--退出" << endl;
        cout << "请选择：";
        cin >> selected;
        while (selected > 5 || selected < 0)
        {
            cout << "选择错误！请重选:";
            cin >> selected;
        }
        break;
    case 2:
        cout << "     图书借阅" << endl;
        cout << "请选择你要执行的功能：" << endl;
        cout << "1--借阅" << endl;
        cout << "2--返还" << endl;
        cout << "0--退出" << endl;
        cout << "请选择：";
        cin >> selected;
        while (selected > 2 || selected < 0)
        {
            cout << "选择错误！请重选:";
            cin >> selected;
        }
        if (selected != _QUIT_)
            selected += 5;
        break;
    case 3:
        cout << "     会员维护" << endl;
        cout << "请选择你要执行的功能：" << endl;
        cout << "1--注册" << endl;
        cout << "2--注销" << endl;
        cout << "3--查询" << endl;
        cout << "4--修改" << endl;
        cout << "5--列表" << endl;
        cout << "0--退出" << endl;
        cout << "请选择：";
        cin >> selected;
        while (selected > 5 || selected < 0)
        {
            cout << "选择错误！请重选:";
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
功能调用函数,依据菜单选择调用相应的功能函数
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




