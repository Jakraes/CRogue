#ifndef ITEM_H
#define ITEM_H

#include "object.h"

typedef struct
{
    Object *object;
    int x;
    int y;
    bool solid;
} Item;

Item *item_new(Object *object, int x, int y, bool solid);
void item_free(void *item);

Item *item_new_ironsword(int x, int y);

#endif