// f0810.cpp  测试类作用域
#include <iostream>
using namespace std;
class X{
public:
	void f1()
	{
		m = 6;
		f2();
	}
	void f2();
private:
	int m;
};

void X::f2()
{
	cout<<"Data member: "<<m<<endl;  // X::m
	int m = 7;
	cout<<"Local Variable: "<<m<<endl;  // X::m被掩藏
	cout<<"Data member: "<<X::m<<endl;
}

int main()
{
	// 此处以下不属于类作用域但属于类定义作用域
	X x;
	x.f1();
}

//g++ f0810.cpp