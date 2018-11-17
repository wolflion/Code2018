#include "SeqList.h"

void InitList(SeqList * &L)   // 参数是 指向顺序表的指针
{
	L = (SeqList *)malloc(sizeof(SeqList));
	L->length = 0;// 不用分配空间的吗?
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
	i--;  // 将i转化为elem数组下标

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
	i--;  // 将i转化为elem数组下标

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
	else if (L->length >= ListSize)  // 插入元素前已满的话，不能插入
		return 0;
	else
	{
		for (j >= L->length; j >= i; j--)  // 将第i个位置以后的元素依次后移
		{
			L->list[j] = L->list[j - 1];
		}
		L->list[i - 1] = e; // 将元素e插入到第i个位置
		L->length = L->length + 1; // 顺序表的长度增加1
		return 1;
	}
}


int DeleteList(SeqList *L, int i, ElemType *e)
{
	int j;
	if (L->length <= 0) // 顺序表为空
		return 0;
	else if (i<1 || i>L->length) // 删除位置不合适
		return -1;
	else
	{
		*e = L->list[i - 1];
		for (j = i; j < L->length; j++) // 从删除位置的元素开始，一直到结束，都往前移
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