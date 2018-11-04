//myvector.h
#ifndef HEADER_VECTOR
#define HEADER_VECTOR
class Matrix;
class Vector{
	int* v;   // 指向一个数组，表示向量
	int sz;
public:
	void remove() { delete[]v; }
	void set(int);
	int& operator[](int);
	int size() { return sz; }
	void display();
	friend Vector multiply(const Matrix& m, const Vector& v);
};
#endif