#include <iostream>
#include <cstdio>
#include <map>
#include <string>
using namespace std;

int main()
{
	int n;
	char str[10], com[13];
	map<string, bool>T;  // ʹ�ñ�׼���е�map

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

// ԭ��chap5��Dictionary.c�����ߵĹ�����һ����

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


// yes,no��������ģ�����������
*/