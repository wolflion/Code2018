// f090901.cpp 测试全局对象的创建顺序
#include "student.h"
Student ra(18);

Tutor je(ra);
int main()
{
	//
}

/*
student
tutuor
18
*/