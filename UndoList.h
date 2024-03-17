#pragma once
#include "DynamicArray.h"

typedef struct
{
	int size;
	int capacity;
	DynamicArray* array;
}UndoList;

UndoList* createUndoList(int maxcapacity);
void resizeUndo(UndoList* list);
void removeUndoList(UndoList* list);
void destroyUndoList(UndoList* list);