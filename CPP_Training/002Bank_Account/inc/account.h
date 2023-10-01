#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

using namespace std;

class Account
{
private:
	string name;
	float balance;
public:
	Account(string, float);
	~Account();
};
#endif