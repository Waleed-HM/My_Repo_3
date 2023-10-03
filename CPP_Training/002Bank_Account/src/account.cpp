#include "account.h"
#include <iostream>

Account::Account(string newName, float value)
{
	this->name = newName;
	this->balance = value;
	cout << "A new account has been opened !" << endl;
	cout << "Name : " << this->name << endl;
	cout << "Starting balance : " << this->balance << endl;
}

Account::~Account()
{
	cout << "Account belonging to " << this->name << " has been deleted at end of the program !" << endl;
}

Return_Code Account::Deposit(float amount)
{
	Return_Code ret;
	if(amount <= 0)
	{
		ret = Deposit_Error;
	}
	else
	{
		this->balance += amount;
		ret = No_Error;
	}
	return ret;
}

Return_Code Account::Withdraw(float amount)
{
	Return_Code ret;
	if(amount <= 0 || amount > this->balance)
	{
		ret = Withdraw_Error;
	}
	else
	{
		this->balance -= amount;
		ret = No_Error;
	}
	return ret;
}