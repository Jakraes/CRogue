#ifndef ENTITY_H
#define ENTITY_H

#include "object.h"

typedef enum {
    PLAYER,
    ORC,
} EntityName;

typedef struct {
    Object* object;
    EntityName name;
    int x;
    int y;
    bool solid;
} Entity;

Entity* entity_new(Object* object, EntityName name, int x, int y, bool solid);
void entity_free(void* entity);

Entity* entity_new_player(int x, int y);

#endif