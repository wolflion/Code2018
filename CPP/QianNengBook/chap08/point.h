//point.h
#ifndef HEADER_POINT
#define HEADER_POINT
#include <iostream>
using namespace std;
class Point{
	int x, y;   
public:
	void set(int a, int b);
	Point operator+(const Point& d);
	friend ostream& operator<<(ostream& o, const Point& d);
};

inline ostream&  operator<<(ostream& o, const Point& d)
{
	return o << '(' << d.x << ',' << d.y << ')' << '\n';
}
#endif