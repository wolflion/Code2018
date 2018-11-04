//f0908.cpp 测试局部对象的创建顺序
#include <iostream>
using namespace std;

class A{
public:
	A()
	{
		cout << "A->";
	}
};

class B{
public:
	B()
	{
		cout << "B->";
	}
};

class C{
public:
	C()
	{
		cout << "C->";
	}
};

void func()
{
	cout << "\nfunc: ";
	A a; 
	static B b;
	C c;
}

int main()
{
	cout << "main: ";
	for (int i = 1; i <= 2;++i)
	{
		for (int j = 1; j <= 2; ++j)
			if (i == 2)
				C C;
			else
				A a;
		B b;
	}
	func();
	func();
}

// g++ f0908.cpp

/*
main: A->A->B->C->C->B->
func: A->B->C->
func: A->C->
*/