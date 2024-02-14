#ifndef MAP_H
#define MAP_H

#include "array.h"
#include "terrain.h"
#include "item.h"
#include "entity.h"

typedef struct {
    unsigned int width;
    unsigned int height;
    Array* terrains;
    Array* items;
    Array* entities;
} Map;

Map* map_new(unsigned int width, unsigned height);
void map_free(void* map);
bool map_is_occupied(Map* map, int x, int y);

void map_generate_test(Map* map);

#endif