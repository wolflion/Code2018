// f0905.cpp  �����Ա��Ĭ�Ϲ���
#include <iostream>
using namespace std;

class StudentID{
	int value;
public:
	StudentID(){
		static int nextStudentID = 0;
		value = ++nextStudentID;
		cout << "Assigning student id " << value << "\n";
	}
};

class Student{
	string name;
	StudentID id;
public:
	Student(string n = "noName"){
		cout << "Constructing student " + n + "\n";
		name = n;
	}
};

int main()
{
	Student s("Randy");
}

// g++ f0905.cpp

/*
Assigning student id 1
Constructing student Randy
*/