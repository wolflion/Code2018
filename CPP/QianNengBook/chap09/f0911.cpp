// f0911.cpp 创建对象需要额外内存
#include <iostream>
#include <string.h>
using namespace std;

class Person
{
	char* pName;
public:
	Person(char* pN = "noName")
	{
		cout << "Constructing " << pN << "\n";
		pName = new char[strlen(pN) + 1];
		if (pName)
			strcpy(pName, pN);  // g++时这个地方得引用<string.h>一下
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
	Person p2;
}

// g++ f0911.cpp

/*
Constructing Randy
Constructing noName
Destructing noName
Destructing Randy
*/