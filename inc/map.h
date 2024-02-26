#ifndef MAP_H
#define MAP_H

#include "array.h"
#include "terrain.h"
#include "item.h"
#include "entity.h"
#include "perlin.h"

typedef struct
{
    unsigned int width;
    unsigned int height;
    unsigned int seed;
    Array *terrains;
    Array *items;
    Array *entities;
} Map;

extern float map_perlin_freq;

Map *map_new(unsigned int width, unsigned int height, unsigned int seed);
void map_free(void *map);
bool map_is_occupied(Map *map, int x, int y);

void map_generate_test(Map *map);
void map_generate_world(Map *map);

#endif