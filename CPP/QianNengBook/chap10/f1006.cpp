// f1006.cpp ¶à¼Ì³Ð

#include <iostream>
using namespace std;

class Bed{
protected:
	int weight;
public:
	Bed():weight(0)
	{
		//
	}
	void sleep() const
	{
		cout << "Sleeping...\n";
	}
	void setWeight(int i)
	{
		weight = i;
	}
};

class Sofa{
protected:
	int weight;
public:
	Sofa():weight(0)
	{
		//
	}
	void watchTV() const
	{
		cout << "Watching TV.\n";
	}
	void setWeight(int i)
	{
		weight = i;
	}
};

class SleeperSofa:public Bed,public Sofa
{
public:
	SleeperSofa()
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
	ss.watchTV();
	ss.foldOut();
	ss.sleep();
}

//g++ f1006.cpp

/*
Watching TV.
Fold out the sofa.
Sleeping...
*/