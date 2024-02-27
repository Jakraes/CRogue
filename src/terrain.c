#include "terrain.h"

// Static generator functions
static void terrain_new_grass_low(Terrain *terrain)
{
    terrain->object = object_new(".", terminal_new_color(T_GRN, T_BLK, 0, 0), "low grass", "It's grass.");
    terrain->solid = 0;
}

static void terrain_new_grass_high(Terrain *terrain)
{
    terrain->object = object_new("v", terminal_new_color(T_GRN, T_BLK, 1, 0), "tall grass", "It's tall grass.");
    terrain->solid = 0;
}

static void terrain_new_water_shallow(Terrain *terrain)
{
    terrain->object = object_new("~", terminal_new_color(T_CYN, T_BLK, 0, 0), "water", "It's water.");
    terrain->solid = 1;
}

static void terrain_new_water_deep(Terrain *terrain)
{
    terrain->object = object_new("~", terminal_new_color(T_BLU, T_BLK, 0, 0), "deep water", "It's deep water.");
    terrain->solid = 1;
}

static void terrain_new_sand(Terrain *terrain)
{
    terrain->object = object_new(".", terminal_new_color(T_YLW, T_BLK, 1, 0), "sand", "It's sand.");
    terrain->solid = 0;
}

static void terrain_generate(Terrain *terrain, TerrainType type)
{
    switch (type)
    {
    case GRASS_LOW:
        terrain_new_grass_low(terrain);
        break;
    case GRASS_HIGH:
        terrain_new_grass_high(terrain);
        break;
    case WATER_SHALLOW:
        terrain_new_water_shallow(terrain);
        break;
    case WATER_DEEP:
        terrain_new_water_deep(terrain);
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
