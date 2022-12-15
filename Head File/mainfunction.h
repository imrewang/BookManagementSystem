#ifndef MAINFUNCTION_H_INCLUDED
#define MAINFUNCTION_H_INCLUDED
#define _QUIT_ 0
/*
显示欢迎信息
*/
void showwelcome(void);

/*
显示菜单项,返回选择的菜单
*/
short showmenu(void);

/*
显示子菜单项
*/
short showsubmenu(short menu);

/*
功能调用函数,依据菜单选择调用相应的功能函数
*/
void callsubtask(short selected);

#endif // MAINFUNCTION_H_INCLUDED