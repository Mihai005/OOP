#include "OperationStack.h"
#include "DynamicArray.h"
#include "Domain.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Operation* createOperation(Medicine* m, char* operationType)
{
	Operation* o = malloc(sizeof(Operation));
	if (o == NULL)
		return NULL;
	o->medicine = copyPlanet(m);

	if (operationType != NULL)
	{
		o->operationType = malloc(sizeof(char) * (strlen(operationType) + 1));
		if (o->operationType == NULL)
		{
			free(o);
			return NULL;
		}
		strcpy(o->operationType, operationType);
	}
	else
		o->operationType = NULL;

	return o;
}

void destroyOperation(Operation* o)
{
	if (o == NULL)
		return;

	destroyPlanet(o->medicine);
	free(o->operationType);
	free(o);
}

Operation* copyOperation(Operation* o)
{
	if (o == NULL)
		return NULL;
	Operation* copy = createOperation(getPlanet(o), getOperationType(o));
	return copy;
}

char* getOperationType(Operation* o)
{
	return o->operationType;
}

Medicine* getMedicine(Operation* o)
{
	return o->medicine;
}

OperationsStack* createStack()
{
	OperationsStack* s = malloc(sizeof(OperationsStack));
	if (s == NULL)
		return NULL;
	s->stack = createDynamicArray(10, &destroyOperation);
	if (s->stack == NULL)
	{
		free(s);
		return NULL;
	}

	return s;
}

void destroyStack(OperationsStack* s)
{
	if (s == NULL)
		return;

	destroy(s->stack);

	free(s);
}

void push(OperationsStack* s, Operation* o)
{
	if (s == NULL || o == NULL)
		return;
	addElement(s->stack, o);
}

Operation* pop(OperationsStack* s)
{
	if (s == NULL)
		return NULL;
	int lastPos = getLength(s->stack) - 1;
	Operation* o = (Operation*)get(s->stack, lastPos); // must cast it to Operation*, as it is a void*
	// make a copy to use it for redo as well
	Operation* lastOp = copyOperation(o);
	deleteElement(s->stack, lastPos);
	return lastOp;
}

int isEmpty(OperationsStack* s)
{
	if (s == NULL)
		return 1;
	return (getLength(s->stack) == 0);
}
