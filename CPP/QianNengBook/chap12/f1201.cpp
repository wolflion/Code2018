// f1201.cpp  Inheritance & Member Overlapped
#include "student.h"
#include "graduatestudent.h"

int main()
{
	Student ds("Lo Lee undergrade");
	GraduateStudent gs;
	ds.addCourse(3,2.5);
	ds.display();
	gs.addCourse(3,3.0);
	gs.display();
}

// ����student.hû��ָ�������˼�������̫��