#include "mymatrix.h"
#include <iostream>
using namespace std;
void Matrix::set(int i, int j)
{
	szl = i;
	szr = j;
	if (i <= 0 || j <= 0)
	{
		cerr << "bad Matrix size.\n";
		exit(1);
	}
	m = new int[i*j];
}

int& Matrix::elem(int i, int j)
{
	if (i < 0 || szl <= i || j < 0 || szr <= j)
	{
		cerr << "Matrix index out of range.\n";
		exit(1);
	}
	return m[i*szr + j];
}

