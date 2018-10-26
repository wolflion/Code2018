// f1301.cpp  Abstract Classes
#include <iostream>
class Display{
public:
	virtual void init() = 0;
	virtual void write(char* pStr) = 0;
};

class Monochrome:public Display{
	virtual void init();             // ����
	virtual void write(char* pStr);  // ����
};

class ColorAdapter:public Display{
public:
	virtual void write(char* pStr);  // ����
};

class SVGA:public ColorAdapter{
public:
	virtual void init();             // ����
};

void Monochrome::init()
{
	//
}

void Monochrome::write(char* pStr)
{
	std::cout<<"Monochrome: "<<pStr;
}

void ColorAdapter::write(char* pStr)
{
	std::cout<<"ColorAdapter: "<<pStr;
}

void SVGA::init()
{
	//
}

void g(Display *d)
{
	d->init();
	d->write("hello.\n");
}

int main()
{
	Monochrome mc;
	SVGA svga;
	g(&mc);
	g(&svga);
}


//g++ f1301.cpp

/*
Monochrome: hello.
ColorAdapter: hello.
*/