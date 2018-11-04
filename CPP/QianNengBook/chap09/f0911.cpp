// f0911.cpp ����������Ҫ�����ڴ�
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
			strcpy(pName, pN);  // g++ʱ����ط�������<string.h>һ��
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