#include "entity.h"

static int possible_moves[9][2] = {{-1, 1}, {0, 1}, {1, 1}, {-1, 0}, {0, 0}, {1, 0}, {-1, -1}, {0, -1}, {1, -1}}; 

static void entity_move_player(Entity* entity) {
    int index = terminal_current_key - 49;
    
    entity->x += possible_moves[index][0];
    entity->y += possible_moves[index][1];
}

static void entity_move_orc(Entity* entity) {
    
}


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

void entity_move(Entity* entity) {
    switch(entity->name) {
        case PLAYER:
            entity_move_player(entity);
            break;
        case ORC:
            entity_move_orc(entity);
            break;
    }
}

Entity* entity_new_player(int x, int y) {
    return entity_new(object_new('@', terminal_new_color(T_WHT, T_BLK, 1)), PLAYER, x, y, 1);
}
