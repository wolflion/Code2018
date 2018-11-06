//f1209.cpp 孤立的类
#include <iostream>
using namespace std;
#include "savings.h"
#include "checking.h"

int main()
{
	Savings s1("3277", 3000), s2("3279", 5000);
	Checking c1("888"), c2("398", 10000);
	s1.deposit(100);
	c1.deposit(2000);
	s2.withdrawal(2500);
	c2.withdrawal(1555.5);
	s1.display();
	c1.display();
}

//  g++ f1209.cpp checking.cpp savings.cpp  必须要这样才能编译成功，跟答案还有点差距



/*
Savings Account:3277 = 3100
Checking Account:888 = 2000
*/