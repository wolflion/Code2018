#include "SeqList.h"

// �Լ��б߽�ĵط�ûע�⵽�������ϻ����Լ�����Ϥ
void insert(SeqList &L, ElemType x)
{
	int i = 0;
	//while (i<L.length & x > L.data[i])
	while (i<L.length & x>=L.data[i])
	{
		i++;
	}

	//for (j = L.length; j > i;j--)
	for (j = L.length - 1; j >= i; j--)
		L.data[j + 1] = L.data[j];

	//L.data[i-1] = x;
	L.data[i] = x;
	L.length++;
}