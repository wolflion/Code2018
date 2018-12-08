class Function
{
public:
	virtual double operator()(double x) const = 0;  // ���麯�����������{}
	virtual ~Function(){}
};

class MyFunction :public Function{
public:
	virtual double operator()(double x)const;  // ���ǻ��ຯ��
};

class Integration{
public:
	virtual double operator()(double a, double b, double eps) const = 0;
	virtual ~Integration(){}
};

class Trapz :public Integration{
public:
	Trapz(const Function &f) :f(f){} // ���캯��
	virtual double operator()(double a, double b, double eps)const;
private:
	const Function &f;
};