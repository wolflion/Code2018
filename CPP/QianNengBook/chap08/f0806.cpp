// f0806.cpp  Time类的operator++应用
#include <iostream>
#include <iomanip>
using namespace std;

class Time
{
public:
	void set(int h,int m,int s)  {hour=h,minute=m,second = s;}
	friend Time& operator++(Time& a);
	friend Time operator++(Time& a, int);
	friend ostream& operator<<(ostream& o, const Time& t);
private:
	int hour,minute,second;
};

Time& operator++(Time& a)
{
	if(!(a.second=(a.second+1)%60)&&!(a.minute=(a.minute+1)%60))
		a.hour = (a.hour+1)%24;
	return a;
}

Time operator++(Time& a, int)
{
	Time t(a);
	if(!(a.second=(a.second+1)%60)&&!(a.minute=(a.minute+1)%60))
		a.hour = (a.hour+1)%24;
	return t;
}

ostream& operator<<(ostream& o, const Time& t)
{
	 o<<setfill('0')<<setw(2)<<t.hour<<":"<<setw(2)<<t.minute<<":";   // error，这里少个分号
	 return o<<setw(2)<<t.second<<"\n"<<setfill(' ');   // setfill()和setw()都是 #include <iomanip>
}

int main()
{
	Time t;
	t.set(11,59,58);
	cout<<t++;
	cout<<++t;
}

//g++ f0806.cpp