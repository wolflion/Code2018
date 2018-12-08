#include "Trapzint.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	MyFunction f;
	Trapz trapz(f);

	// 计算并输出积分结果
	cout << "TRAPZ Int:" << setprecision(7) << trapz(0, 2, le - 7) << endl;
	return 0;
}