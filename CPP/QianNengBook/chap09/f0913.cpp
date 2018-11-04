// f0913.cpp 拷贝构造函数
#include <iostream>
#include <string.h>
using namespace std;

class Person{
	char* pName;
public:
	Person(char* pN = "noName")
	{
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
	~Person()
	{
		cout << "Destructing " << pName << "\n";
		delete[] pName;
	}
};

int main()
{
	Person p1("Randy");
	Person p2(p1);
}

// 有strcpy时，得包含一下<string.h>
// g++ f0913.cpp   

/*
Constructing Randy
copy Constructing Randy
Destructing Randy
Destructing Randy
*/