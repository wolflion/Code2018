// f0902.cpp 使用PPoint
#include "ppoint.h"
#include <iostream>
using namespace std;

int main()
{
	for (double x, y; cout << "Enter x and y:\n" && cin >> x >> y && x >= 0;)
	{
		PPoint p(x, y);  // 构造函数，对象的初始化能够一次解决
		cout << "angle=" << p.angle() << ",radius=" << p.radius() << ",x offset="
			<< p.xOffset() << ", y offset=" << p.yOffset() << "\n";
	}
}

//  g++ f0902.cpp ppoint.cpp