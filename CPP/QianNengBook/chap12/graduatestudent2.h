// graduatestudent2.h
#ifndef  HEADER_GRADUATESTUDENT
#define  HEADER_GRADUATESTUDENT

#include <iostream>
#include "student2.h"
class Advisor{
	int noOfMeeting;
};

class GraduateStudent:public Student{
	Advisor advisor;
	int qualifierGrade;
public:
	GraduateStudent(string pName="noName"):Student(pName),qualifierGrade(0)
	{
		type = GRADUATESTUDENT;
	}
	void calcTuition()
	{
		std::cout << "GraduateStudent tuition calculation.\n";
	}
};

#endif