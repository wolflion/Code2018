#ifndef HEADER_ACCOUNT
#define HEADER_ACCOUNT
#include <string>
using std::string;

class Account{
	string acntNumber;
	double balance;
public:
	Account(string acntNo, double balan= 0.0);
	virtual void display() const;
	double getBalan()
	{
		return balance;
	}
	void deposit(double amount)
	{
		balance += amount;
	}
	bool operator==(const Account& a)const
	{
		return acntNumber == a.acntNumber;
	}
	virtual void withdrawal(double amount) = 0;  // ´¿Ðéº¯Êý
};


#endif // HEADER_ACCOUNT