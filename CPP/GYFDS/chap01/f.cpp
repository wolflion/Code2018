// f.cpp���������������ͺͷ��������͵�����
#include <stdio.h>
void fa(int a)
{
	a = 5;
	printf("fa : a=%d\n",a);
}

void fb(int &a)   // ��׼C�﷨��֧������  
{
	a = 5;
	printf("fb : a=%d\n",a);
}

void fc(int *a)   // �Լ��ĵ� *�����ø�Ϊָ��
{
	*a = 5;
	printf("fc : a=%d\n",*a);
}

void main()
{
	int n = 1;
	printf("main : before fa n = %d\n",n);
	fa(n);
	printf("main : fa(n) n = %d\n",n);
	fb(n);
	printf("main : fb(n) n = %d\n",n);
	fc(&n);   // ����ط��͵ô���ַ
	printf("main : fc(n) n = %d\n",n);
}