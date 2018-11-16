//�����������ʵ�ֵ���������
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;
static const int MAX = 100000;

vector<int>G[MAX];
list<int>out;
bool V[MAX];
int N;

void dfs(int u)
{
	V[u] = true;
	for (int i = 0; i < G[u].size(); i++)
	{
		int v = G[u][i];
		if (!V[v])
			dfs(v);
	}
	out.push_back(u);
}

int main()
{
	int s, t, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		V[i] = false;

	for (int i = 0; i < M; i++)
	{
		cin >> s >> t;
		G[s].push_back(t);
	}

	for (int i = 0; i < N; i++)
	{
		if (!V[i])
			dfs(i);
	}

	for (list<int>::iterator it = out.begin(); it != out.end(); it++)
	{
		cout << *it << endl;
	}

	return 0;
}

/*
6 6
0 1
1 2
3 1
3 4
4 5
5 2
// output
2
1
0
5
4
3
// ����Ͳ�̫����
*/