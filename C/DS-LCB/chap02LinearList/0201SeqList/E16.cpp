#include "SeqList.h"

void move(SeqList &L)
{
	ElemType tmp;  // ¡Ÿ ±±‰¡ø
	int i = 0; j = L.length - 1;

	while (i<j)
	{
		while (i < j&& L.data[i] < 0)
			i++;

		while (i < j&& L.data[j] >= 0)
			j--;

		if (i < j)
		{
			tmp = L.data[i];
			L.data[i] = L.data[j];
			L.data[j] = tmp;
		}
	}
}