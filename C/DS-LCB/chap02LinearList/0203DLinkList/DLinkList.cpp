// 只有初始化，插入，删除不一样
#include "DLinkList.h"

void InitList(DLinkList * &L) 
{
	L = (DLinkList *)malloc(sizeof(DLinkList));
	L->prior=L->next = NULL;
}

void DestoryList(DLinkList *L)
{
	DLinkList *p = L, *q = p->next;
	while (q!=NULL)
	{
		free(p);
		p = q;
		q = p->next;
	}
	free(p);
}

int ListEmpty(DLinkList *L)
{
	return(L->next == NULL);
}

int ListLength(DLinkList *L)
{
	DLinkList *p = L;
	int i = 0;
	while (p->next !=NULL)
	{
		i++;
		p = p->next;
	}
	return (i);
}

void DispList(DLinkList *L)
{
	DLinkList *p = L->next;
	while (p!=NULL)
	{
		printf("%c", p->data);
		p = p->next;
	}
	printf("\n");
}

int GetElem(DLinkList *L, int i, ElemType &e)
{
	int j = 0;
	DLinkList *p = L;
	while (j<i && p!=NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return 0;
	else
	{
		e = p->data;
		return 1;
	}
}

int LocateElem(DLinkList *L, ElemType e)
{
	DLinkList *p = L->next;
	int n = 1;
	while (p!=NULL && p->data != e)
	{
		p=p->next;
		n++;
	}
	if (p==NULL)
	{
		return 0;
	}
	else
	{
		return n;
	}
}

int ListInsert(DLinkList * &L, int i, ElemType e)
{
	int j = 0;
	DLinkList *p = L, *s;
	while (j<i-1 && p!=NULL)
	{
		j++;
		p = p->next;
	}

	if (p == NULL)
		return 0;
	else
	{
		// 主要在这部分有差异
		s = (DLinkList *)malloc(sizeof(DLinkList));
		s->data = e;
		s->next = p->next;
		// 主要在这部分有差异，增加了这两行
		if (p->next != NULL) p->next->prior = s;
		s->prior = p;
		// added end
		p->next = s;
		return 1;
	}
}

int ListDelete(DLinkList *&L, int i, ElemType &e)
{
	int j = 0;
	DLinkList *p = L, *q;
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}

	if (p == NULL)
		return 0;
	else
	{
		q = p->next;
		// add 
		if (q == NULL) return 0;
		// add end
		p->next = q->next;
		// add
		if (p->next != NULL) p->next->prior = p;
		// add end
		free(q);
		return 1;
	}
}