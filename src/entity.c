#include "entity.h"

Entity* entity_new(Object* object, EntityName name, int x, int y, bool solid) {
    Entity* result = malloc(sizeof(Entity));
    
    result->object = object;
    result->name = name;
    result->x = x;
    result->y = y;
    result->solid = solid;
    
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
    return entity_new(object_new('@', terminal_new_color(T_WHT, T_BLK, 1)), PLAYER, x, y, 1);
}