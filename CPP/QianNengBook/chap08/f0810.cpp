// f0810.cpp  ������������
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
	cout<<"Local Variable: "<<m<<endl;  // X::m���ڲ�
	cout<<"Data member: "<<X::m<<endl;
}

int main()
{
	// �˴����²������������������ඨ��������
	X x;
	x.f1();
}

//g++ f0810.cpp