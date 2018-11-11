#include <stdio.h>
#include <stdlib.h>

// 数值比较大，用long类型
long fabonacci(long n)
{
	if (n == 0 || n == 1)
		return n;
	else
		return fabonacci(n - 1) + fabonacci(n - 2);
}

int main()
{
	long n;
	printf("请输入项数(n):");
	scanf("ld", &n);

	printf("数列为： \n");
	for (int i = 0; i < n; i++)
	{
		if (i % 5 == 0) // 一行输出5个
			printf("\n");
		printf("%4d", fabonacci(n));
	}
	printf("\n");

	system("pause");
	return 0;
}