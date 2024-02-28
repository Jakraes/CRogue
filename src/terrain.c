#include "terrain.h"

// Static generator functions
static void terrain_new_grass_low(Terrain *terrain)
{
    terrain->object = object_new('.', terminal_new_color(T_GRN, T_BLK, A_NORMAL, A_NORMAL), "low grass", "It's grass.");
    terrain->solid = 0;
}

static void terrain_new_grass_high(Terrain *terrain)
{
    terrain->object = object_new('v', terminal_new_color(T_GRN, T_BLK, A_BOLD, A_NORMAL), "tall grass", "It's tall grass.");
    terrain->solid = 0;
}

static void terrain_new_water_shallow(Terrain *terrain)
{
    terrain->object = object_new('~', terminal_new_color(T_CYN, T_BLK, A_NORMAL, A_NORMAL), "water", "It's water.");
    terrain->solid = 1;
}

static void terrain_new_water_deep(Terrain *terrain)
{
    terrain->object = object_new('~', terminal_new_color(T_BLU, T_BLK, A_NORMAL, A_NORMAL), "deep water", "It's deep water.");
    terrain->solid = 1;
}

static void terrain_new_sand(Terrain *terrain)
{
    terrain->object = object_new('.', terminal_new_color(T_YLW, T_BLK, A_BOLD, A_NORMAL), "sand", "It's sand.");
    terrain->solid = 0;
}

static void terrain_new_mountain_low(Terrain *terrain)
{
    terrain->object = object_new((chtype)0x0000011E, terminal_new_color(T_WHT, T_BLK, A_NORMAL, A_NORMAL), "low mountain", "It's a low mountain.");
    terrain->solid = 0;
}

static void terrain_new_mountain_high(Terrain *terrain)
{
    terrain->object = object_new((chtype)0x0000011E, terminal_new_color(T_WHT, T_BLK, A_BOLD, A_NORMAL), "high mountain", "It's a high mountain.");
    terrain->solid = 1;
}

static void terrain_new_tree_pine(Terrain *terrain)
{
    terrain->object = object_new((chtype)0x00000106, terminal_new_color(T_GRN, T_BLK, A_NORMAL, A_NORMAL), "pine tree", "It's a pine tree.");
    terrain->solid = 0;
}

static void terrain_new_tree_oak(Terrain *terrain)
{
    terrain->object = object_new((chtype)0x00000105, terminal_new_color(T_GRN, T_BLK, A_BOLD, A_NORMAL), "oak tree", "It's an oak tree.");
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
    case MOUNTAIN_LOW:
        terrain_new_mountain_low(terrain);
        break;
    case MOUNTAIN_HIGH:
        terrain_new_mountain_high(terrain);
        break;
    case TREE_PINE:
        terrain_new_tree_pine(terrain);
        break;
    case TREE_OAK:
        terrain_new_tree_oak(terrain);
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
