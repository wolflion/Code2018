#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

// ����Ҫ֧�ָ��ָ���������
template<typename T>
class MyArray{
public:
#if 0
	MyArray(int capacity);
	// ��������
	MyArray(const MyArray& arr);
	// ����������
	T& operator[](int index);   // ���ص�ǰԪ�ص�����

	// �����ע��һ��
	MyArray<T> operator=(const MyArray<T>& arr);

	// �ӿ�
	void PushBack(T& data);
	//void PushBack(T&& data);
#endif
	MyArray(int capacity)
	{
		this->mCapacity = capacity;
		this->mSize = 0;
		// �����ڴ�
		this->pAddr = new T[this->mCapacity];
	}
	// ��������
	MyArray(const MyArray& arr)
	{
		this->mSize = arr.mSize;
		this->mCapacity = arr.mCapacity;

		// �����ڴ�ռ�
		this->pAddr = new T[this->mCapacity];

		// ���ݿ���
		for (int i = 0; i < this->mSize; i++)
		{
			this->pAddr[i] = arr.[i];
		}
	}
	// ����������
	T& operator[](int index)   // ���ص�ǰԪ�ص�����
	{
		return this->pAddr[index];
	}

	// �����ע��һ�� MyArray<T>
	MyArray<T> operator=(const MyArray<T>& arr)
	{
		if (this->pAddr != NULL)
		{
			delete[] this->pAddr;
		}

		this->mSize = arr.mSize;
		this->mCapacity = arr.mCapacity;

		// �����ڴ�ռ�
		this->pAddr = new T[this->mCapacity];

		// ���ݿ���
		for (int i = 0; i < this->mSize; i++)
		{
			this->pAddr[i] = arr.[i];
		}
		
		return *this;
	}

	// �ӿ�
	void PushBack(T& data)
	{
		// �ж��������Ƿ���λ��
		if (this->mSize >= this->mCapacity)
		{
			return;
		}
		// ���ÿ������� =�Ų�����
		// 1������Ԫ�ر����ܹ���������������ָ��
		// 2����������ֵԢ�⣬��������Ԣ�⣨���������ݣ������ģ���������������ֻ��һ�ݣ�
		// 3�����Ԫ�صĳ�Ա��ָ�룬ע�������ǳ����������
		this->pAddr[this->mSize] = data;
		//msize++
		this->mSize++;
	}
	/*
	void PushBack(T&& data)
	{
		// �ж��������Ƿ���λ��
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
	// ����һ���������¶���Ԫ��
	int mCapacity;
	// ��ǰ�����ж���Ԫ��
	int mSize;
	// �������ݵ��׵�ַ
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

	// ���ܶ���ֵȡ���ã������﷨�д�������ҪT&&��C++11������
	// ��ֵ �����ڶ���ʹ��
	// ��ʱ���� ֻ�ܵ�ǰ��ʹ��

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