#include <stdio.h>
#include <stdlib.h>

int sum(int *a, int n);

int main()
{
	int myarr[5] = { 1, 2, 3, 4, 5 };
	printf("������Ԫ�صĺ��� %d\n", sum(myarr, 5));

	int myarr2[5] = { 12, 21, 32, 44, 1 };
	printf("������Ԫ�ص�ǰ������� %d\n", sum(myarr2, 5));
	printf("������Ԫ�ص�ǰ������� %d\n", sum(myarr2, 4));

	system("pause");
	return 0;
}

int sum(int *a, int n)
{
	if (n == 0)
		return 0;
	else
		return sum(a, n - 1) + a[n-1];  // a������������

	// return n==0?0:sum(a,n-1)+a[n-1];
}

/*
������Ԫ�صĺ��� 15
������Ԫ�ص�ǰ������� 110
������Ԫ�ص�ǰ������� 109
�밴���������. . .
*/