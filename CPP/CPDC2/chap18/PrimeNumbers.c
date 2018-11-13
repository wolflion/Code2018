#include <stdio.h>

/*�������*/
int isPrime(int x)
{
	int i;
	if (x < 2)
		return 0;
	else if (x==2)
	{
		return 1;  // 2��
	}
	if (x % 2 == 0)   // ż������
		return 0;

	// iС�ڵ���x��ƽ����ʱ
	for (i = 3; i*i <= x; i += 2)
	{
		if (x%i == 0)
			return 0;
	}
	return 1;
}

int main()
{
	int n, x, i;
	int cnt = 0;
	scanf("%d", &n);
	for (i = 0; i < n;i++)
	{
		scanf("%d", &x);
		if (isPrime(x))
			cnt++;
	}
	printf("%d\n", cnt);

	return 0;
}

/*
6
2
3
4
5
6
7  // ����6������
//output
4
*/