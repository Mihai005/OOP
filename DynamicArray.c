#include "DynamicArray.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
  Creates a dynamic array with a given capacity
	INPUT: maxcapacity - integer
	OUTPUT: a pointer to a dynamic array
  
*/

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

/*
  Destroys a dynamic array
	INPUT: arr - pointer to a dynamic array
	OUTPUT: none
*/

void destroyDynamicArray(DynamicArray* arr)
{
	if (arr == NULL)
		return;
	for (int i = 0; i < arr->size; i++)
		 free(arr->elems[i].name);
	free(arr->elems);
    free(arr);
}

/*
  Resizes a dynamic array
	INPUT: arr - pointer to a dynamic array
	OUTPUT: none
*/

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

/*
  Adds an element to a dynamic array
	INPUT: arr - pointer to a dynamic array, elem - Medicine
	OUTPUT: none
*/
void addElemToDyamicArray(DynamicArray* arr, Medicine elem)
{
	if (arr->capacity == arr->size)
		resize(arr);
	arr->elems[arr->size++] = elem;
}

/*
  Returns the size of a dynamic array
	INPUT: arr - pointer to a dynamic array
	OUTPUT: an integer
*/
int getSize(DynamicArray* arr)
{
	if (arr == NULL)
		return 0;
	return arr->size;
}

/*
  Returns the capacity of a dynamic array
	INPUT: arr - pointer to a dynamic array
	OUTPUT: an integer
*/
int getCapacity(DynamicArray* arr)
{
	if (arr == NULL)
		return 0;
	return arr->capacity;
}

/*
  Sets the size of a dynamic array
	INPUT: arr - pointer to a dynamic array, size - integer
	OUTPUT: none
*/
void setSize(DynamicArray* arr, int size)
{
	arr->size = size;
}

/*
  Sets the capacity of a dynamic array
	INPUT: arr - pointer to a dynamic array, capacity - integer
	OUTPUT: none
*/
void setCapacity(DynamicArray* arr, int capacity)
{
	arr->capacity = capacity;
}

/*
  Returns an element from a dynamic array
	INPUT: arr - pointer to a dynamic array, index - integer
	OUTPUT: a pointer to a Medicine
*/
Medicine* getElement(DynamicArray* arr, int index)
{
	return &arr->elems[index];
}

/*
  Sets an element from a dynamic array
	INPUT: arr - pointer to a dynamic array, position - integer, name - string, concentration - integer, quantity - integer, price - integer
	OUTPUT: none
*/

void setElement(DynamicArray* arr, int position, char* name, int concentration, int quantity, int price)
{
	arr->elems[position].name = (char*)malloc(sizeof(char) * strlen(name) + 1);
	arr->elems[position].concentration = concentration;
	strcpy(arr->elems[position].name, name);
	arr->elems[position].price = price;
	arr->elems[position].quantity = quantity;
}

/*
  Returns the elements from a dynamic array
	INPUT: arr - pointer to a dynamic array
	OUTPUT: a pointer to a Medicine
*/

Medicine* getElems(DynamicArray* arr)
{
	return arr->elems;
}

/*
  Sets the elements from a dynamic array
	INPUT: arr - pointer to a dynamic array, newElems - pointer to a Medicine
	OUTPUT: none
*/

void setElems(DynamicArray* arr, Medicine* newElems)
{
	
	arr->elems = newElems;
}