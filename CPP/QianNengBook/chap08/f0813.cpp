// f0812.cpp  ��̬���ݳ�Ա
#include <iostream>
using namespace std;
class Student{
public:
	void set(string str)
	{
		name = str;
		++number;
	}
	void print()
	{
		cout<<name<<"-> students are"<<number<<" numbers\n" ;
	}
private:
	static int number;
	string name;
};

int Student::number = 0;  // ��̬���ݳ�Ա���������ռ�ͳ�ʼ��

void fn()
{
	Student s1;
	s1.set("Jenny");
	Student s2;
	s2.set("Randy");
	s1.print();
}

int main()
{
	Student s;
	s.set("Smith");
	fn();
	s.print();
}

//g++ f0813.cpp

/*
Jenny-> students are3 numbers
Smith-> students are3 numbers
*/