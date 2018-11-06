//f1208.cpp Ðéº¯Êý³ÌÐò
#include <iostream>
using namespace std;

class Base
{
public:
	virtual Base* afn()
	{
		cout << "In Base class\n";
		return this;
	}
};

class Sub :public Base{
public:
	Sub* afn()
	{
		cout << "In Sub class\n";
		return this;
	}
};

void test(Base& x)
{
	Base b;
	b = x.afn();
}

int main()
{
	test(Base());
	test(Sub());
}


// g++ 1208.cpp

/*
In Base class
In Sub class
*/