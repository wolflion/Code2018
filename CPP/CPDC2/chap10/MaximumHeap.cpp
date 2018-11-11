#include <iostream>
using namespace std;
#define  MAX 2000000

int H, A[MAX + 1];

void maxHeapify(int i)
{
	int l, r, largest;
	l = 2 * i;
	r = 2 * i + 1;

	// 从左子结点，自身，右子结点中选出值最大的结点
	if (l <= H &&A[l] > A[i])
		largest = 1;
	else
		largest = i;

	if (r <= H &&A[r] > A[largest])
		largest = r;

	if (largest != i)
	{
		swap(A[i], A[largest]);
		maxHeapify(largest);
	}
}

int main()
{
	cin >> H;
	for (int i = 1; i < H;i++)
	{
		cin >> A[i];
	}

	for (int i = H / 2; i >= 1; i--)
		maxHeapify(i);

	for (int i = 1; i <= H; i++)
	{
		cout << " " << A[i];
	}
	cout << endl;

	return 0;
}

/*
10
4 1 3 2 16 9 10 14 8 7
//output
Segmentation fault (core dumped)
*/