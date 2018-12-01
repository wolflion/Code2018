// 类模板外部实现
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

template<typename T>
class Person{
public:
	// 重载左移操作符
	template<typename T>  // 没加这个的时候，类外不认为一回事，只认为这是普通成员函数
	friend ostream& operator<<(ostream& os, Person<T>&p); 

	Person(T age, T id);
	void Show();  // 编译器遇到声明，不编译

public:
	T mAge;
	T mID;
};

// error C2955: 'Person'
template<typename T>
//Person::Person(T age, T id)
Person<T>::Person(T age, T id)
{
	this->mAge = age;
	this->mID = id;
}

// error C2244
template<typename T>
//void Person::Show()
void Person<T>::Show()
{
	cout << "ID:" << mID << " Age:" << mAge << endl;
}

// 重载左移运算操作符
template<typename T>
ostream& operator<<(ostream& os, Person<T>&p)
{
	os << "ID:" << p.mID << " Age:" << p.mAge << endl;
	return os;
}


void testPerson()
{
	Person<int> p(100, 20);
	//p.Show();
	cout << p;
}

int main()
{

	testPerson();

	system("pause");
	return EXIT_SUCCESS;
}