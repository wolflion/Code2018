#include <iostream>
using namespace std;
#define  MAX 100000

int parent(int i)
{
	return i / 2;
}

int left(int i)
{
	return 2 * i;
}

int right(int i)
{
	return 2 * i + 1;
}

int main()
{
	int H, i, A[MAX + 1];   // 数组为1起点，所以加1

	cin >> H;
	for (i = 1; i <= H;i++)
	{
		cin >> A[i];
	}

	for (i = 1; i <= H;i++)
	{
		cout << "node " << i << ": key = " << A[i] << ", ";
		if (parent(i) >= 1)
			cout << "parent key = " << A[parent(i)] << ", ";
		if (left(i) <= H)
			cout << "left key = " << A[left(i)] << ", ";
		if (right(i) <= H)
			cout << "right key = " << A[right(i)] << ", ";
		cout << endl;
	}
	return 0;
}

/*
5
7 8 1 2 3
//output
node 1: key = 7, left key = 8, right key = 1,
node 2: key = 8, parent key = 7, left key = 2, right key = 3,
node 3: key = 1, parent key = 7,
node 4: key = 2, parent key = 8,
node 5: key = 3, parent key = 8,
*/