// f0807.cpp  成员操作符
#include <iostream>
using namespace std;

class Point
{
public:
	void set(int a,int b)  {x=a,y=b;}
	Point operator+(const Point& d)
	{
		Point s;
		s.set(x+d.x,y+d.y);
		return s;
	}
	friend ostream& operator<<(ostream& o, const Point& d);	
private:
	int x,y;
};

inline ostream& operator<<(ostream& o, const Point& d)
{
	return o<<"("<<d.x<<", "<<d.y<<")\n";
}

int main()
{
	Point s,t;
	s.set(2,5);
	t.set(3,1);
	cout << s+t;  // 可以看作是cout << s.operator+(t)
}

//g++ f0807.cpp