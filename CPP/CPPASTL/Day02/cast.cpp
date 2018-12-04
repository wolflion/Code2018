#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Building{};
class Animal{};
class Cat :public Animal{};

// static_cast
void testStatic()
{
	int a = 12;  // 等于10时，cout是没有，换成12
	// 使用规则
	char c = static_cast <char>(a);

	cout << c << endl;

	// 基础数据类型的指针
	//int *p = NULL;
	// char *sp = static_cast<char*>(p);  // 这个报错

	// 对象指针
	//Building* building = NULL;
	//Animal* animal = static_cast<Animal*>(building);  // 这个也报错

	// 转换具有继承关系的对象指针
	// 父类指针转子类指针
	Animal* animal = NULL;
	Cat* cat = static_cast<Cat*>(animal);

	// 子类指针转成父类指针
	Cat* son = NULL;
	Animal* parent = static_cast<Animal*>(son);

	// 引用
	Animal ani;
	Animal& aniref = ani;
	Cat& sonref = static_cast<Cat&>(aniref);

	Cat catobj;
	Cat& catref = catobj;
	Animal& anifather2 = static_cast<Animal&>(catref);

	// static_cast用于内置的数据类型，还有具有继承关系的指针或引用
}

// dynamic_cast ，转换具有继承关系的指针或引用，在转换前会进行对象类型检查
void testDynamic()
{
	// 基础数据类型不能转换
	//int a = 12;
	//char c = dynamic_cast<char>(a);

	// 非继承关系的指针或引用
	//Animal* ani = NULL;
	//Building* building = dynamic_cast<Building*>(ani);

	//继承关系的指针或引用
	//Animal* ani = NULL;
	//Cat* cat = dynamic_cast<Cat*>(ani); // 因为dynamic_cast会做安全类型检查
	// 子类变父类，没有问题；但父类到子类，就有问题，有部分没有赋值。
	// 子类指针可以转换为父类指针（从大到小），类型安全
	// 父类指针转成子类指针（从小到大），不安全

	Cat* cat2 = NULL;
	Animal* ani = dynamic_cast<Animal*>(cat2);

	// 结论：dynamic只能转换具有继承关系的指针或引用，并且只能由子类型转换成父（基）类型。
}

// const_cast 指针 引用 或者对象指针
void testConst()
{
	// 1、基础数据类型
	int a = 10;
	const int&b = a;
	// b=10;
	int&c = const_cast<int&>(b);  // 不是把本身的const取消，而是用新变量去接
	c = 20;
	cout << "a:"<< a << endl;
	cout << "b:" << b << endl;
	cout << "c:" << c << endl;  // 3个值都是20

	// 2、指针类型
	const int* p = NULL;
	int *t = const_cast<int*>(p);

	int* p2 = NULL;
	const int* t1 = const_cast<const int*>(p2);
	// 增加或者去除变量的const性
}

// reinterpret_cast 强制类型转换

typedef void(*FUNC1)(int,int);  // 函数指针  不写*FUNC1时，定义FUNC1*func1，效果是一样的
typedef void(*FUNC2)(int, char*);

void testReinterpret()
{
	// 1、无关的指针类型都可以进行转换
	Building* building = NULL;
	Animal* aniRe = reinterpret_cast<Animal*>(building);

	// 2、函数指针
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