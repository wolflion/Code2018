// f0804.cpp  重载成员函数
#include <iostream>
#include <iomanip>
//#include <string.h>  // 看来加不加这个头文件，无所谓的
using namespace std;

class Date
{
public:
	void set(int y,int m, int d);
	void set(string& s);
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

//void Date::set(const string& s)      // 这样在main里才能直接传("2005-05-15")这样的形式
void Date::set(string& s)
{
	year = atoi(s.substr(0,4).c_str());
	month = atoi(s.substr(5,2).c_str());
	day = atoi(s.substr(8,2).c_str());
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
	Date d,e;
	d.set(2000,12,6);
	//e.set("2005-05-15");  g++ error，要么通过变量，要么加上const
	string sl = "2005-05-15";
	e.set(sl);
	e.print();
	if(d.isLeapYear())
		d.print();
}

//g++ f0804.cpp