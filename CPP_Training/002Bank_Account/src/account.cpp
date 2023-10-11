#include "account.h"
#include <iostream>
#include <vector>

using namespace std;


vector<double> ID_pool;

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

retCode Account::deposit(float amount)
{
	retCode ret;
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

retCode Account::withdraw(float amount)
{
	retCode ret;
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

string Account::getName()
{
	return this->name;
}

float Account::getBalance()
{
	return this->balance;
}

/* ------------------------------------------- */
void Initialize_Accounts()
{
	initialize_ID_pool();
}

static void initialize_ID_pool()
{
	// Fill the ID pool with values
	for (int i = 0; i < ID_POOL_SIZE; i++)
	{
		ID_pool.push_back(rand() % MAX_ID);
	}
	cout << ID_pool.size() << endl;
}