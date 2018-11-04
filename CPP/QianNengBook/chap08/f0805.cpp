// f0805.cpp  重载操作符
#include <iostream>
using namespace std;

class Point
{
public:
	void set(int a,int b)  {x=a,y=b;}
	void print() const {cout<<"("<<x<<","<<y<<")\n";}
	friend Point operator+(const Point& a, const Point& b);  // 声明为friend是为了操作x,y而已
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
	(a+b).print();  // (a+b)实际是调用了operator+(a,b)
	operator+(a,b).print();
	//add(a+b).print();  // 最起码是个排版错误
	add(a,b).print();
}

//g++ f0805.cpp