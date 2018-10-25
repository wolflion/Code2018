// f1007.cpp 非虚拟多继承
#include <iostream>
using namespace std;

class Furniture
{
protected:
	int weight;
public:
	Furniture():weight(0)
	{
		//
	}
	void setWeight(int i)
	{
		weight = i;
	}
	int getWeight() const
	{
		return weight;
	}
};

class Bed: public Furniture
{
public:
	Bed()
	{
		//
	}
	void sleep()const 
	{
		cout << "Sleeping...\n";
	}
};

class Sofa: public Furniture
{
public:
	Sofa()
	{
		//
	}
	void watchTV() const
	{
		cout<<"Watching TV.\n";
	}
};

class SleeperSofa:public Bed,public Sofa
{
public:
	SleeperSofa():Sofa(),Bed()
	{
		//
	}
	void foldOut()const
	{
		cout << "Fold out the sofa.\n";
	}
};

int main()
{
	SleeperSofa ss;
	ss.setWeight(20);   // 错：模糊的setWeight成员
	Furniture* pF = (Furniture*)&ss;  // 错：模糊的Furniture*
	cout<<pF->getWeight()<<endl;
}

// g++ f1007.cpp

