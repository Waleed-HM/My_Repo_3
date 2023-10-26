#include <iostream>
#include <vector>
#include "account_ext.h"

using namespace std;

Account_Ext::Account_Ext()
{
    this->name = "No name";
	this->balance = 0;
	this->total_accounts++;
}

Account_Ext::Account_Ext(string newName, float value, Birthdate date) : Account(newName, value)
{
    this->birthdate = date;
}

Account_Ext::~Account_Ext()
{

}

accountRetCode Account_Ext::depositToSavings(float amount)
{
    accountRetCode ret;
    if(amount <= 0)
    {
        ret = DEPOSIT_ERROR;
    }
    else
    {
        this->savings_balance += amount;
        ret = NO_ERROR;
    }

    return ret;
}

accountRetCode Account_Ext::withdrawFromSavings(float amount)
{
    accountRetCode ret;
    if(amount <=0 || amount >= this->savings_balance)
    {
        ret = WITHDRAW_ERROR;
    }
    else
    {
        this->savings_balance -= amount;
        ret = NO_ERROR;
    }

    return ret;
}

void Account_Ext::printBirthdate()
{
    cout << this->birthdate.day << "/" << this->birthdate.month << "/" << this->birthdate.year << endl;
}

void Account_Ext::printAllInfo()
{
    Account::printAllInfo();
    cout << "Holders birthdate : ";
    this->printBirthdate();
}