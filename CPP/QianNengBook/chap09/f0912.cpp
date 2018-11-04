// f0912.cpp 从一个对象中复制另一个对象
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
// g++ f0912.cpp   

/*
Constructing Randy
Destructing Randy
Destructing
*/