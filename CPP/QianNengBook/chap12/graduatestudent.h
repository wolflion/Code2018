#ifndef  HEADER_GRADUATESTUDENT
#define  HEADER_GRADUATESTUDENT

#include <iostream>
#include "student.h"
class Advisor{
	int noOfMeeting;
};

class GraduateStudent:public Student{
	Advisor advisor;
	int qualifierGrade;
public:
	GraduateStudent(string pName="noName"):Student(pName),qualifierGrade(0)
	{
		//
	}
	int getQualifier()
	{
		return qualifierGrade;
	}
	void display()
	{
		Student::display();
		std::cout<<" qualifierGrade=" << qualifierGrade<<"\n";
	}
};

#endif