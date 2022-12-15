#ifndef DATAINFO_H_INCLUDED
#define DATAINFO_H_INCLUDED

/*
图书的数据结构
*/
typedef struct bookinfo {
	char isbn[12];		//ISBN 12B
	char name[20];		//书名 20B
	char publisher[20];	//出版社 20B
	char author[20];		//作者 20B
	short ver;		//版次
	float price;		//价格
	short count;		//库存
}BOOK;


/*
会员的数据结构
*/
typedef struct memberinfo {
	char name[20];	//会员名 20B
	char address[20];//住址 20B
	short borrow;//借阅数
	char isbn1[12];	//第一本的isbn 12B
	char isbn2[12];	//第二本的isbn 12B
	char isbn3[12];	//第三本的isbn 12B
}MEMBER;


#endif // DATAINFO_H_INCLUDED