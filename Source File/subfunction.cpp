//#include "stdafx.h"
#include <iostream>
#include "subfunction.h"


using namespace std;
const char* _DATA_FILE_ = "book.dat";
const char* _TEMP_FILE_ = "book.tmp";
const char* _MEMBER_FILE_ = "member.dat";

void listbook(void)
{
    FILE* fp;
    BOOK bk;
    //fp = fopen(_DATA_FILE_, "rb");
    errno_t err = fopen_s(&fp, _DATA_FILE_, "rb");
    cout << "ISBN   name   publisher    author   ver   price   count" << endl;
    fread(&bk, sizeof(bk), 1, fp);
    while (!feof(fp))
    {
        cout << bk.isbn << "  " << bk.name << "  " << bk.publisher << "  " << bk.author << "  " << bk.ver << "  " << bk.price << "  " << bk.count << endl;
        fread(&bk, sizeof(bk), 1, fp);
    }
    fclose(fp);
}

void listmember(void)
{
    FILE* fp;
    MEMBER member;
    //fp = fopen(_MEMBER_FILE_, "rb");
    errno_t err = fopen_s(&fp, _MEMBER_FILE_, "rb");
    cout << "����   ��ַ   ������    isbn1   isbn2   isbn3" << endl;
    fread(&member, sizeof(member), 1, fp);
    while (!feof(fp))
    {
        cout << member.name << "  " << member.address << "  " << member.borrow << "  " << member.isbn1 << "  " << member.isbn2 << "  " << member.isbn3 << endl;
        fread(&member, sizeof(member), 1, fp);
    }
    fclose(fp);
}


/*
1.¼��ͼ��
*/
int inputbook(void)
{
    int rtn = 1;
    BOOK book;
    char check = 'n';
    FILE* fp;
    //fp = fopen(_DATA_FILE_, "ab");/*׷�ӷ�ʽ���ļ�*/
    errno_t err = fopen_s(&fp, _DATA_FILE_, "ab");
    if (fp == NULL)
        //fp = fopen(_DATA_FILE_, "wb"); /*д��ʽ���ļ�*/
        err = fopen_s(&fp, _DATA_FILE_, "wb");
    if (fp == NULL)
        rtn = 0;
    else
    {
        do {
            cout << "¼��ͼ��" << endl;
            cout << "ISBN--";
            cin >> book.isbn;
            cout << "����--";
            cin >> book.name;
            cout << "������--";
            cin >> book.publisher;
            cout << "����--";
            cin >> book.author;
            cout << "���--";
            cin >> book.ver;
            cout << "�۸�--";
            cin >> book.price;
            cout << "���--";
            cin >> book.count;
            cout << "ȷ�ϱ���(y/n):";
            cin >> check;
            if (check = 'y')
            {
                fwrite(&book, sizeof(book), 1, fp);/*��д*/
            }
            cout << "����¼����(y/n)";
            cin >> check;
        } while (check != 'n');
    }
    fclose(fp);
    return rtn;
}


/*
��ѯͼ��
*/
BOOK findbook(char* ISBN)
{
    BOOK book;
    bool found = false;
    FILE* fp;
    //fp = fopen(_DATA_FILE_, "rb");/*����ʽ���ļ�*/
    errno_t err = fopen_s(&fp, _DATA_FILE_, "rb");
    book.count = -1;
    if (fp != NULL)
    {
        //fseek(fp,0,SEEK_SET);
        fread(&book, sizeof(book), 1, fp);
        while (!feof(fp))
        {
            if (!strcmp(book.isbn, ISBN))
            {
                found = true;
                break;
            }
            fread(&book, sizeof(book), 1, fp);
        }
        if (!found)
            book.count = -1;
        fclose(fp);
    }
    return book;
}

