//f0917.cpp 拷贝构造函数
#include <iostream>
#include <string.h>
using std::string;
//#include <cstring>  https://blog.csdn.net/gogo_fighting_jxccj/article/details/45308179
using namespace std;

class Person{
	char* pName;
public:
	Person(char* pN = "noName"){
		cout << "Constructing " << pN << "\n";
		pName = new char[strlen(pN) + 1];
		if (pName)
			strcpy(pName, pN);
	}
	Person(const Person& s)
	{
		cout << "copy Constructing " << s.pName << "\n";
		pName = new char[strlen(s.pName) + 1];
		if (pName)
			strcpy(pName, s.pName);
	}

	Person& operator=(Person& s)
	{
		cout << "Assigning " << s.pName << "\n";
		if (this == &s)
			return s;
		delete[] pName;
		pName = new char[strlen(s.pName) + 1];
		if (pName)
			strcpy(pName, s.pName);
		return *this;
	}

	~Person(){
		cout << "Destructing " << pName << "\n";
		delete[] pName;
	}
};

int main(){
	Person p1("Randy");
	Person p2("Jenny");
	p2 = p1;
}

// g++ f0917.cpp  虽然有告警，但还是生成了，可以执行
/*
f0917.cpp:45:19: warning: ISO C++ forbids converting a string constant to ‘char*’ [-Wwrite-strings]
Person p2("Jenny");
*/

/*
Constructing Randy
Constructing Jenny
Assigning Randy
Destructing Randy
Destructing Randy
*/