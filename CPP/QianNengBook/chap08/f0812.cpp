// f0812.cpp  误用数据成员
#include <iostream>
using namespace std;
class Student{
public:
	void set(string str)
	{
		static int number = 0;
		name = str;
		n = ++number;
	}
	void print()
	{
		cout<<name<<"-> students are"<<n<<" numbers\n" ;
	}
private:
	int n;
	string name;
};

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

//g++ f0812.cpp