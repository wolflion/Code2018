#include <stdio.h>
#include <malloc.h>

typedef char ElemType; 

typedef struct DNode
{
	ElemType data;
	struct DNode *prior;
	struct DNode *next;
}DLinkList;

void InitList(DLinkList * &L);
void DestoryList(DLinkList *L);
int ListEmpty(DLinkList *L);
int ListLength(DLinkList *L);
void DispList(DLinkList *L);
int GetElem(DLinkList *L, int i, ElemType &e);
int LocateElem(DLinkList *L, ElemType e);
int ListInsert(DLinkList * &L, int i, ElemType e);
int ListDelete(DLinkList *&L, int i, ElemType &e);