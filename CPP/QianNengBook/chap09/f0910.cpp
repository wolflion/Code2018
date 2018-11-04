//f0910.cpp 测试成员对象的创建顺序
#include <iostream>
using namespace std;

class A{
public:
	A(int x)
	{
		cout << "A:"<<x<<"->";
	}
};

class B{
public:
	B(int x)
	{
		cout << "B:"<<x<<"->";
	}
};

class C{
	A a;
	B b;
public:
	C(int x, int y) :b(x), a(y)
	{
		cout << "C\n";
	}
};

int main()
{
	C c(15, 9);
}

// g++ 0910.cpp

/*
A:9->B:15->C
*/