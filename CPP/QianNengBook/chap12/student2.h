// student2.h
#ifndef HEADER_STUDENT
#define HEADER_STUDENT

#include <iostream>
using std::cout;
using std::string;

class Student{
	string name;
	int semesterHours;
	double average;
public:
	enum StudentType{ STUDENT, GRADUATESTUDENT };   // 之前写成()圆括号了。
	StudentType type;
	Student(string pName = "noName"):name(pName),average(0),semesterHours(0),type(STUDENT)
	{
		//
	}

	void calcTuition()
	{
		cout << "Student tuition calculation.\n";
	}
};
#endif
// HEADER_STUDENT