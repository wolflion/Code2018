//f1207.cpp Ğéº¯ÊıÎóÓÃ
#include <iostream>
using namespace std;

class Base
{
public:
	virtual void fn(int x)
	{
		cout << "In Base class, int x = "<< x<<"\n";
	}
};

class Sub:public Base{
public:
	virtual void fn(double x)
	{
		cout << "In Sub class,double x ="<<x<<"\n";
	}
};

void test(Base& b)
{
	b.fn(2);
	b.fn(3.5);
}

int main()
{
	test(Base());
	test(Sub());
}


// g++ 1207.cpp

/*
*/