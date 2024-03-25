#pragma once
#include "Domain.h"

typedef Dog TElem;

class DynamicVector
{
private:
	TElem* elements;
	int size;
	int capacity;
	void resize();
public:
	DynamicVector();
	DynamicVector(int capacity);

	int getSize();
	int getCapacity();
	TElem* getElements();
	TElem* getElement(int pos);

	void addElement(TElem e);
	void deleteElement(TElem* e);

	// create copy constructor
    DynamicVector(const DynamicVector& v);

	~DynamicVector();

	void testDynamicVector();
};
