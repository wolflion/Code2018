// f0903.cpp 构造函数重载
#include <iostream>
#include <iomanip>
using namespace std;

class Date
{
	int year, month, day;
public:
	Date(int y = 2000, int m = 1,int d = 1);  // 设置默认参数
	Date(const string& s);   // 重载
	bool isLeapYear() const;
	friend ostream& operator<<(ostream& o, const Date& d);
};

Date::Date(const string& s)
{
	year = atoi(s.substr(0, 4).c_str());
	month = atoi(s.substr(5, 2).c_str());
	day = atoi(s.substr(8, 2).c_str());
}

Date::Date(int y, int m, int d)
{
	year = y, month = m, day = d;
}

bool Date::isLeapYear()const{
	return(year % 4 == 0 && year % 100) || year % 400 == 0;
}

ostream& operator<<(ostream& o, const Date& d){
	o << setfill('0') << setw(4) << d.year << '-' << setw(2) << d.month << '-';
	return o << setw(2) << d.day << '\n' << setfill(' ');
}

int main()
{
	Date c("2005-12-28");
	Date d(2003, 12, 6);
	Date e(2002);       // 默认两个参数
	Date f(2002, 12);   // 默认一个参数
	Date g;             // 默认三个参数   【无参对象定义】
	cout << c << d << e << f << g;
}

// g++ f0903.cpp

/*
2005-12-28
2003-12-06
2002-01-01
2002-12-01
2000-01-01
*/