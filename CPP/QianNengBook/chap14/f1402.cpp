//f1402.cpp 模板参数匹配的问题
#include <iostream>
using namespace std;

template <typename T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

int add(double a, double b)
{
	return a+b;
}

int main()
{
	int ia=3;
	double db = 5.0;
	char s1[] = "good",s2[]="better";
	int x = add(ia,db); // ok
	cout<<x;
	return 0;
}