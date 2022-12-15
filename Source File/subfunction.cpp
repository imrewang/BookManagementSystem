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
    cout << "姓名   地址   借阅数    isbn1   isbn2   isbn3" << endl;
    fread(&member, sizeof(member), 1, fp);
    while (!feof(fp))
    {
        cout << member.name << "  " << member.address << "  " << member.borrow << "  " << member.isbn1 << "  " << member.isbn2 << "  " << member.isbn3 << endl;
        fread(&member, sizeof(member), 1, fp);
    }
    fclose(fp);
}


/*
1.录入图书
*/
int inputbook(void)
{
    int rtn = 1;
    BOOK book;
    char check = 'n';
    FILE* fp;
    //fp = fopen(_DATA_FILE_, "ab");/*追加方式打开文件*/
    errno_t err = fopen_s(&fp, _DATA_FILE_, "ab");
    if (fp == NULL)
        //fp = fopen(_DATA_FILE_, "wb"); /*写方式打开文件*/
        err = fopen_s(&fp, _DATA_FILE_, "wb");
    if (fp == NULL)
        rtn = 0;
    else
    {
        do {
            cout << "录入图书" << endl;
            cout << "ISBN--";
            cin >> book.isbn;
            cout << "书名--";
            cin >> book.name;
            cout << "出版社--";
            cin >> book.publisher;
            cout << "作者--";
            cin >> book.author;
            cout << "版次--";
            cin >> book.ver;
            cout << "价格--";
            cin >> book.price;
            cout << "库存--";
            cin >> book.count;
            cout << "确认保存(y/n):";
            cin >> check;
            if (check = 'y')
            {
                fwrite(&book, sizeof(book), 1, fp);/*块写*/
            }
            cout << "继续录入吗？(y/n)";
            cin >> check;
        } while (check != 'n');
    }
    fclose(fp);
    return rtn;
}


