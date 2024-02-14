#ifndef TERRAIN_H
#define TERRAIN_H

#include "object.h"

typedef struct {
    Object* object;
    int x;
    int y;
    bool solid;
} Terrain;

Terrain* terrain_new(Object* object, int x, int y, bool solid);
void terrain_free(void* terrain);

#endif