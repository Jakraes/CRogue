#include "util.h"

void init_rand(long seed) {
    srand(time(NULL));
}

int rand_int(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}