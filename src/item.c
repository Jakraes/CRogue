#include "item.h"

Item* item_new(Object* object, int x, int y, bool solid) {
    Item* result = malloc(sizeof(Item));
    
    result->object = object;
    result->x = x;
    result->y = y;
    result->solid = solid;
    
    return result;
}

void item_free(void* item) {
    if (item) {
        Item* ptr = (Item*) item;
        
        object_free(ptr->object);
        free(ptr);
    }
}

Item* item_new_ironsword(int x, int y) {
    Object* object = object_new('/', terminal_new_color(T_BLK, T_BLK, 1), "an iron sword", "It's an iron sword.");
    
    return item_new(object, x, y, 0);
}