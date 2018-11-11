#include <stdio.h>
#include <stdlib.h>

int sum(int *a, int n);

int main()
{
	int myarr[5] = { 1, 2, 3, 4, 5 };
	printf("数组中元素的和是 %d\n", sum(myarr, 5));

	int myarr2[5] = { 12, 21, 32, 44, 1 };
	printf("数组中元素的前五项和是 %d\n", sum(myarr2, 5));
	printf("数组中元素的前四项和是 %d\n", sum(myarr2, 4));

	system("pause");
	return 0;
}

int sum(int *a, int n)
{
	if (n == 0)
		return 0;
	else
		return sum(a, n - 1) + a[n-1];  // a是数组名不变

	// return n==0?0:sum(a,n-1)+a[n-1];
}

/*
数组中元素的和是 15
数组中元素的前五项和是 110
数组中元素的前四项和是 109
请按任意键继续. . .
*/