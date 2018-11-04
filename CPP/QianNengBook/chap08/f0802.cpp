// f0802.cpp ������Ӧ�ó���
#include<iostream>
#include<iomanip>
using namespace std;

class Date{
    int year;
    int month;
    int day;
public:
    void set(int y,int m,int d);  // ��ֵ����
    bool isLeapYear();
    void print();
};  // �ඨ��

void Date::set(int y,int m,int d)
{
    year = y;
    month = m;
    day = d;
}

void Date::print()
{
    cout<<setfill('0');
    cout<<setw(4)<<year<<'-'<<setw(2)<<month<<'-'<<setw(2)<<day<<'\n';
    cout<<setfill(' ');
}

bool Date::isLeapYear() // no Date:: no year
{
    return(year %4==0 && year%100!=0)||(year%400==0);
}

int main()
{
    Date d;
    d.set(2000,12,6);
    if(d.isLeapYear())
        d.print();
}