int removebook(char* ISBN)
{
    BOOK book;
    FILE* fp;
    FILE* temp;
    //temp = fopen(_TEMP_FILE_, "w");/*д��ʽ���ļ�*/
    errno_t err = fopen_s(&temp, _TEMP_FILE_, "w");
    //fp = fopen(_DATA_FILE_, "rb");/*����ʽ���ļ�*/
    err = fopen_s(&fp, _DATA_FILE_, "rb");
    if (fp != NULL)
    {
        fread(&book, sizeof(book), 1, fp);
        while (!feof(fp))
        {
            if (strcmp(book.isbn, ISBN))
            {
                fwrite(&book, sizeof(book), 1, temp);/*��д*/
            }
            fread(&book, sizeof(book), 1, fp);
        }
        fclose(fp);
        fclose(temp);
        remove(_DATA_FILE_);
        rename(_TEMP_FILE_, _DATA_FILE_);
    }
    return 1;
}
/*
2.ɾ��ͼ��
*/
int deletebook(void)
{
    char check = 'n';
    int rtn = 1;
    char ISBN[12];
    BOOK book;
    do {
        cout << "������ISBN��";
        cin >> ISBN;
        book = findbook(ISBN);
        if (book.count == -1)
        {
            rtn = 0;
            cout << "û���ҵ���" << endl;
        }
        else
        {
            rtn = removebook(ISBN);
            if (rtn == 0)
                cout << "ɾ��ʧ��!" << endl;
        }
        cout << "������(y/n)";
        cin >> check;
    } while (check != 'n');
    return rtn;
}

/*
3.��ѯͼ��
*/
int searchbook(void)
{
    char ISBN[12];
    int rtn = 0;
    BOOK book;
    char check = 'n';
    do {
        cout << "������ISBN��";
        cin >> ISBN;
        book = findbook(ISBN);
        if (book.count == -1)
            cout << "û�ҵ�" << endl;
        else
        {
            cout << "ISBN=" << book.isbn << endl;
            cout << "name=" << book.name << endl;
            cout << "publisher=" << book.publisher << endl;
            cout << "author=" << book.author << endl;
            cout << "ver=" << book.ver << endl;
            cout << "price=" << book.price << endl;
            cout << "count=" << book.count << endl;
        }
        cout << "������ѯ��(y/n)";
        cin >> check;
    } while (check != 'n');
    return rtn;
}


/*
4.�޸�ͼ��
*/
int modifybook(void)
{
    cout << "�޸�ͼ��" << endl;

    char ISBN[12];
    int rtn = 0;
    BOOK book;
    char check = 'n';
    do {
        cout << "������ISBN��";
        cin >> ISBN;
        book = findbook(ISBN);
        if (book.count == -1)
            cout << "û�ҵ�" << endl;
        else
        {
            cout << "ISBN=" << book.isbn << endl;
            cout << "name=" << book.name << endl;
            cout << "publisher=" << book.publisher << endl;
            cout << "author=" << book.author << endl;
            cout << "ver=" << book.ver << endl;
            cout << "price=" << book.price << endl;
            cout << "count=" << book.count << endl;
            cout << "�޸���(y/n)";
            cin >> check;
            if (check == 'y')
            {
                removebook(ISBN);
                inputbook();
            }
        }
        cout << "������(y/n)";
        cin >> check;
    } while (check != 'n');
    return rtn;
}



/*
5.����ͼ��
*/
int lendbook(void)
{
    cout << "����ͼ��" << endl;
    char ISBN[12];
    char name[20];
    MEMBER member;
    BOOK book;
    cout << "����ͼ��ISBN: ";
    cin >> ISBN;
    cout << "�������������: ";
    cin >> name;
    book = findbook(ISBN);
    if (book.count == -1)
        cout << "ͼ�鲻���ڣ�" << endl;
    else
    {
        member = findmember(name);
        if (member.borrow == -1)
            cout << "��Ա������" << endl;
        else
        {
            if (member.borrow > 3)
                cout << "���ĳ��ޣ������ٽ�." << endl;
            else
            {
                if (book.count == 0)
                    cout << "���ѽ���!" << endl;
                else
                {
                    member.borrow++;
                    book.count--;
                    if (member.isbn1[0] == '\0')
                        strcpy_s(member.isbn1, book.isbn);
                    else if (member.isbn2[0] == '\0')
                        strcpy_s(member.isbn2, book.isbn);
                    else
                        strcpy_s(member.isbn3, book.isbn);
                    removemember(member.name);//ɾ���ɵ��û���Ϣ
                    memberborrow(member);//�����µ��û���Ϣ
                    removebook(book.isbn);
                    lendbook(book);
                }

            }
        }
    }

    return 0;
}



