// f1203.cpp  ���ͳ�Ա�Ͷ�̬
#include "student.h"
#include "graduatestudent.h"

void fn(Student& x){
	switch (x.type)
	{
	case Student::Student:
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