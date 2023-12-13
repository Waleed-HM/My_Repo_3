#include <iostream>
#include <vector>
#include "account.h"

using namespace std;


vector<double> *P_ID_POOL = NULL;

Account::Account()
{
	this->name = "No name";
	this->balance = 0;
	this->total_accounts++;
}

Account::Account(string newName, float value)
{
	this->name = newName;
	this->balance = value;

	// pick a random value between 0 and the number of IDs left
	refresh_rng_seed();
	int id_order = pick_random_number(ID_POOL_SIZE - this->total_accounts);

	// pick an ID value from the IDs pool vector based on the random value picked and assign it to the new account instance
	this->ID = *((*P_ID_POOL).begin() + id_order);

	// erase that value from the IDs pool
	(*P_ID_POOL).erase((*P_ID_POOL).begin() + id_order);

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
	if (P_ID_POOL != NULL)
	{
		(*P_ID_POOL).push_back(this->ID);
	}

	// Decrement the number of accounts
	this->total_accounts--;
	cout << "Account belonging to " << this->name << " has been deleted !" << endl;
}

retCode Account::deposit(float amount)
{
	retCode ret;
	if(amount <= 0)
	{
		ret = DEPOSIT_ERROR;
	}
	else
	{
		this->balance += amount;
		ret = NO_ERROR;
	}
	return ret;
}

retCode Account::withdraw(float amount)
{
	retCode ret;
	if(amount <= 0 || amount > this->balance)
	{
		ret = WITHDRAW_ERROR;
	}
	else
	{
		this->balance -= amount;
		ret = NO_ERROR;
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
