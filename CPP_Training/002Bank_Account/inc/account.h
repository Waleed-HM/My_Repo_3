#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>
#include "helpers.h"
#include "constants.h"

using namespace std;

enum retCode : int;

class Account
{
private:
	string name;
	float balance;
	double ID;
	static int total_accounts;
public:
	Account();
	Account(string, float);
	~Account();
	retCode deposit(float);
	retCode withdraw(float);
	string getName();
	float getBalance();
	retCode operator==(Account const&);
};

enum retCode : int
{
	NO_ERROR,
	DEPOSIT_ERROR,
	WITHDRAW_ERROR,
	EQUAL_BALANCE,
	UNEQUAL_BALANCE
};

#endif