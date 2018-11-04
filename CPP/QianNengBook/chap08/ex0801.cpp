// ex0801.cpp
#include <cmath>
using namespace std;
class Point{
protected:
	double x;   // x�����
	double y;   // y�����
public:
	void Set(double ix, double iy)  // ��������
	{
		x = ix;
		y = iy;
	}

	double xOffset()
	{
		return x;
	}

	double yOffset()   // ȡy���������
	{
		return y;
	}

	double angle()    // ȡ��ļ�����
	{  
		return (180/3.14159)*atan2(y,x);
	}

	double radius()    // ȡ��ļ�����뾶
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
	p.x += 5;  // protcted������£���ô������
	p.y += 6;
}