// f1203.cpp  类型成员和多态
#include "student2.h"
#include "graduatestudent2.h"

void fn(Student& x){
	switch (x.type)
	{
	case Student::STUDENT:   // 这个之前写成 case Student::student
		x.calcTuition();
		break;
	case Student::GRADUATESTUDENT:
		GraduateStudent& rx = static_cast<GraduateStudent&>(x);
		rx.calcTuition();
		break;
	}
}

int main()
{
	Student ds("Lo lee undergrade");
	GraduateStudent gs("Jony");
	fn(ds);
	fn(gs);
}

// g++ f1203.cpp

/*
Student tuition calculation.
GraduateStudent tuition calculation.
*/