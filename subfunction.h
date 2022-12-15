#ifndef SUBFUNCTION_H_INCLUDED
#define SUBFUNCTION_H_INCLUDED

#include "datainfo.h"

void mmbook(void);
void listmember(void);

/*
1.¼��ͼ��
*/
int inputbook(void);

/*
2.ɾ��ͼ��
*/
int deletebook(void);

/*
3.��ѯͼ��
*/
int searchbook(void);

/*
4.�޸�ͼ��
*/
int modifybook(void);

/*
5.����ͼ��
*/
int lendbook(void);

/*
6.�黹ͼ��
*/
int returnbook(void);

/*
7.ע���Ա
*/
int inputmember(void);

/*
8.ע����Ա
*/
int deletemember(void);

/*
9.��ѯ��Ա
*/
int searchmember(void);

/*
10.�޸Ļ�Ա
*/
int modifymember(void);

BOOK findbook(char* ISBN);
int removebook(char* ISBN);

MEMBER findmember(char* name);
int removemember(char* name);
int memberborrow(MEMBER member);

int lendbook(BOOK book);

#endif // SUBFUNCTION_H_INCLUDED