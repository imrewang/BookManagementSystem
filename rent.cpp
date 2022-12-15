//#include "stdafx.h"
#include <iostream>
#include "mainfunction.h"

int main()
{
    short selected = 0;
    short selectedsub = 0;
    //显示欢迎信息
    showwelcome();
    do {
        selected = showmenu();//显示菜单项
        do {
            selectedsub = showsubmenu(selected);//显示子菜单项
            callsubtask(selectedsub);//功能调用函数,依据菜单选择调用相应的功能函数
        } while (selectedsub != _QUIT_);
    } while (selected != _QUIT_);
    return 0;
}