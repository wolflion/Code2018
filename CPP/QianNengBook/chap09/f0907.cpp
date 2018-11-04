// f0907.cpp 类成员的初始化
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
	Student(string n = "noName", int ssID = 0) :id(ssID), name(n)
	{
		cout << "Constructing student " << n <<"\n";
	}
};

int main()
{
	Student s("Randy", 58);
	Student t("Jenny");
}

// g++ f0907.cpp

/*
Assigning student id 58
Constructing student Randy
Assigning student id 0
Constructing student Jenny
*/