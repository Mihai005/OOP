#include "DynamicArray.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

void setSize(DynamicArray* arr, int size)
{
	arr->size = size;
}

void setCapacity(DynamicArray* arr, int capacity)
{
	arr->capacity = capacity;
}

Medicine* getElement(DynamicArray* arr, int index)
{
	return &arr->elems[index];
}

void setElement(DynamicArray* arr, int position, char* name, int concentration, int quantity, int price)
{
	arr->elems[position].name = (char*)malloc(sizeof(char) * strlen(name) + 1);
	arr->elems[position].concentration = concentration;
	strcpy(arr->elems[position].name, name);
	arr->elems[position].price = price;
	arr->elems[position].quantity = quantity;
}
