// f1002.cpp������������
#include <iostream>
using namespace std;

class Advisor{
	int noOfMeeting;
public:
	Advisor()  {cout << "Advisor\n";}
	//Advisor()  {cout << "copy Advisor\n";}     // ԭ������ط��ִ���
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
		double totalGrade = (semesterHours*average+grade);  // �ܷ�
		semesterHours += hours;  // ����ѧʱ
		average = semesterHours?totalGrade/semesterHours:0;  // ƽ����
	}

	void display(){
		cout <<"name=\""<<name<<"\""<<",hours="<<semesterHours    // \""������"������\ת����
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

	//getQualifier()  // ԭ��û��int����ֵ
	int getQualifier()
	{
		return qualifierGrade;
	}
};

void fn(Advisor& advisor)
{
	GraduateStudent gs("Yen Kay Doodle",advisor);
	gs.display(); // �����������Ա����display�����
}

int main()
{
	Advisor da;
	fn(da);
}

// g++ f1002.cpp

// �����д𰸻����е�����ģ����� Student
/*
Advisor
copy Advisor
name="Yen Kay Doodle",hours=0,average=0
GraduateStudent
~Advisor
~Student
~Advisor
*/