#include "UndoList.h"
#include <stdlib.h>

UndoList* createUndoList(int maxcapacity)
{
	UndoList* list = malloc(sizeof(UndoList));
	if (list == NULL)
		return NULL;
	list->capacity = maxcapacity;
	list->size = 0;
	list->array = malloc(sizeof(DynamicArray) * maxcapacity);
	if (list->array == NULL)
		return NULL;
	return list;
}

void resizeUndo(UndoList* list)
{
	if (list == NULL)
		return;
	list->capacity *= 2;
	DynamicArray* aux = realloc(list->array, list->capacity * sizeof(DynamicArray));
	if (aux == NULL)
		return;
	list->array = aux;
}

void removeUndoList(UndoList* list)
{
	if (list == NULL)
		return;
	list->size--;
    
}

void destroyUndoList(UndoList* list)
{
	if (list == NULL)
		return;
	for (int i = 0; i < list->size; i++)
		destroyDynamicArray(&list->array[i]);
	free(list->array);
	free(list);
}
