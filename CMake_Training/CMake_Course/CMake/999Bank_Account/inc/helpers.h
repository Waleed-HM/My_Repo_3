#ifndef HELPERS_H
#define HELPERS_H
#include <string>

using namespace std;

typedef struct
{
    int day;
    int month;
    int year;
}Date_t;

typedef enum
{
    VALID_DATE,
    INVALID_DATE
}dateRetCode;

void Initialize_Accounts();
void Deinitialize_Accounts();
void create_ID_pool(vector<double> **, int, int);
void delete_ID_pool(vector<double> **);
void refresh_rng_seed();
int pick_random_number(int);
dateRetCode validate_date(Date_t);



#endif