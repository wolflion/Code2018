// ppoint1.cpp ������汾  ��ppoint.cpp�ӿڲ��һ��������ֻ��Ҫ���ļ�����һ�£����±���һ�¼���
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