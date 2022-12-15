#ifndef DATAINFO_H_INCLUDED
#define DATAINFO_H_INCLUDED

/*
ͼ������ݽṹ
*/
typedef struct bookinfo {
	char isbn[12];		//ISBN 12B
	char name[20];		//���� 20B
	char publisher[20];	//������ 20B
	char author[20];		//���� 20B
	short ver;		//���
	float price;		//�۸�
	short count;		//���
}BOOK;


/*
��Ա�����ݽṹ
*/
typedef struct memberinfo {
	char name[20];	//��Ա�� 20B
	char address[20];//סַ 20B
	short borrow;//������
	char isbn1[12];	//��һ����isbn 12B
	char isbn2[12];	//�ڶ�����isbn 12B
	char isbn3[12];	//��������isbn 12B
}MEMBER;


#endif // DATAINFO_H_INCLUDED