#include "inventory.h"

Inventory *inventory_new(size_t max_capacity)
{
    Inventory *result = malloc(sizeof(Inventory));

    result->max_capacity = max_capacity;
    result->occupied = 0;
    result->items = array_new(item_free);

    return result;
}

void inventory_free(void *inventory)
{
    if (inventory)
    {
        Inventory *ptr = (Inventory *)inventory;

        array_free(ptr->items);
        free(ptr);
    }
}

void inventory_add(Inventory *inventory, Item *item)
{
    if (inventory->occupied < inventory->max_capacity)
    {
        array_push(inventory->items, item);
        inventory->occupied++;
        item->x = -1;
        item->y = -1;
    }
}

void inventory_drop(Inventory *inventory, size_t index, int x, int y)
{
    Item *item = array_remove(inventory->items, index);
    inventory->occupied--;
    item->x = x;
    item->y = y;
}