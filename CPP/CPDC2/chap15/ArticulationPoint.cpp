#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define MAX 100000

vector<int> G[MAX];
int N;
bool visited[MAX];
int prenum[MAX], parent[MAX], lowest[MAX], timer;

void dfs(int current, int prev)
{
	// ���ʽ��current֮������ִ�еĴ���
	prenum[current] = lowest[current] = timer;
	timer++;

	visited[current] = true;

	int next;

	for (int i = 0; i < G[current].size(); i++)
	{
		next = G[current][i];
		if (!visited[next])
		{
			// ����ͨ�����current���ʽ��nextʱִ�еĴ���
			parent[next] = current;
			dfs(next, current);

			// ���next�������֮������ִ�еĴ���
			lowest[current] = min(lowest[current], lowest[next]);
		}
		else if (next != prev)
		{
			// ��current-->nextΪBack-edgeʱ�Ĵ���
			lowest[current] = min(lowest[current], prenum[next]);
		}
	}

	// ���current�������֮������ִ�еĴ���
}

void art_points()
{
	for (int i = 0; i < N; i++)
	{
		visited[i] = false;
	}
	timer = 1;
	// ����lowest
	dfs(0, -1);  // 0==root
	set<int> ap;
	int np = 0;
	for (int i = 1; i < N; i++)
	{
		int p = parent[i];
		if (p == 0)
			np++;
		else if (prenum[p] <= lowest[i])
		{
			ap.insert(p);
		}
	}

	if (np > 1)
		ap.insert(0);
	for (set<int>::iterator it = ap.begin(); it != ap.end();it++)
	{
		cout << *it << endl;
	}
}

int main()
{
	int m;
	cin >> N >> m;
	for (int i = 0; i < m; i++)
	{
		int s, t;
		cin >> s >> t;
		G[s].push_back(t);
		G[s].push_back(s);
	}
	art_points();

	return 0;
}

/*
4 4
0 1
0 2
1 2
2 3
// output
1
2
// ���Ӧ��ֻ��2���ѣ�������1��2
*/