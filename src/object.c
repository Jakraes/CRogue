#include "object.h"

Object *object_new(chtype glyph, attr_t color, char *name, char *description)
{
    Object *result = malloc(sizeof(Object));

    result->glyph = glyph;
    result->color = color;
    result->name = strdup(name);
    result->description = strdup(description);

    return result;
}

void object_free(void *object)
{
    if (object)
    {
        Object *ptr = (Object *)object;

        free(ptr->name);
        free(ptr->description);
        free(ptr);
    }
}