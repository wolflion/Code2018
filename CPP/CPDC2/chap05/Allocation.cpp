#include <iostream>
using namespace std;
#define MAX 100000
typedef long long llong;

int n, k;
llong T[MAX];

// k�����������ΪP�Ŀ�����װ���ٻ��
int check(llong P)
{
	int i = 0;
	for (int j = 0; j < k;j++)
	{
		llong s = 0;
		while (s +T[i] <=P)
		{
			s += T[i];
			i++;
			if (i == n)
				return n;
		}
	}
	return i;
}

int solve()
{
	llong left = 0;
	llong right = 100000 * 10000;  // ������*1��������������
	llong mid;
	while (right-left>1)
	{
		mid = (left + right) / 2;
		int v = check(mid);  // mid==���mid==Pʱ��װ���ٻ���
		if (v >= n)
			right = mid;
		else
			left = mid;
	}
	return right;
}

main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> T[i];
	llong ans = solve();
	cout << ans << endl;
}

/*
5 3
8
1
7
3
9
// ���
10   // 10������Ľ����
*/