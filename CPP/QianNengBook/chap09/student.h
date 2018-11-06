//student.h
#include <iostream>
using namespace std;

class Student
{
	const int id;
public:
	Student(int d) :id(d)
	{
		cout << "student\n";
	}
	void display()
	{
		cout << id << "\n";
	}
};