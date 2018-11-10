#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top, S[1000];

void push(int x)
{
	// top加1之后将元素插入top所指的位置
	S[++top] = x;
}

int pop()
{
	top--;
	// 返回top所指的元素
	return S[top + 1];
}

int main()
{
	int a, b;
	top = 0;
	char s[100];
	while (scanf("%s",s) != EOF)  // 用ctrl+c控制输入的话，也没有输出的
	{
		if (s[0] == '+')
		{
			a = pop();
			b = pop();
			push(a + b);
		}
		else if (s[0] == '-')
		{
			b = pop();
			a = pop();
			push(a - b);
		}else if (s[0] == '*')
		{
			a = pop();
			b = pop();
			push(a*b);
		}
		else
		{
			push(atoi(s));
		}
	}

	printf("%d\n", pop());

	return 0;
}

/*
1 2 + 3 4 - *
输出应该是 -3,但结果没有输出
*/
