#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#if 0
// int�������ݽ���
void MySwap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

// double�������ݽ���
void MySwap(double &a, double &b)
{
	double temp = a;
	a = b;
	b = temp;
}
#endif

// ģ�弼�������Ͳ���������д������Ժ�������

// ��ʶ�������߱����������Ǹ�ģ�庯����**��ֻ�Ե�һ��������Ч**
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
	// �Զ������Ƶ�����**��ģ��ʱ���ܽ����Զ������Ƶ�**��
	cout << "a:" << a << " b:" << b << endl;
	MySwap(a, b);
	cout << "a:" << a << " b:" << b << endl;

	//
	double da = 1.1;  // 1.0ʱ��ֻ��ʾ1
	double db = 2.2;
	cout << "da:" << da << " db:" << db << endl;
	MySwap(da, db);
	cout << "da:" << da << " db:" << db << endl;


	// 2����ʽָ������
	MySwap<int>(a, b);
}


int main()
{

	test();

	system("pause");
	return 0;
}