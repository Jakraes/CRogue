#include "object.h"

Object* object_new(unsigned char glyph, attr_t color) {
    Object* result = malloc(sizeof(Object));
    
    result->glyph = glyph;
    result->color = color;
    
    return result;
}

void object_free(void* object) {
    if (object) {
        free(object);
    }
}