#ifndef random_h
	#define random_h
#include<ctime>
using namespace std;
bool rrand_init;
int rrand_index;
int rrand_mt[624];
void srrand(int seed);
void rrand_generate();
int rrand();
#endif
