#ifndef OBJECT_H
#define OBJECT_H

#include <string.h>
#include "terminal.h"

typedef struct
{
    chtype glyph;
    attr_t color;
    char *name;
    char *description;
} Object;

Object *object_new(chtype glyph, attr_t color, char *name, char *description);
void object_free(void *object);

#endif