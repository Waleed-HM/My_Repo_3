#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>

using namespace std;

#define ID_POOL_SIZE 1000
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
	NO_ERROR,
	DEPOSIT_ERROR,
	WITHDRAW_ERROR
};

void Initialize_Accounts();
void Deinitialize_Accounts();
void create_ID_pool(vector<double> **, int, int);
void delete_ID_pool(vector<double> **);
void refresh_rng_seed();
int pick_random_number(int);
#endif