#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

using namespace std;

enum retCode : int;

class Account
{
private:
	string name;
	float balance;
public:
	Account(string, float);
	~Account();
	retCode deposit(float);
	retCode withdraw(float);
	float getBalance();
};

enum retCode : int
{
	No_Error,
	Deposit_Error,
	Withdraw_Error
};

#endif