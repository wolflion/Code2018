// f1003.cpp  ���Է��ʿ���
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
		b1 = 1; // ��
		b2 = 1;
		b3 = 1;
		fb2();
		fb3();
	}
};

class FromPri:public Pri{
public:
	void test(){
		b1 = 1;  // ��
		b2 = 1;  // ��
		b3 = 1;  // ��
		fb2();   // ��
		fb3();   // ��
	}
};

class Pro:protected Base{
public:
	void test()
	{
		b1 = 1;  // ��
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
		b1 = 1;  // ��
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
		b1 = 1;  // ��
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
		b1 = 1;  // ��
		b2 = 1;  
		b3 = 1;  
		fb2();   
		fb3();   
	}
};


int main(){
	Pri priObj;
	priObj.b1 = 1;  // ��
	priObj.b2 = 1;  // ��
	priObj.b3 = 1;  // ��
	Pro proObj;
	proObj.b1 = 1;  // ��
	proObj.b2 = 1;  // ��
	proObj.b3 = 1;  // ��
	Pub pubObj;
	pubObj.b1 = 1;  // ��
	pubObj.b2 = 1;  // ��
	pubObj.b3 = 1;  
}