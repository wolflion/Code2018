// f1004.cpp  调整访问控制
class Base
{
	int b1;
protected:
	int b2;
	void fb2()
	{
		b1 = 1;
	}
public:
	int b3;
	void fb3()
	{
		b1 = 1;
	}
};

class Pri:private Base{
public:
	using Base::b3;
};

int main()
{
	Pri pri;
	pri.b3 = 1;  // ok
}