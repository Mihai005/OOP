#include "DynamicArray.h"
#include <stdlib.h>

DynamicArray* createDynamicArray(int maxcapacity)
{
	DynamicArray* arr = malloc(sizeof(DynamicArray));
	if (arr == NULL)
		return NULL;
	arr->capacity = maxcapacity;
	arr->size = 0;
	arr->elems = malloc(sizeof(Medicine) * maxcapacity);
	if (arr->elems == NULL)
		return NULL;
	return arr;

}

void destroyDynamicArray(DynamicArray* arr)
{
	if (arr == NULL)
		return;
	for (int i = 0; i < arr->size; i++)
		free(arr->elems[i].name);
	free(arr->elems);
    free(arr);
}

void resize(DynamicArray* arr)
{
	if (arr == NULL)
		return;
	arr->capacity *= 2;
	Medicine* aux = realloc(arr->elems, arr->capacity * sizeof(Medicine));
	if (aux == NULL)
		return;
	arr->elems = aux;
}

void addElemToDyamicArray(DynamicArray* arr, Medicine elem)
{
	if (arr->capacity == arr->size)
		resize(arr);
	arr->elems[arr->size++] = elem;
}

int getSize(DynamicArray* arr)
{
	if (arr == NULL)
		return 0;
	return arr->size;
}

int getCapacity(DynamicArray* arr)
{
	if (arr == NULL)
		return 0;
	return arr->capacity;
}

