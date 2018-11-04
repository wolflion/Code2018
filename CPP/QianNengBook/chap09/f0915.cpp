// f0915.cpp 类转型 实现string到Student类对象的自动转化
#include <iostream>
using namespace std;
class Student{
	string name;
public:
	Student(const string& s) :name(s){}
};

void fn(Student& s)
{
	cout << "ok\n";
}

int main()
{
	fn(string("Jenny"));
}

// g++ f0915.cpp  编译报错