// f0904.cpp ���캯���Ĳ��ֳ�ʼ��
#include <iostream>
#include <iomanip>
using namespace std;

class Date
{
	int year, month, day;
	void init();
public:
	Date(int y = 2000, int m = 1, int d = 1);  // ����Ĭ�ϲ���
	Date(const string& s);   // ����
	bool isLeapYear() const;
	friend ostream& operator<<(ostream& o, const Date& d);
};

void Date::init()
{
	//if (y > 5000 || y < 1 || m < 1 || m>12 || d < 1 || d>31)
	if (year > 5000 || year < 1 || month < 1 || month>12 || day < 1 || day>31)
		exit(1);  // ͣ��
}

Date::Date(const string& s)
{
	year = atoi(s.substr(0, 4).c_str());
	month = atoi(s.substr(5, 2).c_str());
	day = atoi(s.substr(8, 2).c_str());
	init();
}

Date::Date(int y, int m, int d)
{
	year = y, month = m, day = d;
	init();
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
	Date e(2002);       // Ĭ����������
	Date f(2002, 12);   // Ĭ��һ������
	Date g;             // Ĭ����������
	cout << c << d << e << f << g;
}

// g++ f0904.cpp

/*
2005-12-28
2003-12-06
2002-01-01
2002-12-01
2000-01-01
*/