// f1202.cpp ����ͬ��
#include "student.h"
#include "graduatestudent.h"

void fn(Student& x)
{
	x.display();
}

int main()
{
	Student s("Lo Lee undergrade");
	GraduateStudent gs("Jony");
	fn(s);   // ��ʾѧ����Ϣ
	fn(gs);    // ��ʾ�о�����Ϣ
}