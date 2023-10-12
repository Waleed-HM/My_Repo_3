#include "account.h"
#include <iostream>
#include <vector>

using namespace std;


//vector<double> ID_pool;
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
	//int id_order = rand() % (ID_POOL_SIZE - this->total_accounts);

	// pick an ID value from the IDs pool vector based on the random value picked and assign it to the new account instance
	//this->ID = *(ID_pool.begin() + id_order);

	// erase that value from the IDs pool
	//ID_pool.erase(ID_pool.begin() + id_order);

	// Increment the number of account
	this->total_accounts++;
	cout << "A new account has been opened !" << endl;
	cout << "Name : " << this->name << endl;
	cout << "Starting balance : " << this->balance << endl;
	//cout << "ID : " << this->ID << endl;
	cout << "Total accounts: " << this->total_accounts << endl;
	cout << endl;
}

Account::~Account()
{
	// Insert the ID of the deleted account back into the ID pool
	//ID_pool.push_back(this->ID);

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
	vector<double> *p_ID_pool = create_ID_pool(ID_POOL_SIZE, MAX_ID);

	for (vector<double>::iterator it = (*p_ID_pool).begin(); it < (*p_ID_pool).end(); it++)
	{
		cout << *it << endl;
	}

	delete_ID_pool(p_ID_pool);
}

vector<double> * create_ID_pool(int size, int max_id)
{
	vector<double> *p_ID_pool = new vector<double>;
	srand ((unsigned int)time(NULL));
	for (int i = 0; i < size; i++)
	{
		(*p_ID_pool).push_back(rand() % max_id);
	}
	return p_ID_pool;
}

void delete_ID_pool(vector<double> *p)
{
	delete p;
}

void init_ID_pool()
{

}

void deinit_ID_pool()
{

}