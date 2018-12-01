#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>  // 开始忘记引用这个，然后报std::string的错
using namespace std;

// 类内实现
template<typename T1, typename T2>
class Person{
public:
	Person(T1 name, T2 age)
	{
		this->mName = name;
		this->mAge = age;
	}
	void Show()
	{
		cout << "Name:" << this->mName << " Age:" << this->mAge<<endl;
	}
public:
	T1 mName;
	T2 mAge;
};

void testPerson()
{
	Person<string, int> p("AAA", 20);
	p.Show();
}


int main()
{

	testPerson();

	system("pause");
	return EXIT_SUCCESS;
}