#ifndef OBJECT_H
#define OBJECT_H

#include <string.h>
#include "terminal.h"

typedef struct
{
    char *glyph;
    attr_t color;
    char *name;
    char *description;
} Object;

Object *object_new(char *glyph, attr_t color, char *name, char *description);
void object_free(void *object);

#endif