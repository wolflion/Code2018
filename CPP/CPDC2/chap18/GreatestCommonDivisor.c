#include <stdio.h>

//用递归函数求最大公约数
int gcd(int x, int y)
{
	return y ? gcd(y, x%y) : x;
}

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n", gcd(a, b));

	return 0;
}

/*
147 105
//output
21
*/