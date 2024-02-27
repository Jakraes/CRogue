#include "entity.h"

// Static generator functions
static void entity_new_player(Entity *entity)
{
    entity->object = object_new('@', terminal_new_color(T_WHT, T_BLK, 1, 0), "player", "It's you!");
    entity->type = PLAYER;
    entity->solid = 1;
    entity->inventory = inventory_new(10);
}

static void entity_new_orc(Entity *entity)
{
    entity->object = object_new('o', terminal_new_color(T_YLW, T_BLK, 1, 0), "orc", "It's an orc.");
    entity->type = ORC;
    entity->solid = 1;
    entity->inventory = inventory_new(0);
}

static void entity_generate(Entity *entity, EntityType type)
{
    switch (type)
    {
    case PLAYER:
        entity_new_player(entity);
        break;

    case ORC:
        entity_new_orc(entity);
        break;
    }
}

// Header implementation
Entity *entity_new(int x, int y, EntityType type)
{
    Entity *result = malloc(sizeof(Entity));

    result->x = x;
    result->y = y;

    entity_generate(result, type);

    return result;
}

void entity_free(void *entity)
{
    if (entity)
    {
        Entity *ptr = (Entity *)entity;

        object_free(ptr->object);
        free(ptr);
    }
}