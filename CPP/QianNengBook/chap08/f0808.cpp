// f0808.cpp  公有数据成员的一个较差的设计例
#include <iostream>
#include <iomanip>
using namespace std;

class Date
{
public:
	int year,month,day;
};

void print(Date);
bool isLeapYear(Date d);

int main()
{
	Date d;
	d.year = 2000;
	d.month = 12;
	d.day = 6;
	if(isLeapYear(d))
		print(d);
}

void print(Date s)
{
	cout<<setfill('0');
	cout<<setw(4)<<s.year<<'-'<<setw(2)<<s.month<<'-'<<setw(2)<<s.day<<'\n';
	cout<<setfill(' ');
}

bool isLeapYear(Date d)
{
	return (d.year%4==0 && d.year%100!=0) || (d.year%400==0);
}

//g++ f0808.cpp