// f1204.cpp �޸��û���
#include "student2.h"
#include "graduatestudent2.h"
#include "doctor.h"   // ��Ҫ�Լ�����

void fn(Student& x){
	switch (x.type)
	{
	case Student::STUDENT:   
		x.calcTuition();
		break;
	case Student::GRADUATESTUDENT:
		GraduateStudent& rx = static_cast<GraduateStudent&>(x);
		rx.calcTuition();
		break;
	case Student::Docotr:
		Doctor& rx = static_cast<Doctor&>(x);
		rx.calcTuition();
		break;
	}
}

int main()
{
	Student ds("Lo lee undergrade");
	GraduateStudent gs("Jony");
	Doctor ds("smith");
	fn(ds);
	fn(gs);
	fn(ds);
}

// g++ f1204.cpp