/*
6.�黹ͼ��
*/
int returnbook(void)
{
    cout << "�黹ͼ��" << endl;
    char ISBN[12];
    char name[20];
    MEMBER member;
    BOOK book;
    bool ok = false;
    cout << "����ͼ��ISBN: ";
    cin >> ISBN;
    cout << "�������������: ";
    cin >> name;
    book = findbook(ISBN);
    if (book.count == -1)
        cout << "ͼ�鲻���ڣ�" << endl;
    else
    {
        member = findmember(name);
        if (member.borrow == -1)
            cout << "��Ա������" << endl;
        else
        {
            if (!strcmp(member.isbn1, book.isbn))
            {
                member.isbn1[0] = '\0';
                ok = true;
            }
            else if (!strcmp(member.isbn2, book.isbn))
            {
                member.isbn2[0] = '\0';
                ok = true;
            }
            else if (!strcmp(member.isbn3, book.isbn))
            {
                member.isbn3[0] = '\0';
                ok = true;
            }
            else
                cout << "�û�Աû�н����." << endl;
            if (ok)
            {
                member.borrow--;
                book.count++;
                removemember(member.name);
                memberborrow(member);
                removebook(book.isbn);
                lendbook(book);
            }
        }
    }
    return 0;
}



/*
7.ע���Ա
*/
int inputmember(void)
{
    cout << "ע���Ա" << endl;
    int rtn = 1;
    MEMBER member;
    char check = 'n';
    FILE* fp;
    //fp = fopen(_MEMBER_FILE_, "ab");/*׷�ӷ�ʽ���ļ�*/
    errno_t err = fopen_s(&fp, _MEMBER_FILE_, "ab");
    if (fp == NULL)
        //fp = fopen(_MEMBER_FILE_, "wb"); /*д��ʽ���ļ�*/
        err = fopen_s(&fp, _MEMBER_FILE_, "wb");
    if (fp == NULL)
        rtn = 0;
    else
    {
        do {
            cout << "¼���Ա" << endl;
            cout << "����--";
            cin >> member.name;
            cout << "��ַ--";
            cin >> member.address;
            member.borrow = 0;
            member.isbn1[0] = '\0';
            member.isbn2[0] = '\0';
            member.isbn3[0] = '\0';
            cout << "ȷ�ϱ���(y/n):";
            cin >> check;
            if (check = 'y')
            {
                fwrite(&member, sizeof(member), 1, fp);/*��д*/
            }
            cout << "����¼����(y/n)";
            cin >> check;
        } while (check != 'n');
    }
    fclose(fp);
    return rtn;
    return 0;
}

/*
8.ע����Ա
*/
int deletemember(void)
{
    cout << "ע����Ա" << endl;
    char check = 'n';
    int rtn = 1;
    char name[20];
    MEMBER member;
    do {
        cout << "������������";
        cin >> name;
        member = findmember(name);
        if (member.borrow == -1)
        {
            rtn = 0;
            cout << "û���ҵ���" << endl;
        }
        else
        {
            rtn = removemember(name);
            if (rtn == 0)
                cout << "ɾ��ʧ��!" << endl;
        }
        cout << "������(y/n)";
        cin >> check;
    } while (check != 'n');
    return rtn;
}



/*
9.��ѯ��Ա
*/
int searchmember(void)
{
    cout << "��ѯ��Ա" << endl;
    char name[20];
    int rtn = 0;
    MEMBER member;
    char check = 'n';
    do {
        cout << "������������";
        cin >> name;
        member = findmember(name);
        if (member.borrow == -1)
            cout << "û�ҵ�" << endl;
        else
        {
            cout << "����   ��ַ   ������    isbn1   isbn2   isbn3" << endl;
            cout << member.name << "  " << member.address << "  " << member.borrow << "  " << member.isbn1 << "  " << member.isbn2 << "  " << member.isbn3 << endl;
        }
        cout << "������ѯ��(y/n)";
        cin >> check;
    } while (check != 'n');
    return rtn;
}



