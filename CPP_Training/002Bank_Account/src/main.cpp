#include <iostream>
#include "account.h"
#include<cstdlib>

using namespace std;

int main()
{
		Initialize_Accounts();

	cout << "Bank Account test project !" << endl;
	Account Waleed_account("Waleed Alhammami",20000);

	return 0;
}