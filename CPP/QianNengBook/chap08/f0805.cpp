// f0805.cpp  ���ز�����
#include <iostream>
using namespace std;

class Point
{
public:
	void set(int a,int b)  {x=a,y=b;}
	void print() const {cout<<"("<<x<<","<<y<<")\n";}
	friend Point operator+(const Point& a, const Point& b);  // ����Ϊfriend��Ϊ�˲���x,y����
	friend Point add(const Point& a, const Point& b);
private:
	int x,y;
};

Point operator+(const Point& a, const Point& b)
{
	Point s;
	s.set(a.x+b.x, a.y+b.y);
	return s;
}

Point add(const Point& a, const Point& b)
{
	Point s;
	s.set(a.x+b.x, a.y+b.y);
	return s;
}

int main()
{
	Point a,b;
	a.set(3,2);
	b.set(1,5);
	(a+b).print();  // (a+b)ʵ���ǵ�����operator+(a,b)
	operator+(a,b).print();
	//add(a+b).print();  // �������Ǹ��Ű����
	add(a,b).print();
}

//g++ f0805.cpp