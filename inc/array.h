#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>

typedef struct
{
	size_t _space;
	size_t length;
	void **data;
	void (*free_func)(void *);
} Array;

Array *array_new(void (*free_func)(void *));
void array_free(void *array);
void array_free_contents(Array *array);
void array_push(Array *array, void *obj);
void array_insert(Array *array, void *obj, size_t index);
void *array_pop(Array *array);
void *array_remove(Array *array, size_t index);
void *array_remove_ptr(Array *array, void *obj);

#endif