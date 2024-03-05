#include "map.h"

static void map_generate_overworld(Map *map)
{
    const int biome_seed = map->seed << 4;

    for (int y = 0; y < map->height; y++)
    {
        for (int x = 0; x < map->width; x++)
        {
            float height = pnoise2d(x * MAP_FREQ, y * MAP_FREQ, 0.25, 15, map->seed);
            float biome = pnoise2d(x * MAP_BIOME_FREQ, y * MAP_BIOME_FREQ, 0.25, 15, biome_seed);
            Terrain *t = NULL;

            if (height < 0.05)
            {
                t = terrain_new(x, y, WATER_DEEP);
            }
            else if (height < 0.2)
            {
                t = terrain_new(x, y, WATER_SHALLOW);
            }
            else if (height < 0.3)
            {
                t = terrain_new(x, y, SAND);
            }
            else if (height < 0.9)
            {
                int i = rand_int(0, 1);
                int j = rand_int(0, 4);

                if (biome < 0.5)
                {
                    if (j == 0)
                    {
                        if (i)
                        {
                            t = terrain_new(x, y, TREE_OAK);
                        }
                        else
                        {
                            t = terrain_new(x, y, TREE_PINE);
                        }
                    }
                    else
                    {
                        if (i)
                        {
                            t = terrain_new(x, y, GRASS_LOW);
                        }
                        else
                        {
                            t = terrain_new(x, y, GRASS_HIGH);
                        }
                    }
                }
                else
                {
                    if (j == 0)
                    {
                        if (i)
                        {
                            t = terrain_new(x, y, GRASS_LOW);
                        }
                        else
                        {
                            t = terrain_new(x, y, GRASS_HIGH);
                        }
                    }
                    else
                    {
                        if (i)
                        {
                            t = terrain_new(x, y, TREE_OAK);
                        }
                        else
                        {
                            t = terrain_new(x, y, TREE_PINE);
                        }
                    }
                }
            }
            else if (height < 0.95)
            {
                t = terrain_new(x, y, MOUNTAIN_LOW);
            }
            else
            {
                t = terrain_new(x, y, MOUNTAIN_HIGH);
            }

            array_push(map->terrains, t);
        }
    }
}

static void map_generate_test(Map *map)
{
    for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 10; x++)
        {
            array_push(map->terrains, terrain_new(x, y, GRASS_LOW));
        }
    }

    array_push(map->entities, entity_new(0, 0, PLAYER));
    array_push(map->items, item_new(3, 4, IRON_SWORD));
}

static void map_generate(Map *map, MapType type)
{
    switch (type)
    {
    case OVERWORLD:
        map_generate_overworld(map);
        break;
    case DUNGEON:
        break;
    case TEST:
        map_generate_test(map);
        break;
    }
}

Map *map_new(unsigned int width, unsigned int height, unsigned int seed, MapType type)
{
    Map *result = malloc(sizeof(Map));

    result->width = width;
    result->height = height;
    result->seed = seed;
    result->terrains = array_new(terrain_free);
    result->items = array_new(item_free);
    result->entities = array_new(entity_free);

    map_generate(result, type);

    return result;
}

void map_free(void *map)
{
    if (map)
    {
        Map *ptr = (Map *)map;

        array_free(ptr->terrains);
        array_free(ptr->items);
        array_free(ptr->entities);
        free(ptr);
    }
}

bool map_is_occupied(Map *map, int x, int y)
{
    Terrain *t = (Terrain *)map->terrains->data[y * map->height + x];

    if (t->solid)
    {
        return 1;
    }

    for (size_t i = 0; i < map->items->length; i++)
    {
        Item *p = (Item *)map->items->data[i];

        if (p->x == x && p->y == y && p->solid)
        {
            return 1;
        }
    }

    for (size_t i = 0; i < map->entities->length; i++)
    {
        Entity *p = (Entity *)map->entities->data[i];

        if (p->x == x && p->y == y && p->solid)
        {
            return 1;
        }
    }

    return 0;
}