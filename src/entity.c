#include "entity.h"

Entity* entity_new(Object* object, EntityName name, int x, int y, bool solid, size_t inventory_capacity) {
    Entity* result = malloc(sizeof(Entity));
    
    result->object = object;
    result->name = name;
    result->x = x;
    result->y = y;
    result->solid = solid;
    result->inventory = inventory_new(inventory_capacity);
    
    return result;
}

void entity_free(void* entity) {
    if (entity) {
        Entity* ptr = (Entity*) entity;
        
        object_free(ptr->object);
        free(ptr);
    }
}

Entity* entity_new_player(int x, int y) {
    return entity_new(object_new('@', terminal_new_color(T_WHT, T_BLK, 1), "player", "It's you!"), PLAYER, x, y, 1, 10);
}
