#include <iostream>
#include <cassert>
using namespace std;

#define N 8
#define FREE -1
#define NOT_FREE 1

int row[N], col[N], dpos[2 * N - 1], dneg[2 * N - 1];

bool X[N][N];

void initialize()
{
	for (int i = 0; i < N; i++)
	{
		row[i] = FREE;
		col[i] = FREE;
	}
	for (int i = 0; i < 2 * N - 1; i++)
	{
		dpos[i] = FREE;
		dneg[i] = FREE;
	}
}

void printBoard()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (X[i][j])
			{
				if (row[i] != j)
					return;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << ((row[i] == j) ? "Q" : ".");
		}
		cout << endl;
	}
}

void recursive(int i)
{
	// 成功放置皇后
	if (i == N)
	{
		printBoard();
		return;
	}

	for (int j = 0; j < N; j++)
	{
		// 如果(i,j)受到其他皇后攻击，则忽略该格子
		if (NOT_FREE == col[j] ||
			NOT_FREE == dpos[i+j] ||
			NOT_FREE == dneg[i-j+N-1])
			continue;

		// 在(i,j)放置皇后
		row[i] = j;
		col[j] = dpos[i + j] = dneg[i - j + N - 1] = NOT_FREE;
		// 尝试下一行
		recursive(i + 1);

		// (i,j）拿掉摆放在(i,j）的皇后
		row[i] = col[j] = dpos[i + j] = dneg[i - j + N - 1] = FREE;
	}
	// 皇后放置失败
}

int main()
{
	initialize();
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			X[i][j] = false;

	int k;
	cin >> k;
	for (int i = 0; i < k;i++)
	{
		int r, c;
		cin >> r >> c;
		X[r][c] = true;
	}

	recursive(0);
	return 0;
}

/*
2
2 2
5 3
// output
......Q.
Q.......
..Q.....
.......Q
.....Q..
...Q....
.Q......
....Q...
*/