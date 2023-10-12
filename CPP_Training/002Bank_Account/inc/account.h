#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>

using namespace std;

#define ID_POOL_SIZE 20
#define MAX_ID		 1000000

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
};

enum retCode : int
{
	No_Error,
	Deposit_Error,
	Withdraw_Error
};

void Initialize_Accounts();
vector<double> * create_ID_pool(int, int);
void delete_ID_pool(vector<double> *);
void init_ID_pool();
void deinit_ID_pool();

#endif