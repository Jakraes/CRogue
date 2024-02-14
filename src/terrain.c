#include "terrain.h"

Terrain* terrain_new(Object* object, int x, int y, bool solid) {
    Terrain* result = malloc(sizeof(Terrain));
 
    result->object = object;
    result->x = x;
    result->y = y;
    result->solid = solid;   
    
    return result;
}

void terrain_free(void* terrain) {
    if (terrain) {
        Terrain* ptr = (Terrain*) terrain;
        
        object_free(ptr->object);
        free(ptr);
    }
}

