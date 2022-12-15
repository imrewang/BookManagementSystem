#ifndef SUBFUNCTION_H_INCLUDED
#define SUBFUNCTION_H_INCLUDED

#include "datainfo.h"

void mmbook(void);
void listmember(void);

/*
1.录入图书
*/
int inputbook(void);

/*
2.删除图书
*/
int deletebook(void);

/*
3.查询图书
*/
int searchbook(void);

/*
4.修改图书
*/
int modifybook(void);

/*
5.借阅图书
*/
int lendbook(void);

/*
6.归还图书
*/
int returnbook(void);

/*
7.注册会员
*/
int inputmember(void);

/*
8.注销会员
*/
int deletemember(void);

/*
9.查询会员
*/
int searchmember(void);

/*
10.修改会员
*/
int modifymember(void);

BOOK findbook(char* ISBN);
int removebook(char* ISBN);

MEMBER findmember(char* name);
int removemember(char* name);
int memberborrow(MEMBER member);

int lendbook(BOOK book);

#endif // SUBFUNCTION_H_INCLUDED