// f1001.cpp　继承
#include <iostream>
using namespace std;

class Advisor{
	int noOfMeeting;
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
};

class GraduateStudent:public Student{
	Advisor advisor;
	int qualifierGrade;
public:
	int getQualifier()
	{
		return qualifierGrade;
	}
};

int main()
{
	Student ds("Lo Lee undergrade");
	GraduateStudent gs;
	ds.addCourse(3,2.5);
	ds.display();
	gs.addCourse(3,3.0);
	gs.display();
}

// g++ f1001.cpp

/*
name="Lo Lee undergrade",hours=3,average=0.833333
name="noName",hours=3,average=1
*/