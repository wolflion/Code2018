#include "SeqList.h"

void Intersection(SeqList A, SeqList B, SeqList &C)
{
	int i, j, k = 0;
	for (i = 0; i < A.length; i++)
	{
		j = 0;
		while (j<B.length && B.data[j] != A.data[i])
		{
			j++;
		}

		if (j < B.length)
			c.data[k++] = a.data[i];
	}
	C.length = k;
}