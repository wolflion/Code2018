// f0803.cpp  对象指针使用成员函数
#include <iostream>
#include <iomanip>
using namespace std;

class Date
{
public:
	void set(int y,int m, int d);
	bool isLeapYear();
	void print();
private:
	int year,month,day;
};

void Date::set(int y,int m, int d)
{
	year = y;
	month = m;
	day	= d;
}

bool Date::isLeapYear()
{
	return (year%4==0 && year%100!=0) || (year%400==0);
}

void Date::print()
{
	cout<<setfill('0');
	cout<<setw(4)<<year<<'-'<<setw(2)<<month<<'-'<<setw(2)<<day<<'\n';
	cout<<setfill(' ');
}

int main()
{
	Date *dp = new Date;  // 与f0802.cpp的区别，就在于main里
	dp->set(2000,12,6);
	if (dp->isLeapYear())
	{
		(*dp).print();
	}
}

// g++ f0803.cpp