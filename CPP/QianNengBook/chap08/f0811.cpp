// f0811.cpp 使用PPoint类
#include "ppoint.h"
#include <iostream>
using namespace std;

int main()
{
	PPoint p;
	// 重复输入x和y轴分量，直到x分量值小于0
	for (double x, y; cout << "Enter x and y:\n" && cin >> x >> y && x >= 0;)
	{
		p.set(x, y);
		cout << "angle=" << p.angle() << ",radius=" << p.radius()
			<< ",x offset=" << p.xOffset() << ",y offset=" << p.yOffset() << "\n";
	}
}

// g++ f0811.cpp ppoint.cpp

/*
Enter x and y:
10 10
angle=45,radius=14.1421,x offset=10,y offset=10
Enter x and y:
50 0
angle=0,radius=50,x offset=50,y offset=0
Enter x and y:
-1 1
*/