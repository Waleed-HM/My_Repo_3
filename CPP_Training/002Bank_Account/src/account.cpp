#include "account.h"
#include <iostream>
#include <vector>

using namespace std;


vector<double> ID_pool;

Account::Account(string newName, float value)
{
	this->name = newName;
	this->balance = value;

	// pick a random value between 0 and the number of IDs left
	int id_order = rand() % (ID_POOL_SIZE - this->total_accounts);

	// pick an ID value from the IDs pool vector based on the random value picked and assign it to the new account instance
	this->ID = ID_pool[id_order];

	// erase that value from the IDs pool
	ID_pool.erase(ID_pool.begin() + id_order);

	// Increment the number of account
	this->total_accounts++;
	cout << "A new account has been opened !" << endl;
	cout << "Name : " << this->name << endl;
	cout << "Starting balance : " << this->balance << endl;
	cout << "ID : " << this->ID << endl;
	cout << "Total accounts: " << this->total_accounts << endl;
	cout << endl;
}

Account::~Account()
{
	// Insert the ID of the deleted account back into the ID pool
	ID_pool.push_back(this->ID);

	// Decrement the number of accounts
	this->total_accounts--;
	cout << "Account belonging to " << this->name << " has been deleted !" << endl;
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

int Account::total_accounts;

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
}