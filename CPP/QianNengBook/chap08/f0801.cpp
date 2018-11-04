// f0801.cpp ���ڽṹӦ�ó���
#include<iostream>
#include<iomanip>  // manipulator����д��del��setfill()�Ĳ�����
using namespace std;

struct Date{
    int year;
    int month;
    int day;
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
    // cout.setfill('0');  //error
    cout<<setfill('0');
    cout<<setw(4)<<s.year<<'-'<<setw(2)<<s.month<<'-'<<setw(2)<<s.day<<'\n';
    //cout.setfill(' ');  //error
    cout<<setfill(' ');
}

bool isLeapYear(Date d)
{
    return(d.year %4==0 && d.year%100!=0)||(d.year%400==0);
}
