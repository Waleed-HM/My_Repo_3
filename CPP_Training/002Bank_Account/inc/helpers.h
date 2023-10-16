#ifndef HELPERS_H
#define HELPERS_H

using namespace std;

void Initialize_Accounts();
void Deinitialize_Accounts();
void create_ID_pool(vector<double> **, int, int);
void delete_ID_pool(vector<double> **);
void refresh_rng_seed();
int pick_random_number(int);


#endif