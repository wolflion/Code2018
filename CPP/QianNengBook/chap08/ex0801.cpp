// ex0801.cpp
#include <cmath>
using namespace std;
class Point{
protected:
	double x;   // x轴分量
	double y;   // y轴分量
public:
	void Set(double ix, double iy)  // 设置坐标
	{
		x = ix;
		y = iy;
	}

	double xOffset()
	{
		return x;
	}

	double yOffset()   // 取y轴坐标分量
	{
		return y;
	}

	double angle()    // 取点的极坐标
	{  
		return (180/3.14159)*atan2(y,x);
	}

	double radius()    // 取点的极坐标半径
	{
		return sqrt(x*x+y*y);
	}
};

int main()
{
	Point p;
	double x, y;

	cout << "Enter x and y:\n";
	cin >> x >> y;

	p.Set(x, y);
	p.x += 5;  // protcted的情况下，怎么操作？
	p.y += 6;
}