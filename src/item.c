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