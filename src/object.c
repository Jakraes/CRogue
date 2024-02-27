#include "object.h"

Object *object_new(char *glyph, attr_t color, char *name, char *description)
{
    Object *result = malloc(sizeof(Object));

    result->glyph = strdup(glyph);
    result->color = color;
    result->name = strdup(name);
    result->description = description;

    return result;
}

void object_free(void *object)
{
    if (object)
    {
        free(object);
    }
}