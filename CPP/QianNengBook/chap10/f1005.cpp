// f1005.cpp  ×éºÏ³É¼Ì³Ð
#include "circle_compos.h"
//#include "circle_inher.h"
#include <iostream>
using namespace std;

int main()
{
	Point a(2.3,5.6);
	Circle c(a,7);
	c.moveTo(1,2);
	c.modifyRadius(3);
	cout << "The radius is "<< c.getRadius()<<"\n";
	cout <<"The point is " << c.getPoint();
	cout << "The area is "<<c.getArea()<<"\n";
	cout << "The circumference is "<<c.getCircum()<<"\n";
}

// g++ f1005.cpp circle_compos.cpp point.cpp

/*
The radius is 3
The point is (1,2)
The area is 28.2743
The circumference is 18.8496
*/