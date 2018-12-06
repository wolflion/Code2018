#include<iostream>
using namespace std;

class Complex{
public:
	friend Complex(double r=0.0,double i=0.0):real(r),imag(i){};  //构造函数
	friend Complex operator+ (const Complex &c2) const;  // 运算符+重载成员函数
	friend Complex operator- (const Complex &c2) const;  // 运算符-重载成员函数
	friend ostream& operator<< (ostream &out, const Complex &C);
private:
	double real;
	double imag;    // 复数虚部
};

Complex Complex::operator+(const Complex &c2) const{
	// 创建一个临时无名对象作为返回值  【More Effective C++里有提到 无名对象】
	return Complex(real+c2.real,imag+c2.imag);
}

Complex Complex::operator-(const Complex &c2) const{
	return Complex(real-c2.real,imag-c2.imag);
}

ostream& operator<<(ostream& out, const Complex& C){
	out<<"("<<c.real<<","<<c.imag<<")";
	return out;
}


int main()
{
	Complex c1(5,4),c2(2,10),c3;
	cout<<"c1="<<c1<<endl;
	cout<<"c2="<<c2<<endl;
	c3=c1-c2;
	cout<<"c3=c1-c2="<<c3<<endl;
	
	c3=c1+c2;
	cout<<"c3=c1+c2="<<c3<<endl;
	
	return 0;
}














