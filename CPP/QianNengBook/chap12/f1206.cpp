// f1206.cpp ´«²¥Ðéº¯Êý
#include <iostream>
#include <cmath>
using namespace std;

class Shape{
protected:
	double xCoord,yCoord;
public:
	Shape(double x, double y):xCoord(x),yCoord(y)
	{
		//
	}
	virtual double area() const
	{
		return 0.0;
	}
};

class Circle:public Shape
{
protected:
	double radius;
public:
	Circle(double x, double y, double r):Shape(x,y),radius(r)
	{
		//
	}
	double area() const
	{
		return 3.14*radius*radius;
	}
};

class Rectangle:public Shape
{
protected:
	double x2Coord,y2Coord;
public:
	Rectangle(double x1, double y1,double x2, double y2):Shape(x1,y1),x2Coord(x2),y2Coord(y2)
	{
		//
	}
	double area() const;
};

double Rectangle::area() const
{
	return abs((xCoord-x2Coord)*(yCoord-y2Coord));
}

void fun(const Shape& sp)
{
	cout << sp.area()<<"\n";
}

int main()
{
	fun(Circle(2,5,4));
	fun(Rectangle(2,4,1,2));
}

// g++ f1206.cpp
/*
50.24 
2     
*/