#include "CppUtest/TestHarness.h"
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

TEST(account_test_group, simple_test)
{
	int x = 5;
	CHECK_EQUAL(x, 5);
}

TEST(account_test_group, simple_test_2)
{
	int x = 4;
	CHECK_EQUAL(x, 5);
}