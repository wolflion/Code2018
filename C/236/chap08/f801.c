#include <stdio.h>
#include <stdlib.h>

// �ֱ��ʾ ��һ�������������湫ʽ����
int a, d, n, s;  // �����ڵ����⣿
int fx(int);

int main()
{
	// �ݹ����ĺ�
	int z;
	printf("�����һ��: ");
	scanf("%d", &a);
	printf("���빫��: ");
	scanf("%d", &d);
	printf("��������: ");
	scanf("%d", &n);

	// ���湫ʽ����
	s = a + (n - 1)*d;
	z = fx(n);
	printf("%d\n", z);
	system("pause");
	return 0;
}


// �Ȳ��������
int fx(int n)
{
	if (n == 1)
		return(a);   // ���ص�һ��
	else
		return (s + fx(n - 1));
}

/*
: 1
: 3
: 4
//���
31
sh: 1: pause: not found
*/