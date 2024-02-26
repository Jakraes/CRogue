#ifndef ITEM_H
#define ITEM_H

#include "object.h"

typedef enum
{
    IRON_SWORD
} ItemType;

typedef struct
{
    Object *object;
    int x;
    int y;
    bool solid;
} Item;

Item *item_new(int x, int y, ItemType type);
void item_free(void *item);

#endif