#pragma once
#include "Domain.h"

typedef struct
{
	int capacity;
	int size;
	Medicine* elems;
}DynamicArray;

DynamicArray* createDynamicArray(int maxcapacity);
void destroyDynamicArray(DynamicArray* arr);
void addElemToDyamicArray(DynamicArray* arr, Medicine elem);
int getSize(DynamicArray* arr);
int getCapacity(DynamicArray* arr);
void resize(DynamicArray* arr);