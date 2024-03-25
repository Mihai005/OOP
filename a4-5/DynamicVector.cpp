#include "DynamicVector.h"
#include "Domain.h"


DynamicVector::DynamicVector()
{
	this->size = 0;
	this->capacity = 10;
	this->elements = new TElem[10];
}

void DynamicVector::resize()
{
	this->capacity *= 2;
	TElem* newElements = new TElem[this->capacity];
	for (int i = 0; i < this->size; i++)
		newElements[i] = this->elements[i];
	delete[] this->elements;
	this->elements = newElements;
	/// to do implementation; it doesn't work; it raises an exception
}

DynamicVector::DynamicVector(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->elements = new TElem[capacity];
}

TElem* DynamicVector::getElements()
{
	return this->elements;
}

int DynamicVector::getSize()
{
	return this->size;
}

int DynamicVector::getCapacity()
{
	return this->capacity;
}

void DynamicVector::addElement(TElem* d)
{
	if (this->size== this->capacity)
		this->resize();
	this->elements[this->size++] = *d;
}

TElem* DynamicVector::getElement(int pos)
{
	return &this->elements[pos];
}

void DynamicVector::deleteElement(TElem* d)
{
	for (int i = 0; i < this->size; i++)
		if (this->elements[i] == *d)
		{
			for (int j = i; j < this->size - 1; j++)
				this->elements[j] = this->elements[j + 1];
			this->size--;
			break;
		}
}

DynamicVector::DynamicVector(const DynamicVector& v)
{
	this->size = v.size;
	this->capacity = v.capacity;
	this->elements = new TElem[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elements[i] = v.elements[i];
}

DynamicVector::~DynamicVector()
{
	delete[] this->elements;
}
