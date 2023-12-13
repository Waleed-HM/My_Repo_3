#include "CppUTest/TestHarness.h"
#include "account_ext.h"

// Create a test group
TEST_GROUP(account_ext_test_group)
{
	void setup()
	{
		Initialize_Accounts();
	}

	void teardown()
	{
		Deinitialize_Accounts();
	}
};

TEST(account_ext_test_group, good_savings_deposit)
{
	Account_Ext testAccount("Test Account",2000,{20,3,1990});
	accountRetCode ret = testAccount.depositToSavings(1000);
	float Savings_Balance = testAccount.getSavingsBalance();

	CHECK_EQUAL(ret, NO_ERROR);
	CHECK_EQUAL(Savings_Balance,1000);
}

TEST(account_ext_test_group, bad_Savings_deposit)
{
	Account_Ext testAccount("Test Account",2000,{20,3,1990});
	accountRetCode ret = testAccount.depositToSavings(-1000);
	float Savings_Balance = testAccount.getSavingsBalance();

	CHECK_EQUAL(ret, DEPOSIT_ERROR);
	CHECK_EQUAL(Savings_Balance,0);
}