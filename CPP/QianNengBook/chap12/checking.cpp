//checking.cpp
#include <iostream>
#include "checking.h"

Checking::Checking(string acntNo, double balan) :acntNumber(acntNo), balance(balan), remittance(other)
{
	//
}

void Checking::display()const
{
	std::cout << "Checking Account:" + acntNumber + " = " << balance << "\n";
}

void Checking::withdrawal(double amount)
{
	if (remittance == remitByPost)  // ÐÅ»ã30
	{
		amount += 30;
	}
	if (remittance == remitByCable)  // µç»ã60
	{
		amount += 60;
	}
	if (balance < amount)
		std::cout << "Insufficient funds withdrawal: " << amount << "\n";
	else
		balance -= amount;
}