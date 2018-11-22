#include "DLinkList.h"

int main()
{
	DLinkList *L;
	ElemType e;
	printf("(1) init L\n");
	InitList(L);
	printf("(2) insert \n"); 
	ListInsert(L, 1, 'a');
	ListInsert(L, 2, 'b');
	ListInsert(L, 3, 'c');
	ListInsert(L, 4, 'd');
	ListInsert(L, 5, 'e');
	printf("(3) display ");
	DispList(L);
	printf("(4) length = %d\n", ListLength(L));
	printf("(5) %d empty \n", ListEmpty(L));
	GetElem(L, 3, e);
	printf("(6) 3 elem is %c\n", e);
	printf("(7) a location %d\n", LocateElem(L, 'a'));
	printf("(8) 4 insert f \n");
	ListInsert(L, 4, 'f');
	printf("(9) display ");
	DispList(L);
	printf("(10) del 3\n");
	ListDelete(L, 3, e);
	printf("(11) display ");
	DispList(L);
	printf("(12) free \n");
	DestoryList(L);
	return 0;
}

// gcc testDLinkList.cpp DLinkList.cpp

/*
(1) init L
(2) insert
(3) display abcde
(4) length = 5
(5) 0 empty
(6) 3 elem is c
(7) a location 1
(8) 4 insert f
(9) display abcfde
(10) del 3
(11) display abfde
(12) free
*/