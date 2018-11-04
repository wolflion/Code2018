//f0914.cpp  Îö¹¹µÄË³Ğò
#include <iostream>
using namespace std;

class A{
public:
	A(){ cout << "A->"; }
	~A(){ cout << "<-~A"; }
};

class B{
public:
	B(){ cout << "B->"; }
	~B(){ cout << "<-~B"; }
};

class C{
public:
	C(){ cout << "C->"; }
	~C(){ cout << "<-~C"; }
};

void func()
{
	cout << "\nfunc: ";
	A a;
	cout << "ok->";
	static B b;
	C c;
}

int main()
{
	cout << "main: ";
	for (int i = 1; i <= 2; ++i)
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

// g++ f0914.cpp

/*
main: A-><-~AA-><-~AB-><-~BC-><-~CC-><-~CB-><-~B
func: A->ok->B->C-><-~C<-~A
func: A->ok->C-><-~C<-~A<-~B
*/