#include "terrain.h"

// Static generator functions
static void terrain_newe_grass(Terrain *terrain)
{
    terrain->object = object_new(' ', terminal_new_color(T_GRN, T_GRN, 1, 0), "grass", "It's grass.");
    terrain->solid = 0;
}

static void terrain_new_water(Terrain *terrain)
{
    terrain->object = object_new(' ', terminal_new_color(T_WHT, T_CYN, 1, 0), "water", "It's water.");
    terrain->solid = 1;
}

static void terrain_new_sand(Terrain *terrain)
{
    terrain->object = object_new(' ', terminal_new_color(T_YLW, T_YLW, 1, 0), "sand", "It's sand.");
    terrain->solid = 0;
}

static void terrain_generate(Terrain *terrain, TerrainType type)
{
    switch (type)
    {
    case GRASS:
        terrain_newe_grass(terrain);
        break;
    case WATER:
        terrain_new_water(terrain);
        break;
    case SAND:
        terrain_new_sand(terrain);
        break;
    }
}

// Header implementation
Terrain *terrain_new(int x, int y, TerrainType type)
{
    Terrain *result = malloc(sizeof(Terrain));
    result->x = x;
    result->y = y;

    terrain_generate(result, type);

    return result;
}

void terrain_free(void *terrain)
{
    if (terrain)
    {
        Terrain *ptr = (Terrain *)terrain;

        object_free(ptr->object);
        free(ptr);
    }
}
