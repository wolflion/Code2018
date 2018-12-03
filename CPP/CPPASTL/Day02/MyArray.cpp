#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

// 数组要支持各种各样的类型
template<typename T>
class MyArray{
public:
#if 0
	MyArray(int capacity);
	// 拷贝构造
	MyArray(const MyArray& arr);
	// 操作符重载
	T& operator[](int index);   // 返回当前元素的引用

	// 这个得注意一下
	MyArray<T> operator=(const MyArray<T>& arr);

	// 接口
	void PushBack(T& data);
	//void PushBack(T&& data);
#endif
	MyArray(int capacity)
	{
		this->mCapacity = capacity;
		this->mSize = 0;
		// 申请内存
		this->pAddr = new T[this->mCapacity];
	}
	// 拷贝构造
	MyArray(const MyArray& arr)
	{
		this->mSize = arr.mSize;
		this->mCapacity = arr.mCapacity;

		// 申请内存空间
		this->pAddr = new T[this->mCapacity];

		// 数据拷贝
		for (int i = 0; i < this->mSize; i++)
		{
			this->pAddr[i] = arr.[i];
		}
	}
	// 操作符重载
	T& operator[](int index)   // 返回当前元素的引用
	{
		return this->pAddr[index];
	}

	// 这个得注意一下 MyArray<T>
	MyArray<T> operator=(const MyArray<T>& arr)
	{
		if (this->pAddr != NULL)
		{
			delete[] this->pAddr;
		}

		this->mSize = arr.mSize;
		this->mCapacity = arr.mCapacity;

		// 申请内存空间
		this->pAddr = new T[this->mCapacity];

		// 数据拷贝
		for (int i = 0; i < this->mSize; i++)
		{
			this->pAddr[i] = arr.[i];
		}
		
		return *this;
	}

	// 接口
	void PushBack(T& data)
	{
		// 判断容器中是否有位置
		if (this->mSize >= this->mCapacity)
		{
			return;
		}
		// 调用拷贝构造 =号操作符
		// 1、对象元素必须能够被拷贝，不能是指针
		// 2、容器都是值寓意，而非引用寓意（就是有两份，拷贝的，而不是引用那种只有一份）
		// 3、如何元素的成员有指针，注意深拷贝和浅拷贝的问题
		this->pAddr[this->mSize] = data;
		//msize++
		this->mSize++;
	}
	/*
	void PushBack(T&& data)
	{
		// 判断容器中是否有位置
		if (this->mSize >= this->mCapacity)
		{
			return;
		}
		this->pAddr[this->mSize] = data;
		//msize++
		this->mSize++;
	}
	*/

	~MyArray()
	{
		if (this->pAddr != NULL)
		{
			delete[] this->pAddr;
		}
	}
public:
	// 数组一共可以容下多少元素
	int mCapacity;
	// 当前数组有多少元素
	int mSize;
	// 保存数据的首地址
	T* pAddr;

};

void testMyArrary()
{
	MyArray<int> marray(20);
	int a = 10, b = 20, c = 30, d = 40;
	marray.PushBack(a);
	marray.PushBack(b);
	marray.PushBack(c);
	marray.PushBack(d);

	// 不能对右值取引用，所以语法有错，所以需要T&&，C++11的特性
	// 左值 可以在多行使用
	// 临时变量 只能当前行使用

	// marray.PushBack(100);

	for (int i = 0; i < marray.mSize; i++)
	{
		cout << marray[i] << " ";
	}
	cout << endl;
}

int main()
{

	testMyArrary();

	system("pause");
	return EXIT_SUCCESS;
}