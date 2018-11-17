#include <stdio.h>
#include <malloc.h>

#define MaxSize 50
typedef char ElemType; 

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LinkList;

void InitList(LinkList * &L);
void DestoryList(LinkList *L);
int ListEmpty(LinkList *L);
int ListLength(LinkList *L);
void DispList(LinkList *L);
int GetElem(LinkList *L, int i, ElemType &e);
int LocateElem(LinkList *L, ElemType e);
int ListInsert(LinkList * &L, int i, ElemType e);
int ListDelete(LinkList *&L, int i, ElemType &e);