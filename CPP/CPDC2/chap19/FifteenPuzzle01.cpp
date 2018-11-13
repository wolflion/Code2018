// 用IDA*实现搜索
// Iterative Deepening
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>
#include <cassert>
using namespace std;
#define N 4
#define N2 16
#define LIMIT 100

static const int dx[4] = { 0, -1, 0, 1 }; 
static const int dy[4] = { 1, 0, -1, 0 };
static const char dir[4] = { 'r', 'u','l', 'd' };

int MDT[N2][N2];

struct Puzzle 
{
	int f[N2], space, MD;
};

Puzzle state;
int limit;  // 深度限制
int path[LIMIT];

int getAllMD(Puzzle pz)
{
	int sum = 0;
	for (int i = 0; i < N2;i++)
	{
		if (pz.f[i] == N2)
			continue;
		sum += MDT[i][pz.f[i] - 1];
	}
	return sum;
}

bool isSolved()
{
	for (int i = 0; i < N2;i++)
	{
		if (state.f[i] != i + 1)
			return false;
	}
	return true;
}

bool dfs(int depth, int prev)
{
	if (state.MD == 0)
		return true;

	// 如果当前深度加上启发超过了限制，则进行剪枝
	if (depth + state.MD>limit)
		return false;

	int sx = state.space / N;
	int sy = state.space % N;

	Puzzle tmp;

	for (int r = 0; r < 4; r++)
	{
		int tx = sx + dx[r];
		int ty = sy + dy[r];

		if (tx<0 || ty<0||tx>=N||ty>=N)
			continue;
		if (max(prev, r) - min(prev,r)==2)
			continue;
		tmp = state;

		// 计算曼哈顿距离的差值，同时交换拼图块
		state.MD -= MDT[tx*N + ty][state.f[tx*N + ty] - 1];
		state.MD += MDT[sx*N + sy][state.f[tx*N + ty] - 1];
		swap(state.f[tx*N + ty], state.f[sx*N + sy]);
		state.space = tx*N + ty;
		if (dfs(depth + 1, r))
		{
			path[depth] = r;
			return true;
		}
		state = tmp;
	}
	return false;
}

// 迭代加深
string iterative_deepening(Puzzle in)
{
	in.MD = getAllMD(in);  // 初始状态的曼哈顿距离

	for (limit = in.MD; limit <= LIMIT; limit++)
	{
		state = in;
		if (dfs(0, -100))
		{
			string ans = "";
			for (int i = 0; i < limit; i++)
				ans += dir[path[i]];
			return ans;
		}
	}
	return "unsolvable";
}

int main()
{
	for (int i = 0; i < N2; i++)
		for (int j = 0; j < N2;j++)
		{
			MDT[i][j] = abs(i / N - j / N) + abs(i%N - j%N);
		}
	Puzzle in;

	for (int i = 0; i < N2;i++)
	{
		cin >> in.f[i];
		if (in.f[i] == 0)
		{
			in.f[i] = N2;
			in.space = i;
		}
	}
	string ans = iterative_deepening(in);
	cout << ans.size() << endl;

	return 0;
}

/*
1 2 3 4
6 7 8 0
5 10 11 12
9 13 14 15
// output
8
*/