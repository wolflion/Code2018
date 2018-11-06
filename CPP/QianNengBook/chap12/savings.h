#ifndef  HEADER_SAVINGS
#define HEADER_SAVINGS

#include <string>
using std::string;

class Savings{
	string acntNumber;
	double balance;
public:
	Savings(string acntNo, double balan = 0.0);
	void deposit(double amount)
	{
		balance += amount;
	}
	double getBalan()const
	{
		return balance;
	}

	void display()const;
	void withdrawal(double amount);
};

#endif // ! HEADER_SAVINGS
