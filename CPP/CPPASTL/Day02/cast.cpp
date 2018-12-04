#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Building{};
class Animal{};
class Cat :public Animal{};

// static_cast
void testStatic()
{
	int a = 12;  // ����10ʱ��cout��û�У�����12
	// ʹ�ù���
	char c = static_cast <char>(a);

	cout << c << endl;

	// �����������͵�ָ��
	//int *p = NULL;
	// char *sp = static_cast<char*>(p);  // �������

	// ����ָ��
	//Building* building = NULL;
	//Animal* animal = static_cast<Animal*>(building);  // ���Ҳ����

	// ת�����м̳й�ϵ�Ķ���ָ��
	// ����ָ��ת����ָ��
	Animal* animal = NULL;
	Cat* cat = static_cast<Cat*>(animal);

	// ����ָ��ת�ɸ���ָ��
	Cat* son = NULL;
	Animal* parent = static_cast<Animal*>(son);

	// ����
	Animal ani;
	Animal& aniref = ani;
	Cat& sonref = static_cast<Cat&>(aniref);

	Cat catobj;
	Cat& catref = catobj;
	Animal& anifather2 = static_cast<Animal&>(catref);

	// static_cast�������õ��������ͣ����о��м̳й�ϵ��ָ�������
}

// dynamic_cast ��ת�����м̳й�ϵ��ָ������ã���ת��ǰ����ж������ͼ��
void testDynamic()
{
	// �����������Ͳ���ת��
	//int a = 12;
	//char c = dynamic_cast<char>(a);

	// �Ǽ̳й�ϵ��ָ�������
	//Animal* ani = NULL;
	//Building* building = dynamic_cast<Building*>(ani);

	//�̳й�ϵ��ָ�������
	//Animal* ani = NULL;
	//Cat* cat = dynamic_cast<Cat*>(ani); // ��Ϊdynamic_cast������ȫ���ͼ��
	// ����丸�࣬û�����⣻�����ൽ���࣬�������⣬�в���û�и�ֵ��
	// ����ָ�����ת��Ϊ����ָ�루�Ӵ�С�������Ͱ�ȫ
	// ����ָ��ת������ָ�루��С���󣩣�����ȫ

	Cat* cat2 = NULL;
	Animal* ani = dynamic_cast<Animal*>(cat2);

	// ���ۣ�dynamicֻ��ת�����м̳й�ϵ��ָ������ã�����ֻ����������ת���ɸ����������͡�
}

// const_cast ָ�� ���� ���߶���ָ��
void testConst()
{
	// 1��������������
	int a = 10;
	const int&b = a;
	// b=10;
	int&c = const_cast<int&>(b);  // ���ǰѱ����constȡ�����������±���ȥ��
	c = 20;
	cout << "a:"<< a << endl;
	cout << "b:" << b << endl;
	cout << "c:" << c << endl;  // 3��ֵ����20

	// 2��ָ������
	const int* p = NULL;
	int *t = const_cast<int*>(p);

	int* p2 = NULL;
	const int* t1 = const_cast<const int*>(p2);
	// ���ӻ���ȥ��������const��
}

// reinterpret_cast ǿ������ת��

typedef void(*FUNC1)(int,int);  // ����ָ��  ��д*FUNC1ʱ������FUNC1*func1��Ч����һ����
typedef void(*FUNC2)(int, char*);

void testReinterpret()
{
	// 1���޹ص�ָ�����Ͷ����Խ���ת��
	Building* building = NULL;
	Animal* aniRe = reinterpret_cast<Animal*>(building);

	// 2������ָ��
	FUNC1 func1;
	FUNC2 func2 = reinterpret_cast<FUNC2>(func1);
}

int main()
{
	testConst();
	testStatic();
	testDynamic();

	void testReinterpret();

	system("pause");
	return EXIT_SUCCESS;
}