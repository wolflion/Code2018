#include "Trapzint.h"
#include <cmath>

double MyFunction::operator ()(double x)const{
	return log(1.0 + x) / (1.0 + x*x);
}

double Trapz::operator ()(double a, double b, double eps) const{
	bool done = false;  // 是Trapz类的虚函数成员
	int n = 1;
	double h = b - a;
	double tn = h*(f(a) + f(b)) / 2;    // 计算n=1时的积分值
	double t2n;

	do 
	{
		double sum = 0;
		for (int k = 0; k < n;k++)
		{
			double x = a + (k + 0.5)*h;
			sum += f(x);
		}
		t2n = (tn + h*sum) / 2.0;  // 变步长梯形法计算
		if (fabs(t2n-tn)<eps)
		{
			done = true;  // 判断积分误差
		}
		else
		{
			tn = t2n;
			n *= 2;
			h /= 2;
		}
	} while (!done);
	return t2n;
}

class Trapz :public Integration{
public:
	Trapz(const Function &f) :f(f){} // 构造函数
	virtual double operator()(double a, double b, double eps)const;
private:
	const Function &f;
};