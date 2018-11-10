// 使用sort给数组排序 
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,v[5];

	for (int i = 0; i < 5; i++)
	{
		cin >> v[i];
	}

	sort(v, v+5);

	for (int i = 0; i < 5; i++)
	{
		cout << v[i] << " ";
	}

	cout << endl;

	return 0;
}

/*
8 6 9 10 7
// 输出
6 7 8 9 10
*/