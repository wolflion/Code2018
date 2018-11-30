#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

// **返回值不是函数重载的条件**

template<typename T>
T MyAdd(T a, T b)
{
	return a + b;
}

// 这里编译器会做自动类型转化
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
	cout << MyAdd(c1, c2)<<endl;  // 这个屏幕上没有输出，应该是发生溢出了
	*/
	char c1 = '1';
	char c2 = '2';

	cout << MyAdd(a, b)<< endl;
	cout << MyAdd(c1, c2)<<endl;
	cout << MyAdd(a, c1)<< endl;  // 这个调用普通函数
}


int main()
{

	testfunction();

	system("pause");
	return EXIT_SUCCESS;
}