#include <iostream>
#include <cstdio>
#include <map>
#include <string>
using namespace std;

int main()
{
	int n;
	char str[10], com[13];
	map<string, bool>T;  // 使用标准库中的map

	cin >> n;
	for (int i = 0; i < n;i++)
	{
		scanf("%s%s", com, str);
		if (com[0] == 'i')
			T[string(str)] = true;
		else
		{
			if (T[string(str)])
			{
				printf("yes\n");
			}
			else
				printf("no\n");
		}
	}
	return 0;
}

// 原型chap5的Dictionary.c，两者的功能是一样的

/*
6
insert AAA
insert AAC
find AAA
yes
find CCC
no
insert CCC
find CCC
yes


// yes,no都是输出的，其它是输入
*/