/*
10.�޸Ļ�Ա
*/
int modifymember(void)
{
    cout << "�޸Ļ�Ա" << endl;

    char name[20];
    int rtn = 0;
    MEMBER member;
    char check = 'n';
    do {
        cout << "������������";
        cin >> name;
        member = findmember(name);
        if (member.borrow == -1)
            cout << "û�ҵ�" << endl;
        else
        {
            cout << "����=" << member.name << endl;
            cout << "��ַ=" << member.address << endl;
            cout << "������=" << member.borrow << endl;
            cout << "ISBN1=" << member.isbn1 << endl;
            cout << "ISBN2=" << member.isbn2 << endl;
            cout << "ISBN3=" << member.isbn3 << endl;
            cout << "�޸���(y/n)";
            cin >> check;
            if (check == 'y')
            {
                removemember(name);
                inputmember();
            }
        }
        cout << "������(y/n)";
        cin >> check;
    } while (check != 'n');
    return rtn;
}



MEMBER findmember(char* name)
{
    MEMBER member;
    bool found = false;
    FILE* fp;
    //fp = fopen(_MEMBER_FILE_, "rb");/*����ʽ���ļ�*/
    errno_t err = fopen_s(&fp, _MEMBER_FILE_, "rb");
    member.borrow = -1;
    if (fp != NULL)
    {
        fread(&member, sizeof(member), 1, fp);
        while (!feof(fp))
        {
            if (!strcmp(member.name, name))
            {
                found = true;
                break;
            }
            fread(&member, sizeof(member), 1, fp);
        }
        if (!found)
            member.borrow = -1;
        fclose(fp);
    }
    return member;
}



int removemember(char* name)
{
    MEMBER member;
    FILE* fp;
    FILE* temp;
    //temp = fopen(_TEMP_FILE_, "w");/*д��ʽ���ļ�*/
    errno_t err = fopen_s(&temp, _TEMP_FILE_, "w");
    //fp = fopen(_MEMBER_FILE_, "rb");/*����ʽ���ļ�*/
    err = fopen_s(&fp, _MEMBER_FILE_, "rb");
    if (fp != NULL)
    {
        fread(&member, sizeof(member), 1, fp);
        while (!feof(fp))
        {
            if (strcmp(member.name, name))
            {
                fwrite(&member, sizeof(member), 1, temp);/*��д*/
            }
            fread(&member, sizeof(member), 1, fp);
        }
        fclose(fp);
        fclose(temp);
        remove(_MEMBER_FILE_);
        rename(_TEMP_FILE_, _MEMBER_FILE_);
    }
    return 1;
}



int memberborrow(MEMBER member)
{
    int rtn = 1;
    FILE* fp;
    //fp = fopen(_MEMBER_FILE_, "ab");/*׷�ӷ�ʽ���ļ�*/
    errno_t err = fopen_s(&fp, _MEMBER_FILE_, "ab");
    if (fp == NULL)
        //fp = fopen(_MEMBER_FILE_, "wb"); /*д��ʽ���ļ�*/
        err = fopen_s(&fp, _MEMBER_FILE_, "wb");
    if (fp == NULL)
        rtn = 0;
    else
    {
        fwrite(&member, sizeof(member), 1, fp);/*��д*/
    }
    fclose(fp);
    return rtn;
    return 0;
}


int lendbook(BOOK book)
{
    int rtn = 1;
    FILE* fp;
    //fp = fopen(_DATA_FILE_, "ab");/*׷�ӷ�ʽ���ļ�*/
    errno_t err = fopen_s(&fp, _DATA_FILE_, "ab");
    if (fp == NULL)
        //fp = fopen(_DATA_FILE_, "wb"); /*д��ʽ���ļ�*/
        errno_t err = fopen_s(&fp, _DATA_FILE_, "wb");
    if (fp == NULL)
        rtn = 0;
    else
    {
        fwrite(&book, sizeof(book), 1, fp);/*��д*/
    }
    fclose(fp);
    return rtn;
}
