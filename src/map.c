#include "map.h"

static float map_perlin_freq = 0.07;
static float map_perlin_depth = 1.0;

Map* map_new(unsigned int width, unsigned int height) {
    Map* result = malloc(sizeof(Map));
    
    result->width = width;
    result->height = height;
    result->terrains = array_new(terrain_free);
    result->items = array_new(item_free);
    result->entities = array_new(entity_free);
    
    return result;
}

void map_free(void* map) {
    if (map) {
        Map* ptr = (Map*) map;
        
        array_free(ptr->terrains);
        array_free(ptr->items);
        array_free(ptr->entities);
        free(ptr);
    }
}

bool map_is_occupied(Map* map, int x, int y) {
    for (size_t i = 0; i < map->terrains->length; i++) {
        Terrain* p = (Terrain*) map->terrains->data[i];
        
        if (p->x == x && p->y == y && p->solid) {
            return 1;
        }
    }
    
    for (size_t i = 0; i < map->items->length; i++) {
        Item* p = (Item*) map->items->data[i];
        
        if (p->x == x && p->y == y && p->solid) {
            return 1;
        }
    }
    
    for (size_t i = 0; i < map->entities->length; i++) {
        Entity* p = (Entity*) map->entities->data[i];
        
        if (p->x == x && p->y == y && p->solid) {
            return 1;
        }
    }
    
    return 0;
}

void map_generate_test(Map* map) {
    Object* object = object_new(' ', terminal_new_color(T_WHT, T_GRN, 0), "grass", "A patch of grass.");
    
    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            array_push(map->terrains, terrain_new(object, x, y, 0));
        }
    }
    
    array_push(map->entities, entity_new_player(0, 0));
    array_push(map->items, item_new_ironsword(3, 4));
}

void map_generate_world(Map* map) {
    Object* grass = object_new(' ', terminal_new_color(T_WHT, T_GRN, 0), "grass", "A patch of grass.");
    Object* sand = object_new(' ', terminal_new_color(T_WHT, T_YLW, 1), "sand", "There's at least 1 grain of sand here.");
    Object* water = object_new(' ', terminal_new_color(T_WHT, T_BLU, 0), "water", "It's wet.");
    
    for (int y = 0; y < map->height; y++) {
        for (int x = 0; x < map->width; x++) {
            float height = perlin2d(x, y, map_perlin_freq, map_perlin_depth);
            Terrain* t;
            
            if (height < 0.2) t = terrain_new(water, x, y, 0);
            else if (height < 0.4) t = terrain_new(sand, x, y, 0);
            else t = terrain_new(grass, x, y, 0);
            
            array_push(map->terrains, t);
        }
    }
}