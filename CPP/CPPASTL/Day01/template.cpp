#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#if 0
// int类型数据交换
void MySwap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

// double类型数据交换
void MySwap(double &a, double &b)
{
	double temp = a;
	a = b;
	b = temp;
}
#endif

// 模板技术，类型参数化，编写代码可以忽略类型

// 标识符，告诉编译器，这是个模板函数，**但只对第一个函数生效**
template<typename T>
void MySwap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

void test()
{
	int a = 100;
	int b = 200;
	// 自动类型推导，但**类模板时不能进行自动类型推导**。
	cout << "a:" << a << " b:" << b << endl;
	MySwap(a, b);
	cout << "a:" << a << " b:" << b << endl;

	//
	double da = 1.1;  // 1.0时，只显示1
	double db = 2.2;
	cout << "da:" << da << " db:" << db << endl;
	MySwap(da, db);
	cout << "da:" << da << " db:" << db << endl;


	// 2、显式指定类型
	MySwap<int>(a, b);
}


int main()
{

	test();

	system("pause");
	return 0;
}