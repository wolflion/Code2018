//f1205.cpp Ðéº¯Êý
#include <iostream>
using namespace std;

class Base
{
public:
	virtual void fn()
	{
		cout << "In Base class\n";
	}
};

class Sub:public Base{
public:
	virtual void fn()
	{
		cout << "In Sub class\n";
	}
};

void test(Base& b)
{
	b.fn();
}

int main()
{
	Base bc;
	Sub sc;
	test(bc);
	test(sc);
}


// g++ 1205.cpp

/*
In Base class
In Sub class
*/