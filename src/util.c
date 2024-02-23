#include "util.h"

void init_rand()
{
    srand(time(NULL));
}

void init_rand_seed(long seed)
{
    srand(time(&seed));
}

int rand_int(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}