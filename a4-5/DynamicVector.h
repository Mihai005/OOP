#pragma once
#include "Domain.h"
#include <typeinfo>
#include <assert.h>
//typedef Dog TElem;
/// include cpp file here

template <typename TElem>

class DynamicVector
{
private:
	TElem* elements;
	int size;
	int capacity;
	void resize() {
		/// resize the current DynamicVector, double the capacity
		this->capacity *= 2;
		TElem* newElements = new TElem[this->capacity];
		for (int i = 0; i < this->size; i++)
			newElements[i] = this->elements[i];
		this->elements = newElements;
	};
public:
	DynamicVector() {
		/// default constructor
		this->size = 0;
		this->capacity = 10;
		this->elements = new TElem[10];
	};
	DynamicVector(int capacity){
		/// constructor with capacity
	this->size = 0;
	this->capacity = capacity;
	this->elements = new TElem[capacity];
	};

	int getSize() {
		/// return the size of the DynamicVector
		return this->size;
	};
	int getCapacity() {
		/// return the capacity of the DynamicVector
		return this->capacity;
	};
	TElem* getElements()
	{
		/// return the elements of the DynamicVector
		return this->elements;
	};
	TElem* getElement(int pos) {
		return &this->elements[pos];
	};

	void addElement(TElem d) {
		/// add an element to the DynamicVector
		if (this->size == this->capacity)
			this->resize();
		this->elements[this->size++] = d;
	};
	void deleteElement(TElem* d) {
		/// delete an element from the DynamicVector
		for (int i = 0; i < this->size; i++)
			if (this->elements[i] == *d)
			{
				for (int j = i; j < this->size - 1; j++)
					this->elements[j] = this->elements[j + 1];
				this->size--;
				break;
			}
	};

	DynamicVector(const DynamicVector& v) {
		/// copy constructor
		this->size = v.size;
		this->capacity = v.capacity;
		this->elements = new TElem[this->capacity];
		for (int i = 0; i < this->size; i++)
			this->elements[i] = v.elements[i];
	};

	~DynamicVector() {
		/// destructor
		delete[] this->elements;
	};

};
