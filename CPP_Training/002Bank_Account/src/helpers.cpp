#include <iostream>
#include <vector>
#include "helpers.h"
#include "constants.h"

using namespace std;

extern vector<double> *P_ID_POOL;

void Initialize_Accounts()
{
	cout << "Initializing accounts !" << endl;

	create_ID_pool(&P_ID_POOL, ID_POOL_SIZE, MAX_ID);

#ifdef ENABLE_DEBUG
	for (vector<double>::iterator it = (*P_ID_POOL).begin(); it < (*P_ID_POOL).end(); it++)
	{
		cout << *it << endl;
	}
#endif
}

void Deinitialize_Accounts()
{
	cout << "Deinitializing accounts !" << endl;
	delete_ID_pool(&P_ID_POOL);
	P_ID_POOL = NULL;
}

void create_ID_pool(vector<double> **p, int size, int max_id)
{
	*p = new vector<double>;

	refresh_rng_seed();
	for(int i = 0; i < size; i++)
	{
		(**p).push_back(pick_random_number(max_id));
	}
}

void delete_ID_pool(vector<double> **p)
{
	delete *p;
}

void refresh_rng_seed()
{
	srand((unsigned int)time(NULL));
}

int pick_random_number(int max_num)
{
	return (rand() % max_num);
}