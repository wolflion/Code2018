class Function
{
public:
	virtual double operator()(double x) const = 0;  // 纯虚函数重载运算符{}
	virtual ~Function(){}
};

class MyFunction :public Function{
public:
	virtual double operator()(double x)const;  // 覆盖基类函数
};

class Integration{
public:
	virtual double operator()(double a, double b, double eps) const = 0;
	virtual ~Integration(){}
};

class Trapz :public Integration{
public:
	Trapz(const Function &f) :f(f){} // 构造函数
	virtual double operator()(double a, double b, double eps)const;
private:
	const Function &f;
};