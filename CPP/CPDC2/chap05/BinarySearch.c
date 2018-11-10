#include <stdio.h>

int A[1000000], n;

int binarySearch(int key)
{
	int left = 0;
	int right = n;
	int mid;
	while (left<right)
	{
		mid = (left + right) / 2;
		if (key == A[mid])
			return 1;   // �ҵ�
		if (key > A[mid])
		{
			left = mid+1; // ������벿��
		}
		else if (key <A[mid])
		{
			right = mid;  // ����ǰ�沿��
		}
	}
	return 0;
}

int main()
{
	int i, q, k, sum = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}

	scanf("%d", &q);
	for (i = 0; i < q; i++)
	{
		scanf("%d", &k);
		if (binarySearch(k))
		{
			sum++;
		}
	}
	printf("%d\n", sum);
	return 0;
}

/*
// ����
5
1 2 3 4 5
3
3 4 1
// ���
3
*/