#include<stdio.h>
#include "malloc.h"

typedef int ElemType;
typedef int Status;

//�������״̬���� 
#define   TRUE    1
#define   FALSE   0
#define   OK    1
#define    ERROR    0
#define    INFEASIBLE   -1
#define   OVERFLOW   -2

//----------���Ա�Ķ�̬����洢�ṹ--------------
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef struct {
	ElemType *elem;
	int length;
	int listsize;
}SqList;

SqList L;

//----------1 ��ʼ��--------------
Status InitList_Sq(SqList L)
{
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem)
		return(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}

//----------2 �������Ա�--------------
Status DestroyList(SqList L)
{
	if (! L.elem) {return ERROR;}
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
	L.listsize = 0;
	return OK;
}

//----------3 �����Ա���Ϊ�ձ�--------------
Status ClearList(SqList L)
{
	if (!L.elem) { return ERROR; }
	L.length = 0;
	return OK;
}

//----------4 �ж����Ա��Ƿ�Ϊ��--------------
Status ListEmpty(SqList L)
{
	if (L.length > 0)
		return TRUE;
	else
		return FALSE;
}

//----------5 ���--------------
int ListLength(SqList L)
{
	return L.length;
}

//----------6 ���ұ��е�i�����ݵ�ֵ--------------
ElemType GetElem(SqList L, int i, ElemType e)
{
	if ((i < 1) || (i > L.length)) return ERROR;
	e = L.elem[i - 1];
	return e;
}

//----------7 ��i��λ��ǰ����Ԫ��e--------------
Status ListInsert(SqList L, int i, ElemType e)
{
	if ((i < 1) || (i > L.length+1)) return ERROR;
	if (L.length >= L.listsize)
	{
		ElemType newbase;
		newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase) return OVERFLOW;
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	ElemType *q,*p;
	q = &(L.elem[i - 1]);
	for (p = &(L.elem[i - 1]); p >= q; --p)
	{
		*(p + 1) = *p;
	}
	*q = e;
	L.length++;

	return OK;
}



int main()
{
	printf("hello world\n");
}