/*
查询图书
*/
BOOK findbook(char* ISBN)
{
    BOOK book;
    bool found = false;
    FILE* fp;
    //fp = fopen(_DATA_FILE_, "rb");/*读方式打开文件*/
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
    //temp = fopen(_TEMP_FILE_, "w");/*写方式打开文件*/
    errno_t err = fopen_s(&temp, _TEMP_FILE_, "w");
    //fp = fopen(_DATA_FILE_, "rb");/*读方式打开文件*/
    err = fopen_s(&fp, _DATA_FILE_, "rb");
    if (fp != NULL)
    {
        fread(&book, sizeof(book), 1, fp);
        while (!feof(fp))
        {
            if (strcmp(book.isbn, ISBN))
            {
                fwrite(&book, sizeof(book), 1, temp);/*块写*/
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
2.删除图书
*/
int deletebook(void)
{
    char check = 'n';
    int rtn = 1;
    char ISBN[12];
    BOOK book;
    do {
        cout << "请输入ISBN：";
        cin >> ISBN;
        book = findbook(ISBN);
        if (book.count == -1)
        {
            rtn = 0;
            cout << "没有找到！" << endl;
        }
        else
        {
            rtn = removebook(ISBN);
            if (rtn == 0)
                cout << "删除失败!" << endl;
        }
        cout << "继续吗？(y/n)";
        cin >> check;
    } while (check != 'n');
    return rtn;
}

/*
3.查询图书
*/
int searchbook(void)
{
    char ISBN[12];
    int rtn = 0;
    BOOK book;
    char check = 'n';
    do {
        cout << "请输入ISBN：";
        cin >> ISBN;
        book = findbook(ISBN);
        if (book.count == -1)
            cout << "没找到" << endl;
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
        cout << "继续查询吗？(y/n)";
        cin >> check;
    } while (check != 'n');
    return rtn;
}


/*
4.修改图书
*/
int modifybook(void)
{
    cout << "修改图书" << endl;

    char ISBN[12];
    int rtn = 0;
    BOOK book;
    char check = 'n';
    do {
        cout << "请输入ISBN：";
        cin >> ISBN;
        book = findbook(ISBN);
        if (book.count == -1)
            cout << "没找到" << endl;
        else
        {
            cout << "ISBN=" << book.isbn << endl;
            cout << "name=" << book.name << endl;
            cout << "publisher=" << book.publisher << endl;
            cout << "author=" << book.author << endl;
            cout << "ver=" << book.ver << endl;
            cout << "price=" << book.price << endl;
            cout << "count=" << book.count << endl;
            cout << "修改吗？(y/n)";
            cin >> check;
            if (check == 'y')
            {
                removebook(ISBN);
                inputbook();
            }
        }
        cout << "继续吗？(y/n)";
        cin >> check;
    } while (check != 'n');
    return rtn;
}



/*
5.借阅图书
*/
int lendbook(void)
{
    cout << "借阅图书" << endl;
    char ISBN[12];
    char name[20];
    MEMBER member;
    BOOK book;
    cout << "输入图书ISBN: ";
    cin >> ISBN;
    cout << "输入借阅者姓名: ";
    cin >> name;
    book = findbook(ISBN);
    if (book.count == -1)
        cout << "图书不存在！" << endl;
    else
    {
        member = findmember(name);
        if (member.borrow == -1)
            cout << "会员不存在" << endl;
        else
        {
            if (member.borrow > 3)
                cout << "借阅超限，不能再借." << endl;
            else
            {
                if (book.count == 0)
                    cout << "书已借完!" << endl;
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
                    removemember(member.name);//删除旧的用户信息
                    memberborrow(member);//加入新的用户信息
                    removebook(book.isbn);
                    lendbook(book);
                }

            }
        }
    }

    return 0;
}



/*
6.归还图书
*/
int returnbook(void)
{
    cout << "归还图书" << endl;
    char ISBN[12];
    char name[20];
    MEMBER member;
    BOOK book;
    bool ok = false;
    cout << "输入图书ISBN: ";
    cin >> ISBN;
    cout << "输入借阅者姓名: ";
    cin >> name;
    book = findbook(ISBN);
    if (book.count == -1)
        cout << "图书不存在！" << endl;
    else
    {
        member = findmember(name);
        if (member.borrow == -1)
            cout << "会员不存在" << endl;
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
                cout << "该会员没有借该书." << endl;
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
7.注册会员
*/
int inputmember(void)
{
    cout << "注册会员" << endl;
    int rtn = 1;
    MEMBER member;
    char check = 'n';
    FILE* fp;
    //fp = fopen(_MEMBER_FILE_, "ab");/*追加方式打开文件*/
    errno_t err = fopen_s(&fp, _MEMBER_FILE_, "ab");
    if (fp == NULL)
        //fp = fopen(_MEMBER_FILE_, "wb"); /*写方式打开文件*/
        err = fopen_s(&fp, _MEMBER_FILE_, "wb");
    if (fp == NULL)
        rtn = 0;
    else
    {
        do {
            cout << "录入会员" << endl;
            cout << "姓名--";
            cin >> member.name;
            cout << "地址--";
            cin >> member.address;
            member.borrow = 0;
            member.isbn1[0] = '\0';
            member.isbn2[0] = '\0';
            member.isbn3[0] = '\0';
            cout << "确认保存(y/n):";
            cin >> check;
            if (check = 'y')
            {
                fwrite(&member, sizeof(member), 1, fp);/*块写*/
            }
            cout << "继续录入吗？(y/n)";
            cin >> check;
        } while (check != 'n');
    }
    fclose(fp);
    return rtn;
    return 0;
}

/*
8.注销会员
*/
int deletemember(void)
{
    cout << "注销会员" << endl;
    char check = 'n';
    int rtn = 1;
    char name[20];
    MEMBER member;
    do {
        cout << "请输入姓名：";
        cin >> name;
        member = findmember(name);
        if (member.borrow == -1)
        {
            rtn = 0;
            cout << "没有找到！" << endl;
        }
        else
        {
            rtn = removemember(name);
            if (rtn == 0)
                cout << "删除失败!" << endl;
        }
        cout << "继续吗？(y/n)";
        cin >> check;
    } while (check != 'n');
    return rtn;
}



/*
9.查询会员
*/
int searchmember(void)
{
    cout << "查询会员" << endl;
    char name[20];
    int rtn = 0;
    MEMBER member;
    char check = 'n';
    do {
        cout << "请输入姓名：";
        cin >> name;
        member = findmember(name);
        if (member.borrow == -1)
            cout << "没找到" << endl;
        else
        {
            cout << "姓名   地址   借阅数    isbn1   isbn2   isbn3" << endl;
            cout << member.name << "  " << member.address << "  " << member.borrow << "  " << member.isbn1 << "  " << member.isbn2 << "  " << member.isbn3 << endl;
        }
        cout << "继续查询吗？(y/n)";
        cin >> check;
    } while (check != 'n');
    return rtn;
}



/*
10.修改会员
*/
int modifymember(void)
{
    cout << "修改会员" << endl;

    char name[20];
    int rtn = 0;
    MEMBER member;
    char check = 'n';
    do {
        cout << "请输入姓名：";
        cin >> name;
        member = findmember(name);
        if (member.borrow == -1)
            cout << "没找到" << endl;
        else
        {
            cout << "姓名=" << member.name << endl;
            cout << "地址=" << member.address << endl;
            cout << "借阅数=" << member.borrow << endl;
            cout << "ISBN1=" << member.isbn1 << endl;
            cout << "ISBN2=" << member.isbn2 << endl;
            cout << "ISBN3=" << member.isbn3 << endl;
            cout << "修改吗？(y/n)";
            cin >> check;
            if (check == 'y')
            {
                removemember(name);
                inputmember();
            }
        }
        cout << "继续吗？(y/n)";
        cin >> check;
    } while (check != 'n');
    return rtn;
}



MEMBER findmember(char* name)
{
    MEMBER member;
    bool found = false;
    FILE* fp;
    //fp = fopen(_MEMBER_FILE_, "rb");/*读方式打开文件*/
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
    //temp = fopen(_TEMP_FILE_, "w");/*写方式打开文件*/
    errno_t err = fopen_s(&temp, _TEMP_FILE_, "w");
    //fp = fopen(_MEMBER_FILE_, "rb");/*读方式打开文件*/
    err = fopen_s(&fp, _MEMBER_FILE_, "rb");
    if (fp != NULL)
    {
        fread(&member, sizeof(member), 1, fp);
        while (!feof(fp))
        {
            if (strcmp(member.name, name))
            {
                fwrite(&member, sizeof(member), 1, temp);/*块写*/
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
    //fp = fopen(_MEMBER_FILE_, "ab");/*追加方式打开文件*/
    errno_t err = fopen_s(&fp, _MEMBER_FILE_, "ab");
    if (fp == NULL)
        //fp = fopen(_MEMBER_FILE_, "wb"); /*写方式打开文件*/
        err = fopen_s(&fp, _MEMBER_FILE_, "wb");
    if (fp == NULL)
        rtn = 0;
    else
    {
        fwrite(&member, sizeof(member), 1, fp);/*块写*/
    }
    fclose(fp);
    return rtn;
    return 0;
}


int lendbook(BOOK book)
{
    int rtn = 1;
    FILE* fp;
    //fp = fopen(_DATA_FILE_, "ab");/*追加方式打开文件*/
    errno_t err = fopen_s(&fp, _DATA_FILE_, "ab");
    if (fp == NULL)
        //fp = fopen(_DATA_FILE_, "wb"); /*写方式打开文件*/
        errno_t err = fopen_s(&fp, _DATA_FILE_, "wb");
    if (fp == NULL)
        rtn = 0;
    else
    {
        fwrite(&book, sizeof(book), 1, fp);/*块写*/
    }
    fclose(fp);
    return rtn;
}
