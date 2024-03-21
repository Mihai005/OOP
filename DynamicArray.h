#pragma once
#include "Domain.h"

typedef struct
{
	int capacity;
	int size;
	Medicine* elems;
}DynamicArray;

typedef struct
{
	DynamicArray* undoList;
	DynamicArray* redoList;
}UndoRedo;

DynamicArray* createDynamicArray(int maxcapacity);
void destroyDynamicArray(DynamicArray* arr);
void addElemToDyamicArray(DynamicArray* arr, Medicine elem);
int getSize(DynamicArray* arr);
int getCapacity(DynamicArray* arr);
void setSize(DynamicArray* arr, int size);
void setCapacity(DynamicArray* arr, int capacity);
void resize(DynamicArray* arr);
Medicine* getElement(DynamicArray* arr, int pos);
void setElement(DynamicArray* arr, int position, char* name, int concentration, int quantity, int price);
Medicine* getElems(DynamicArray* arr);
void setElems(DynamicArray* arr, Medicine* newElems);