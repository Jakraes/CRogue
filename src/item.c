#include "item.h"

// Static generator functions
static void item_new_ironsword(Item *item)
{
    item->object = object_new('/', terminal_new_color(T_BLK, T_BLK, 1, 0), "an iron sword", "It's an iron sword.");
    item->solid = 0;
}

static void item_generate(Item *item, ItemType type)
{

    switch (type)
    {
    case IRON_SWORD:
        item_new_ironsword(item);
        break;
    }
}

// Header implementation
Item *item_new(int x, int y, ItemType type)
{
    Item *result = malloc(sizeof(Item));

    result->x = x;
    result->y = y;

    item_generate(result, type);

    return result;
}

void item_free(void *item)
{
    if (item)
    {
        Item *ptr = (Item *)item;

        object_free(ptr->object);
        free(ptr);
    }
}