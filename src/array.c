#include "array.h"

static const size_t ARRAY_INCREMENT = 32;

static void array_allocate_space(Array *array)
{
	if (array->length == array->_space)
	{
		array->data = realloc(array->data, sizeof(void *) * (array->_space + ARRAY_INCREMENT));
		array->_space += ARRAY_INCREMENT;
	}
	else if (array->length == array->_space - ARRAY_INCREMENT)
	{
		array->data = realloc(array->data, sizeof(void *) * (array->_space - ARRAY_INCREMENT));
		array->_space -= ARRAY_INCREMENT;
	}
}

Array *array_new(void (*free_func)(void *))
{
	Array *result = malloc(sizeof(Array));

	result->_space = ARRAY_INCREMENT;
	result->length = 0;
	result->data = malloc(sizeof(void *) * ARRAY_INCREMENT);
	result->free_func = free_func;

	return result;
}

void array_free(void *array)
{
	if (array)
	{
		Array *ptr = (Array *)array;

		array_free_contents(ptr);
		free(ptr->data);
		free(ptr);
	}
}

void array_free_contents(Array *array)
{
	for (size_t i = 0; i < array->length; i++)
	{
		array->free_func(array->data[i]);
	}

	array->_space = ARRAY_INCREMENT;
	array->length = 0;
	array->data = realloc(array->data, sizeof(void *) * ARRAY_INCREMENT);
}

void array_push(Array *array, void *obj)
{
	array->data[array->length++] = obj;
	array_allocate_space(array);
}

void array_insert(Array *array, void *obj, size_t index)
{
	for (size_t i = array->length - 1; i >= index; i--)
	{
		array->data[i + 1] = array->data[i];
	}

	array->data[index] = obj;
	array->length++;
	array_allocate_space(array);
}

void *array_pop(Array *array)
{
	void *result = array->data[--array->length];
	array->data[array->length] = NULL;
	array_allocate_space(array);

	return result;
}

void *array_remove(Array *array, size_t index)
{
	void *result = array->data[index];

	for (size_t i = index; i < array->length - 1; i++)
	{
		array->data[i] = array->data[i + 1];
	}

	array->data[--array->length] = NULL;
	array_allocate_space(array);

	return result;
}

void *array_remove_ptr(Array *array, void *obj)
{
	size_t index = -1;

	for (size_t i = 0; i < array->length; i++)
	{
		if (array->data[i] == obj)
		{
			index = i;
			break;
		}
	}

	return index != -1 ? array_remove(array, index) : NULL;
}