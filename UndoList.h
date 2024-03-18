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

int get_size_undo(UndoList* list);
int get_capacity_undo(UndoList* list);
void set_size_undo(UndoList* list, int size);
void set_capacity_undo(UndoList* list, int capacity);
DynamicArray* get_undo_array(UndoList* list, int position);
void decreaseUndoListSize(UndoList* list, int newSize);

void testundolist();