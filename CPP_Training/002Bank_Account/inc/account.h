#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>
#include "helpers.h"
#include "constants.h"

using namespace std;

enum accountRetCode : int;

class Account
{
protected:
	string name;
	float balance;
	double ID;
	static int total_accounts;
public:
	Account();
	Account(string, float);
	~Account();
	accountRetCode deposit(float);
	accountRetCode withdraw(float);
	string getName();
	float getBalance();
	accountRetCode operator==(Account const&);
};

enum accountRetCode : int
{
	NO_ERROR,
	DEPOSIT_ERROR,
	WITHDRAW_ERROR,
	EQUAL_BALANCE,
	UNEQUAL_BALANCE
};

#endif