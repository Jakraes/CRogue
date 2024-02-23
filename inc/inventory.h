#ifndef INVENTORY_H
#define INVENTORY_H

#include "array.h"
#include "item.h"

typedef struct
{
    size_t max_capacity;
    size_t occupied;
    Array *items;
} Inventory;

Inventory *inventory_new(size_t max_capacity);
void inventory_free(void *inventory);
void inventory_add(Inventory *inventory, Item *item);
void inventory_drop(Inventory *inventory, size_t index, int x, int y);

#endif