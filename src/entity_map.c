#include "entity_map.h"

static int possible_moves[9][2] = {{-1, 1}, {0, 1}, {1, 1}, {-1, 0}, {0, 0}, {1, 0}, {-1, -1}, {0, -1}, {1, -1}}; 

static void entity_move_player(Entity* entity, Map* map) {
    int index = terminal_current_key - 49;
    
    int x = entity->x + possible_moves[index][0];
    int y = entity->y + possible_moves[index][1];
    
    if (!map_is_occupied(map, x, y)) {
        entity->x += possible_moves[index][0];
        entity->y += possible_moves[index][1];
    }
    
}

static void entity_move_orc(Entity* entity, Map* map) {
    
}

void entity_act(Entity* entity, Map* map) {
    switch(entity->name) {
        case PLAYER:
            entity_move_player(entity, map);
            break;
        case ORC:
            entity_move_orc(entity, map);
            break;
    }
}