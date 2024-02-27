#ifndef TERRAIN_H
#define TERRAIN_H

#include "object.h"

typedef enum
{
    GRASS_LOW,
    GRASS_HIGH,
    WATER_SHALLOW,
    WATER_DEEP,
    SAND,
    MOUNTAIN_LOW,
    MOUNTAIN_HIGH,
    TREE_PINE,
    TREE_OAK
} TerrainType;

typedef struct
{
    Object *object;
    int x;
    int y;
    bool solid;
} Terrain;

Terrain *terrain_new(int x, int y, TerrainType type);
void terrain_free(void *terrain);

#endif