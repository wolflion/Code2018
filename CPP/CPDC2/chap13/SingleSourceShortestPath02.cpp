#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

static const int  MAX = 100;
static const int INFTY = (1 << 21);
static const int  WHITE = 0;
static const int  GRAY = 1;
static const int  BLACK = 2;

int n;
vector<pair<int, int>>adj[MAX];   // ��Ȩ����ͼ���ڽӱ��ʾ��

void dijkstra()
{
	priority_queue<pair<int, int>> PQ;
	int d[MAX];
	int color[MAX];

	for (int i = 0; i < n; i++)
	{
		d[i] = INFTY;
		color[i] = WHITE;
	}

	d[0] = 0;
	PQ.push(make_pair(0, 0));
	color[0] = GRAY;
	while (!PQ.empty())
	{
		pair<int, int> f = PQ.top();
		PQ.pop();
		int u = f.second;
	
		color[u] = BLACK;

		// ȡ����Сֵ������������·�������
		if (d[u]<f.first*(-1))
			continue;

		for (int j = 0; j < adj[u].size(); j++)
		{
			int v = adj[u][j].first;
			if (color[v] ==BLACK)
				continue;
			if (d[v]>d[u] + adj[u][j].second)
			{
				d[v] = d[u] + adj[u][j].second;
				//priority_queueĬ�����Ƚϴ�ֵ�����Ҫ����-1
				PQ.push(make_pair(d[v] * (-1), v));
				color[v] = GRAY;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << i << " " << ((d[i] == INFTY) ? (-1) : d[i]) << endl;
	}
}

int main()
{
	int k, c, u, v;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> u >> k;
		for (int j = 0; j < k; j++)
		{
			cin >> v >> c;
			adj[u].push_back(make_pair(v, c));
		}
	}

	dijkstra();

	return 0;
}

/*
5
0 3 2 3 3 1 1 2
1 2 0 2 3 4
2 3 0 3 3 1 4 1
3 4 2 1 0 1 1 4 4 3
4 2 2 1 3 3
//output
0 0
1 2
2 2
3 1
4 3
*/