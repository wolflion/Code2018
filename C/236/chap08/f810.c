#include <stdio.h>
#include <stdlib.h>

int factorial(int num)
{
	if (num == 1)
		return 1;
	else
		return factorial(num-1)*num;   // �����Ū���ˣ�д��factorial(num)*(num-1)�����Ǵ��
}

int main()
{
	int number;
	printf("������Ҫ��׳˵����֣� ");
	scanf("%d", &number);

	printf("%d�Ľ׳˵��ڣ� %d\n", number, factorial(number));

	system("pause");
	return 0;
}

/*
������Ҫ��׳˵����֣� 5
5�Ľ׳˵��ڣ� 120
*/