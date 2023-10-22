#ifndef ACCOUNT_EXT_H
#define ACCOUNT_EXT_H

#include "account.h"
#include "helpers.h"

typedef Date_t      Birthdate;
typedef Date_t      Opening_date;

class Account_Ext : public Account
{
private:
    Birthdate       birthdate;
    Opening_date    opening_date;
public:
    Account_Ext();
    Account_Ext(string, float, Birthdate);
    ~Account_Ext();
};
#endif