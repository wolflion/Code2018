// f0901.cpp 全局和局部对象值
#include "point.h"
#include <iostream>
using namespace std;

Point t;  // 全局对象(0,0)
int main(){
	Point s;   // 局部对象 （随机值）
	cout << s << t;
}

// g++ f0901.cpp 

/*
(-682734608,32767)
(0,0)
*/