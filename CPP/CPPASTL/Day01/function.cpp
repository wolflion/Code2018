#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

// **����ֵ���Ǻ������ص�����**

template<typename T>
T MyAdd(T a, T b)
{
	return a + b;
}

// ��������������Զ�����ת��
int MyAdd(int a, char c)
{
	return a + c;
}

void testfunction()
{
	int a = 100;
	int b = 200;
	/*
	char c1 = 'a';
	char c2 = 'b';
	cout << MyAdd(c1, c2)<<endl;  // �����Ļ��û�������Ӧ���Ƿ��������
	*/
	char c1 = '1';
	char c2 = '2';

	cout << MyAdd(a, b)<< endl;
	cout << MyAdd(c1, c2)<<endl;
	cout << MyAdd(a, c1)<< endl;  // ���������ͨ����
}


int main()
{

	testfunction();

	system("pause");
	return EXIT_SUCCESS;
}