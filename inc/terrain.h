#ifndef TERRAIN_H
#define TERRAIN_H

#include "object.h"

typedef enum
{
    GRASS,
    WATER,
    SAND
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