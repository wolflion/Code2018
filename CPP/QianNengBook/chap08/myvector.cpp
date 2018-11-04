#include "myvector.h"
#include <iostream>
using namespace std;

void Vector::set(int s){
	sz = s;
	if (s <= 0)
	{
		cerr << "bad Vector size.\n";
		exit(1);
	}
	v = new int[s];
}

int& Vector::operator[](int i){  // ���÷��ص�Ŀ���Ƿ���ֵ��������ֵ
	if (i < 0 || i >= sz){
		cerr << "Vector index out of range.\n";
		exit(1);
	}
	return v[i];
}

void Vector::display(){
	for (int i = 0; i < sz; ++i)
		cout << v[i] << " ";
	cout << "\n";
}

Vector multply(const Matrix& m, const Vector& v)   // ���������
{
	if (m.szr != v.sz)
	{
		cerr << "bad multiply Matrix with Vector.\n";
		exit(1);
	}
	Vector r;
	r.set(m.szl);   //����һ����Ž���Ŀ�����
	for (int i = 0; i < m.szl; i++)
	{
		r.v[i] = 0;
		for (int j = 0; j < m.szr; j++)
			r.v[i] += m.m[i*m.szr + j] * v.v[j];
	}
	return r;
}
