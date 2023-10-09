#include "CppUTest/TestHarness.h"
#include "account.h"

// Create a test group
TEST_GROUP(account_test_group)
{
	void setup()
	{

	}

	void teardown()
	{
		
	}
};

TEST(account_test_group, good_deposit)
{
	Account testAccount("Test Account",2000);
	retCode ret = testAccount.Deposit(1000);
	float Balance = testAccount.getBalance();

	CHECK_EQUAL(ret, No_Error);
	CHECK_EQUAL(Balance,3000);
}

TEST(account_test_group, bad_deposit)
{
	Account testAccount("Test Account",2000);
	retCode ret = testAccount.Deposit(-500);
	float Balance = testAccount.getBalance();

	CHECK_EQUAL(ret, Deposit_Error);
	CHECK_EQUAL(Balance,2000);
}

TEST(account_test_group, good_withdraw)
{
	Account testAccount("Test Account",2000);
	retCode ret = testAccount.Withdraw(1000);
	float Balance = testAccount.getBalance();

	CHECK_EQUAL(ret, No_Error);
	CHECK_EQUAL(Balance,1000);
}

TEST(account_test_group, bad_withdraw_1)
{
	Account testAccount("Test Account",2000);
	retCode ret = testAccount.Withdraw(3000);
	float Balance = testAccount.getBalance();

	CHECK_EQUAL(ret, Withdraw_Error);
	CHECK_EQUAL(Balance,2000);
}

TEST(account_test_group, bad_withdraw_2)
{
	Account testAccount("Test Account",2000);
	retCode ret = testAccount.Withdraw(-500);
	float Balance = testAccount.getBalance();

	CHECK_EQUAL(ret, Withdraw_Error);
	CHECK_EQUAL(Balance,2000);
}