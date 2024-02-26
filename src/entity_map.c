#include "entity_map.h"

static int possible_moves[9][2] = {{-1, 1}, {0, 1}, {1, 1}, {-1, 0}, {0, 0}, {1, 0}, {-1, -1}, {0, -1}, {1, -1}};

static void entity_act_player(Entity *entity, Map *map)
{
    switch (terminal_current_key)
    {
    case 'p': // Pick up item
        for (size_t i = 0; i < map->items->length; i++)
        {
            Item *p = map->items->data[i];
            if (p->x == entity->x && p->y == entity->y)
            {
                inventory_add(entity->inventory, p);
                break;
            }
        }

        break;

    default:; // Defaults to movement (NEEDS SEMICOLON TO WORK)
        int index = terminal_current_key - 49;

        int x = entity->x + possible_moves[index][0];
        int y = entity->y + possible_moves[index][1];

        if (!map_is_occupied(map, x, y))
        {
            entity->x += possible_moves[index][0];
            entity->y += possible_moves[index][1];
        }

        break;
    }
}

static void entity_act_orc(Entity *entity, Map *map)
{
}

void entity_act(Entity *entity, Map *map)
{
    switch (entity->type)
    {
    case PLAYER:
        entity_act_player(entity, map);
        break;
    case ORC:
        entity_act_orc(entity, map);
        break;
    }
}