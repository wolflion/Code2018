// f1003.cpp  ≤‚ ‘∑√Œ øÿ÷∆
class Base
{
	int b1;
protected:
	int b2;
	void fb2(){b1=1;}
public:
	int b3;
	void fb3(){b1=1;}
};

class Pri:private Base
{
public:
	void test()
	{
		b1 = 1; // ¥Ì
		b2 = 1;
		b3 = 1;
		fb2();
		fb3();
	}
};

class FromPri:public Pri{
public:
	void test(){
		b1 = 1;  // ¥Ì
		b2 = 1;  // ¥Ì
		b3 = 1;  // ¥Ì
		fb2();   // ¥Ì
		fb3();   // ¥Ì
	}
};

class Pro:protected Base{
public:
	void test()
	{
		b1 = 1;  // ¥Ì
		b2 = 1;  
		b3 = 1;  
		fb2();   
		fb3();   
	}
};

class FromPro:public Base
{
public:
	void test()
	{
		b1 = 1;  // ¥Ì
		b2 = 1;  
		b3 = 1;  
		fb2();   
		fb3();   
	}
};

class Pub:public Base{
public:
	void test()
	{
		b1 = 1;  // ¥Ì
		b2 = 1;  
		b3 = 1;  
		fb2();   
		fb3();   
	}
};

class FromPub:public Base{
public:
	void test()
	{
		b1 = 1;  // ¥Ì
		b2 = 1;  
		b3 = 1;  
		fb2();   
		fb3();   
	}
};


int main(){
	Pri priObj;
	priObj.b1 = 1;  // ¥Ì
	priObj.b2 = 1;  // ¥Ì
	priObj.b3 = 1;  // ¥Ì
	Pro proObj;
	proObj.b1 = 1;  // ¥Ì
	proObj.b2 = 1;  // ¥Ì
	proObj.b3 = 1;  // ¥Ì
	Pub pubObj;
	pubObj.b1 = 1;  // ¥Ì
	pubObj.b2 = 1;  // ¥Ì
	pubObj.b3 = 1;  
}