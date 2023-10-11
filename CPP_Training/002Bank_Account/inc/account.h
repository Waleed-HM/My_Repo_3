#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

using namespace std;

#define ID_POOL_SIZE 1000
#define MAX_ID		 1000000

enum retCode : int;

class Account
{
private:
	string name;
	float balance;
	int ID;
public:
	Account(string, float);
	~Account();
	retCode deposit(float);
	retCode withdraw(float);
	string getName();
	float getBalance();
};

enum retCode : int
{
	No_Error,
	Deposit_Error,
	Withdraw_Error
};

void Initialize_Accounts();
static void initialize_ID_pool();

#endif