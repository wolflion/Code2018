#include "SeqList.h"

void InitList(SeqList * &L)   // ������ ָ��˳����ָ��
{
	L = (SeqList *)malloc(sizeof(SeqList));
	L->length = 0;// ���÷���ռ����?
}

void DestoryList(SeqList *L)
{
	free(L);
}

int ListEmpty(SeqList *L)
{
	if (L->length == 0)
		return 1;
	else
		return 0;
}

int ListLength(SeqList *L)
{
	return (L->length);
}

void DispList(SeqList *L)
{
	int i;
	if (ListEmpty(L))
		return ;
	for (i = 0; i < L->length; i++)
	{
		printf("%c", L->elem[i]);
	}
	printf("\n");
}

int GetElem(SeqList *L, int i, ElemType &e)
{
	if (i<1 || i>L->length)
		return 0;
	e = L->elem[i - 1];
	return 1;
}

int LocateElem(SeqList *L, ElemType e)
{
#if 0
	int i;
	for (i = 0; i < L->length; i++)
	{
		if (e == L->elem[i])
			return i + 1;
	}
#endif
	int i = 0;
	while (i<L->length && L->elem[i]!=e)
	{
		i++;
	}
	if (i>=L->length)
	{
		return 0;
	}
	else
	{
		return i + 1;
	}
	return 0;
}

int ListInsert(SeqList * &L, int i, ElemType e)
{
	int j;
	if (i<1 || i>L->length + 1)
		return 0;
	i--;  // ��iת��Ϊelem�����±�

	for (j = L->length; j > i; j--)
	{
		L->elem[j] = L->elem[j - 1];
	}
	L->elem[i] = e;
	L->length++;
	return 1;
}

int ListDelete(SeqList *&L, int i, ElemType &e)
{
	int j;
	if (i<1 || i>L->length + 1)
		return 0;
	i--;  // ��iת��Ϊelem�����±�

	e = L->elem[i];
	for (j= i ; j < L->length-1; j++)
	{
		L->elem[j] = L->elem[j + 1];
	}
	L->length--;
	return 1;
}

# if 0
int ListInsert(SeqList *L, int i, ElemType e)
{
	int j;
	if (i<1 || i>L.length + 1)
		return -1;
	else if (L->length >= ListSize)  // ����Ԫ��ǰ�����Ļ������ܲ���
		return 0;
	else
	{
		for (j >= L->length; j >= i; j--)  // ����i��λ���Ժ��Ԫ�����κ���
		{
			L->list[j] = L->list[j - 1];
		}
		L->list[i - 1] = e; // ��Ԫ��e���뵽��i��λ��
		L->length = L->length + 1; // ˳���ĳ�������1
		return 1;
	}
}


int DeleteList(SeqList *L, int i, ElemType *e)
{
	int j;
	if (L->length <= 0) // ˳���Ϊ��
		return 0;
	else if (i<1 || i>L->length) // ɾ��λ�ò�����
		return -1;
	else
	{
		*e = L->list[i - 1];
		for (j = i; j < L->length; j++) // ��ɾ��λ�õ�Ԫ�ؿ�ʼ��һֱ������������ǰ��
		{
			L->list[j - 1] = L->list[j];
		}
		L->length = L->length - 1;
		return 1;
	}
}

void ClearList(SeqList *L)
{
	L->length = 0;
}
#endif