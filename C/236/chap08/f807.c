#include <stdio.h>
#include <stdlib.h>

// ��ֵ�Ƚϴ���long����
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
	printf("����������(n):");
	scanf("ld", &n);

	printf("����Ϊ�� \n");
	for (int i = 0; i < n; i++)
	{
		if (i % 5 == 0) // һ�����5��
			printf("\n");
		printf("%4d", fabonacci(n));
	}
	printf("\n");

	system("pause");
	return 0;
}