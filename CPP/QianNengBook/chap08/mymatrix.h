//mymatrix.h
#ifndef HEADER_MATRIX
#define HEADER_MATRIX
class Vector;
class Matrix{
	int* m;   
	int szl,szr;
public:
	void set(int,int);
	void remove() { delete[]m; }
	int sizeL() { return szl; }
	int sizeR() { return szr; }
	int& elem(int,int);
	friend Vector multiply(const Matrix& m, const Vector& v);
};
#endif