#include <iostream>
#include "account.h"
#include<cstdlib>

using namespace std;

int main()
{
		Initialize_Accounts();

	cout << "Bank Account test project !" << endl << endl;
	Account Waleed_account("Waleed Alhammami",20000);
	Account Kotaiba_account("Kotaiba Alhammami",15000);

	return 0;
}