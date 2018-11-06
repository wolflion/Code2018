//checking.h
#ifndef HEADER_CHECKING
#define HEADER_CHECKING

#include <string>
using std::string;

enum REMIT{remitByPost,remitByCable,other}; // ÐÅ»ã£¬µç»ã£¬ÎÞ

class Checking{
	string acntNumber;
	double balance;
	REMIT remittance;
public:
	Checking(string acntNo, double balan = 0.0);
	void display()const;
	void deposit(double amount)
	{ 
		balance += amount; 
	}
	double getBalan()const
	{
		return balance;
	}
	void withdrawal(double amount);
	void setRemit(REMIT re)
	{
		remittance = re;
	}
};

#endif