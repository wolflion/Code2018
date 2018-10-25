// f1008.cpp ĞéÄâ¼Ì³Ğ
#include <iostream>
using namespace std;

class Furniture
{
protected:
	int weight;
public:
	Furniture()
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

class Bed:virtual  public Furniture
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

class Sofa:virtual public Furniture
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
	ss.setWeight(20);
	cout<<ss.getWeight()<<endl;
}

// g++ f1008.cpp

/*
20
*/