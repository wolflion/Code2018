// f0906.cpp 不正确的初始化尝试
#include <iostream>
using namespace std;

class StudentID{
	int value;
public:
	StudentID(int id = 0)
	{
		value = id;
		cout << "Assigning student id " << value << "\n";
	}
};

class Student
{
	string name;
	StudentID id;
public:
	Student(string n = "noName", int ssID = 0)
	{
		cout << "Constructing student " + n + "\n";
		name = n;
		StudentID id(ssID);
	}
};

int main()
{
	Student s("Randy", 58);
}

// g++ f0906.cpp

/*
Assigning student id 0
Constructing student Randy
Assigning student id 58
*/