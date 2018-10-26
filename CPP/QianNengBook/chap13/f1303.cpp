#include "idate.h"
#include <iostream>

void fn(IDate& d1, IDate& d2)
{
	std::cout<<d2-d1<<"\n";
	std::cout<<++d;
}

int main()
{
	IDate& rd1 = createDate(2005,1,6);
	IDate& rd2 = createDate(2005,2,3);
	fn(rd1,rd2);
	delete &rd1;
	delete &rd2;
}