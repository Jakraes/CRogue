#ifndef UTIL_H
#define UTIL_H

#include <stdlib.h>
#include <time.h>

void init_rand();
void init_rand_seed(long seed);
int rand_int(int min, int max);

#endif