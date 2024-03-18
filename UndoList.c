#include "UndoList.h"
#include <stdlib.h>
#include <stdio.h>

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
		destroyDynamicArray(&list->array[i]);
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
