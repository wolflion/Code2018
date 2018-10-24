#include "ppoint.h"
#include <cmath>
using namespace std;

PPoint::PPoint(double ix, double iy)
{
	x = ix;
	y = iy;
}

double PPoint::xOffset(){
	return x;
}

double PPoint::yOffset(){
	return y;
}

double PPoint::angle(){
	return (180 / 3.14159)*atan2(y, x);
}

double PPoint::radius(){
	return sqrt(x*x + y*y);
}