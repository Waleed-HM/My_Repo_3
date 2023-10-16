#include "CppUTest/TestHarness.h"
#include "account.h"

// Create a test group
TEST_GROUP(account_test_group)
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

TEST(account_test_group, good_deposit)
{
	Account testAccount("Test Account",2000);
	retCode ret = testAccount.deposit(1000);
	float Balance = testAccount.getBalance();

	CHECK_EQUAL(ret, NO_ERROR);
	CHECK_EQUAL(Balance,3000);
}

TEST(account_test_group, bad_deposit)
{
	Account testAccount("Test Account",2000);
	retCode ret = testAccount.deposit(-500);
	float Balance = testAccount.getBalance();

	CHECK_EQUAL(ret, DEPOSIT_ERROR);
	CHECK_EQUAL(Balance,2000);
}

TEST(account_test_group, good_withdraw)
{
	Account testAccount("Test Account",2000);
	retCode ret = testAccount.withdraw(1000);
	float Balance = testAccount.getBalance();

	CHECK_EQUAL(ret, NO_ERROR);
	CHECK_EQUAL(Balance,1000);
}

TEST(account_test_group, bad_withdraw_1)
{
	Account testAccount("Test Account",2000);
	retCode ret = testAccount.withdraw(3000);
	float Balance = testAccount.getBalance();

	CHECK_EQUAL(ret, WITHDRAW_ERROR);
	CHECK_EQUAL(Balance,2000);
}

TEST(account_test_group, bad_withdraw_2)
{
	Account testAccount("Test Account",2000);
	retCode ret = testAccount.withdraw(-500);
	float Balance = testAccount.getBalance();

	CHECK_EQUAL(ret, WITHDRAW_ERROR);
	CHECK_EQUAL(Balance,2000);
}

TEST(account_test_group, equal_Accounts)
{
	Account testAccount1("Test Account 1",1000);
	Account testAccount2("Test Account 2",1000);
	
	retCode ret = (testAccount1 == testAccount2);
	CHECK_EQUAL(ret, EQUAL_BALANCE);
}

TEST(account_test_group, unequal_Accounts)
{
	Account testAccount1("Test Account 1",1000);
	Account testAccount2("Test Account 2",1500);
	
	retCode ret = (testAccount1 == testAccount2);
	CHECK_EQUAL(ret, UNEQUAL_BALANCE);
}