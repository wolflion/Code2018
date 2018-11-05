// circle_inher.h
#ifndef HEADER_CIRCLE_INHER
#define HEADER_CIRCLE_INHER

#include "point.h"

class Circle : class Point{
	double radius;
public:
	Circle(const Point& p=Point(),double r=0);
	double getRadius()const;
	Point getPoint() const;
	double getArea()const;
	double getCircum() const;
	void moveTo(double a, double b);
	void modifyRadius(double r);
};

#endif 
