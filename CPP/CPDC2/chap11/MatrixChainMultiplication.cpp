#include <iostream>
#include <algorithm>
using namespace std;
static const int N = 100;

int main()
{
	int n, p[N + 1], m[N + 1][N + 1];
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i - 1] >> p[i];

	for (int i = 1; i <= n; i++)
		m[i][i] = 0;
	for (int t = 2; t <= n; t++)
	{
		for (int i = 1; i <= n - t + 1; i++)
		{
			int j = i + t - 1;
			m[i][j] = (1 << 21);
			for (int k = i; k <= j - 1;k++)  // ����ط���k <=j-1;
			{
				m[i][j] = min(m[i][j], m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]);
			}
		}
	}
	
	cout << m[1][n] << endl;

	return 0;
}

// ԭ��  https://blog.csdn.net/u013075699/article/details/78937000

/*
6
30 35
35 15
15 5
5 10
10 20
20 25
// output ������ 15125   [�ĺ���]
12582912
*/