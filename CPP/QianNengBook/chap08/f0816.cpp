// f0816.cpp 友元函数访问类成员
#include "mymatrix.h"
#include "myvector.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream in("in.txt");
	int x, y;
	in >> x >> y;
	Matrix ma;
	ma.set(x, y);
	for (int i = 0; i < x; ++i)
		for (int j = 0; j < x; ++j)
			in >> ma.elem(i, j);
	in >> x;
	Vector ve;
	ve.set(x);
	for (int i = 0; i < x; ++i)
		in >> ve[i];
	Vector vx = multiply(ma, ve);
	vx.display();
	vx.remove();
	ve.remove();
	ma.remove();
}

//  gcc -o f0816 f0816.cpp myvector.cpp mymatrix.cpp
