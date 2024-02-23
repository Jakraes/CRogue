#ifndef OBJECT_H
#define OBJECT_H

#include "terminal.h"

typedef struct
{
    unsigned char glyph;
    attr_t color;
    char *name;
    char *description;
} Object;

Object *object_new(unsigned char glyph, attr_t color, char *name, char *description);
void object_free(void *object);

#endif