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
	void print()
	{
		cout << id << "\n";
	}
};

class Tutor
{
	Student s;
public:
	Tutor(Student& st) :s(st)
	{
		cout << "tutuor\n";
		s.print();
	}
};