#include <stdio.h>
#include <stdlib.h>

int factorial(int num)
{
	if (num == 1)
		return 1;
	else
		return factorial(num-1)*num;   // 这个又弄混了，写成factorial(num)*(num-1)，这是错的
}

int main()
{
	int number;
	printf("请输入要求阶乘的数字： ");
	scanf("%d", &number);

	printf("%d的阶乘等于： %d\n", number, factorial(number));

	system("pause");
	return 0;
}

/*
请输入要求阶乘的数字： 5
5的阶乘等于： 120
*/