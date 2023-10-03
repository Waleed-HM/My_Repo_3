#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

using namespace std;

enum Return_Code : int;

class Account
{
private:
	string name;
	float balance;
public:
	Account(string, float);
	~Account();
	Return_Code Deposit(float);
	Return_Code Withdraw(float);
};

enum Return_Code : int
{
	No_Error,
	Deposit_Error,
	Withdraw_Error
};

#endif