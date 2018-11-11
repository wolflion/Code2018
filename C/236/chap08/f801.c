#include <stdio.h>
#include <stdlib.h>

// 分别表示 第一项、公差、项数、常规公式计算
int a, d, n, s;  // 生存期的问题？
int fx(int);

int main()
{
	// 递归计算的和
	int z;
	printf("输入第一项: ");
	scanf("%d", &a);
	printf("输入公差: ");
	scanf("%d", &d);
	printf("输入项数: ");
	scanf("%d", &n);

	// 常规公式计算
	s = a + (n - 1)*d;
	z = fx(n);
	printf("%d\n", z);
	system("pause");
	return 0;
}


// 等差数列求和
int fx(int n)
{
	if (n == 1)
		return(a);   // 返回第一项
	else
		return (s + fx(n - 1));
}

/*
: 1
: 3
: 4
//输出
31
sh: 1: pause: not found
*/