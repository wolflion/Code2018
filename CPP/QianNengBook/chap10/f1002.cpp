// f1002.cpp　构造派生类
#include <iostream>
using namespace std;

class Advisor{
	int noOfMeeting;
public:
	Advisor()  {cout << "Advisor\n";}
	//Advisor()  {cout << "copy Advisor\n";}     // 原文这个地方又错了
	Advisor(Advisor&)  {cout << "copy Advisor\n";}
	~Advisor()  {cout<<"~Advisor\n";}
};

class Student{
	string name;
	int semesterHours;
	double average;
public:
	Student(string pName = "noName"):name(pName),average(0),semesterHours(0){}
	void addCourse(int hours, double grade){
		double totalGrade = (semesterHours*average+grade);  // 总分
		semesterHours += hours;  // 总修学时
		average = semesterHours?totalGrade/semesterHours:0;  // 平均分
	}

	void display(){
		cout <<"name=\""<<name<<"\""<<",hours="<<semesterHours    // \""中两个"是由于\转义了
			<<",average="<<average<<"\n";
	}

	int getHours(){
		return semesterHours;
	}

	double getAverage()
	{
		return average;
	}

	~Student()
	{
		cout << "~Student\n";
	}
};

class GraduateStudent:public Student{
	Advisor advisor;
	int qualifierGrade;
public:
	GraduateStudent(const string& pN, Advisor& adv):Student(pN),advisor(adv),qualifierGrade(0)
	{

	}

	void display()
	{
		Student::display();
		cout<<"GraduateStudent\n";
	}

	//getQualifier()  // 原文没有int返回值
	int getQualifier()
	{
		return qualifierGrade;
	}
};

void fn(Advisor& advisor)
{
	GraduateStudent gs("Yen Kay Doodle",advisor);
	gs.display(); // 调用派生类成员函数display的语句
}

int main()
{
	Advisor da;
	fn(da);
}

// g++ f1002.cpp

// 跟书中答案还是有点区别的，少了 Student
/*
Advisor
copy Advisor
name="Yen Kay Doodle",hours=0,average=0
GraduateStudent
~Advisor
~Student
~Advisor
*/