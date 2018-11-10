#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top, S[1000];

void push(int x)
{
	// top��1֮��Ԫ�ز���top��ָ��λ��
	S[++top] = x;
}

int pop()
{
	top--;
	// ����top��ָ��Ԫ��
	return S[top + 1];
}

int main()
{
	int a, b;
	top = 0;
	char s[100];
	while (scanf("%s",s) != EOF)  // ��ctrl+c��������Ļ���Ҳû�������
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
���Ӧ���� -3,�����û�����
*/
