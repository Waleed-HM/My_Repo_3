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