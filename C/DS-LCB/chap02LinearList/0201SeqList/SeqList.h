#include <stdio.h>
#include <malloc.h>

#define MaxSize 50
typedef char ElemType; 

typedef struct
{
	ElemType elem[MaxSize];
	int length;
}SeqList;

void InitList(SeqList * &L);
void DestoryList(SeqList *L);
int ListEmpty(SeqList *L);
int ListLength(SeqList *L);
void DispList(SeqList *L);
int GetElem(SeqList *L, int i, ElemType &e);
int LocateElem(SeqList *L, ElemType e);
int ListInsert(SeqList * &L, int i, ElemType e);
int ListDelete(SeqList *&L, int i, ElemType &e);
int DeleteList(SeqList *L, int i, ElemType *e);
void ClearList(SeqList *L);