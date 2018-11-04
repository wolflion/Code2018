// ppoint1.cpp 极坐标版本  与ppoint.cpp接口差别一样，所以只需要把文件名改一下，重新编译一下即可
#include "ppoint.h"
#include <cmath>
using namespace std;

void PPoint::set(double ix, double iy)
{
	x = atan2(ix,iy);
	y = sqrt(ix*ix+iy*iy);
}

double PPoint::xOffset()
{
	return y*cosx(x);
}

double PPoint::yOffset()
{
	return y*sin(x);
}

double PPoint::angle()
{
	return (180 / 3.14159)*x;
}

double PPoint::radius()
{
	return y;
}