#ifndef ENTITY_H
#define ENTITY_H

#include "object.h"
#include "inventory.h"

typedef enum
{
    PLAYER,
    ORC,
} EntityType;

typedef struct
{
    Object *object;
    EntityType type;
    int x;
    int y;
    bool solid;
    Inventory *inventory;
} Entity;

Entity *entity_new(int x, int y, EntityType type);
void entity_free(void *entity);

#endif