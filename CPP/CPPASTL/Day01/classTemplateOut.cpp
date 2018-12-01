// ��ģ���ⲿʵ��
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

template<typename T>
class Person{
public:
	// �������Ʋ�����
	template<typename T>  // û�������ʱ�����ⲻ��Ϊһ���£�ֻ��Ϊ������ͨ��Ա����
	friend ostream& operator<<(ostream& os, Person<T>&p); 

	Person(T age, T id);
	void Show();  // ����������������������

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

// �����������������
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