#include "UndoList.h"
#include "DynamicArray.h"
#include "Domain.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

UndoList* createUndoList(int maxcapacity)
{
	UndoList* list = malloc(sizeof(UndoList));
	if (list == NULL)
		return NULL;
	set_capacity_undo(list, maxcapacity);
    set_size_undo(list, 0);
	list->array = malloc(sizeof(DynamicArray) * maxcapacity);
	if (list->array == NULL)
		return ((void*)0);
	return list;
}

void resizeUndo(UndoList* list)
{
	if (list == NULL)
		return;
	set_capacity_undo(list, get_capacity_undo(list) * 2);
	DynamicArray* aux = realloc(list->array, list->capacity * sizeof(DynamicArray));
	if (aux == NULL)
		return;
	list->array = aux;
}

void removeUndoList(UndoList* list)
{
	if (list == NULL)
		return;

	set_size_undo(list, get_size_undo(list)-1);   
}

void destroyUndoList(UndoList* list)
{
	if (list == NULL)
		return;
	for (int i = 0; i < get_size_undo(list); i++)
	{
		for (int j = 0; j < getSize(get_undo_array(list, i)); j++)
			free(get_name(&get_undo_array(list, i)->elems[j]));
		free(getElems(get_undo_array(list, i)));
	}
    free(list->array);
	free(list);
}

int get_size_undo(UndoList* list)
{
	return list->size;
}

int get_capacity_undo(UndoList* list)
{
	return list->capacity;
}

void set_size_undo(UndoList* list, int size)
{
	list->size = size;
}

void set_capacity_undo(UndoList* list, int capacity)
{
	list->capacity = capacity;
}

DynamicArray* get_undo_array(UndoList* list, int position)
{
	return &list->array[position];
}

void decreaseUndoListSize(UndoList* list, int newSize) {
	if (newSize >= list->size) {
		return;  // Nothing to do
	}

	for (int i = newSize; i < list->size; i++) {
		// Free any dynamically allocated memory in each element
		printf("1");
		for (int j = 0; j < list->array[i].size; j++) {
			free(list->array[i].elems[j].name);
		}
		free(list->array[i].elems);
	}

	// Adjust the size of the undo list
	list->size = newSize;
}

void testundolist()
{
	UndoList* list;
	list = createUndoList(10);
	assert(get_capacity_undo(list) == 10);
	assert(get_size_undo(list) == 0);
	assert(get_size_undo(list) == 0);
	assert(get_capacity_undo(list) == 10);
	assert(get_size_undo(list) == 0);
	destroyUndoList(list);
	UndoList* redo;
	redo = createUndoList(15);
	assert(get_capacity_undo(redo) == 15);
	assert(get_size_undo(redo) == 0);
	assert(get_size_undo(redo) == 0);
	assert(get_capacity_undo(redo) == 15);
	assert(get_size_undo(redo) == 0);
	destroyUndoList(redo);
}
