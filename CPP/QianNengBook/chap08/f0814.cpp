// f0814.cpp  静态成员函数
#include <iostream>
using namespace std;
class Student{
public:
	void set(string str)
	{
		name = str;
		++number;
	}
	static int printNumber()
	{
		cout<<number<<"total numbers\n";
	}
	void print()
	{
		cout<<name<<"-> students are"<<number<<" numbers\n" ;
	}
private:
	static int number;
	string name;
};

int Student::number = 0;  // 静态数据成员在类外分配空间和初始化

void fn()
{
	Student s1;
	s1.set("Jenny");
	Student s2;
	s2.set("Randy");
	s1.printNumber();
}

int main()
{
	Student s;
	s.set("Smith");
	fn();
	Student::printNumber();
}

//g++ f0814.cpp

/*
3total numbers
3total numbers
*/