//f0809.cpp ��ĳ�����֯�ṹ
#include "point.h"
#include <iostream>
using namespace std;

int main()
{
	Point s, t;
	s.set(2, 5);
	t.set(3, 1);
	cout << s + t;  // (5,6)
}

// g++ f0809.cpp point.cpp