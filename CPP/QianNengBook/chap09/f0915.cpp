// f0915.cpp ��ת�� ʵ��string��Student�������Զ�ת��
#include <iostream>
using namespace std;
class Student{
	string name;
public:
	Student(const string& s) :name(s){}
};

void fn(Student& s)
{
	cout << "ok\n";
}

int main()
{
	fn(string("Jenny"));
}

// g++ f0915.cpp  ���뱨��