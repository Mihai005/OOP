#pragma once

#include "DynamicArray.h"
#include "Domain.h"

typedef struct
{
	Medicine* medicine;
	char* operationType;
}Operation;

Operation* createOperation(Medicine* m, char* operationType);
void destroyOperation(Operation* o);
Operation* copyOperation(Operation* o);
char* getOperationType(Operation* o);
Medicine* getMedicine(Operation* o);

typedef struct
{
	DynamicArray* stack;
} OperationsStack;

OperationsStack* createStack();
void destroyStack(OperationsStack* s);
void push(OperationsStack* s, Operation* o);
Operation* pop(OperationsStack* s);
int isEmpty(OperationsStack* s);

