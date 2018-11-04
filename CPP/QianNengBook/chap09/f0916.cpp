// f0916.cpp 模棱两可的转换
#include <iostream>
using namespace std;
class Student{
	string name;
public:
	Student(string& n="noName") :name(n){}
};

class Teacher
{
	string name;
public:
	Teacher(string& n = "noName") :name(n){}
};

void addCourse(Student& s);
void addCourse(Teacher& t);

int main()
{
	addCourse(Teacher("Prof.DingleBerry"));
	//addCourse("Prof.DingleBerry");  // 错
}

// g++ f0916.cpp  编译也报错