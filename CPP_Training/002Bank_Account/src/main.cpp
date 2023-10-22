#include <iostream>
#include "account.h"
#include "account_ext.h"
#include <cstdlib>
#include "helpers.h"

using namespace std;

int main()
{
	Initialize_Accounts();

	cout << "Bank Account test project !" << endl << endl;
	Account Waleed_account("Waleed Alhammami",20000);
	Account_Ext Kotaiba_account("Kotaiba Alhammami",15000,{24,5,1994});

	Deinitialize_Accounts();

	return 0;
}