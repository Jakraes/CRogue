#ifndef MAP_H
#define MAP_H

#include "array.h"
#include "terrain.h"
#include "item.h"
#include "entity.h"
#include "perlin.h"
#include "util.h"

#define MAP_FREQ 0.05
#define MAP_BIOME_FREQ 0.05

typedef enum
{
    TEST,
    OVERWORLD,
    DUNGEON,
} MapType;

typedef enum
{
    FOREST,
    PLAINS,
} MapBiomeType;

typedef struct
{
    unsigned int width;
    unsigned int height;
    unsigned int seed;
    Array *terrains;
    Array *items;
    Array *entities;
} Map;

Map *map_new(unsigned int width, unsigned int height, unsigned int seed, MapType type);
void map_free(void *map);
bool map_is_occupied(Map *map, int x, int y);

#endif