#include<stdio.h>
int n, A[50];

// 从输入值M中减去所选元素的递归函数
int solve(int i, int m)
{
	if (m == 0)
		return 1;
	if (i >= n)
		return 0;
	int res = solve(i + 1, m) || solve(i + 1, m - A[i]);
	return res;
}

int main()
{
	int i, q, M;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}

	scanf("%d", &q);
	for (i = 0; i < q; i++)
	{
		scanf("%d", &M);
		if (solve(0, M))
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}


/*
5
1 5 7 10 21
4
2 4 17 8
// 输出
no
no
yes
yes
*/