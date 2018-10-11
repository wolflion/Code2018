// f.cpp　变量的引用类型和非引用类型的区别
#include <stdio.h>
void fa(int a)
{
	a = 5;
	printf("fa : a=%d\n",a);
}

void fb(int &a)   // 标准C语法不支持引用  
{
	a = 5;
	printf("fb : a=%d\n",a);
}

void fc(int *a)   // 自己改的 *把引用改为指针
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
	fc(&n);   // 这个地方就得传地址
	printf("main : fc(n) n = %d\n",n);
}