#include <iostream>
using namespace std;

class Date{
	int year,month,day;
protected:
	int ymd2i()const;
	void i2ymd(int n);
	void print(ostream& o)const;
	static const int tians[];
	bool isLeapYear() const
	{
		return !(year%4)&&(year%100) || !(year%400);
	}
public:
	Date(const string& s);
	Date(int n = 1)
	{
		i2ymd(n);
	}
	Date(int y,int m,int n):year(y),month(m),day(d)
	{
		//
	}
	Date operator+(int n) const
	{
		return Date(ymd2i()+n)
	}
	
	Date operator+=(int n) const
	{
		i2ymd(ymd2i()+n);
		return *this;
	}

	Date& operator++()
	{
		return *this +=1;
	}
};