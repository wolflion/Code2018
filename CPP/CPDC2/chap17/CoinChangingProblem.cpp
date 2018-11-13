#include <iostream>
#include <algorithm>

using namespace std;

static const int MMAX = 20;
static const int NMAX = 50000;
static const int INFTY = (1 << 29);

main()
{
	int n, m;
	int C[21];
	int T[NMAX + 1];

	cin >> n >> m;

	for (int i = 1; i <= m; i++)
		cin >> C[i];

	for (int i = 0; i <= NMAX; i++)
		T[i] = INFTY;
	T[0] = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j + C[i] <= n; j++)
			T[j + C[j]] = min(T[j + C[i]], T[j] + 1);
	}

	cout << T[n] << endl;
	return 0;
}

/*
15 6
1 2 7 8 12 50
// output，应该是2才对啊
536870912
*/