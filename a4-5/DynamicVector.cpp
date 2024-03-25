#include "DynamicVector.h"
#include "Domain.h"
#include <cassert>


DynamicVector::DynamicVector()
{
	/// constructor
	this->size = 0;
	this->capacity = 10;
	this->elements = new TElem[10];
}

void DynamicVector::resize()
{
	/// resize the current DynamicVector, double the capacity
	this->capacity *= 2;
	TElem* newElements = new TElem[this->capacity];
	for (int i = 0; i < this->size; i++)
		newElements[i] = this->elements[i];
	//delete[] this->elements; -> doesn't work if I uncomment this line
	this->elements = newElements;
	/// to do implementation; it doesn't work; it raises an exception
}

DynamicVector::DynamicVector(int capacity)
{
	/// constructor with capacity
	this->size = 0;
	this->capacity = capacity;
	this->elements = new TElem[capacity];
}

TElem* DynamicVector::getElements()
{
	/// return the elements of the DynamicVector
	return this->elements;
}

int DynamicVector::getSize()
{
	/// return the size of the DynamicVector
	return this->size;
}

int DynamicVector::getCapacity()
{
	/// return the capacity of the DynamicVector
	return this->capacity;
}

void DynamicVector::addElement(TElem d)
{
	/// add an element to the DynamicVector
	if (this->size== this->capacity)
		this->resize();
	this->elements[this->size++] = d;
}

TElem* DynamicVector::getElement(int pos)
{
	/// return the element from a given position
	return &this->elements[pos];
}

void DynamicVector::deleteElement(TElem* d)
{
	/// delete an element from the DynamicVector
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
	/// copy constructor
	this->size = v.size;
	this->capacity = v.capacity;
	this->elements = new TElem[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elements[i] = v.elements[i];
}

DynamicVector::~DynamicVector()
{
	/// destructor
	delete[] this->elements;
}


void DynamicVector::testDynamicVector() {
	DynamicVector vector1;
	assert(vector1.getSize() == 0);
	DynamicVector vector2(5);
	assert(vector2.getCapacity() == 5);
	Dog dog1 = Dog();
	dog1.CreateDog("Labrador", "Buddy", 2, "https://example.com");
	vector2.addElement(dog1);
	assert(vector2.getSize() == 1);
	Dog dog2 = Dog();
	dog2.CreateDog("Golden Retriever", "Max", 3, "https://example101.com");
	vector2.addElement(dog2);
	assert(vector2.getSize() == 2);
	Dog* retrievedDog = vector2.getElement(0);
	vector2.deleteElement(retrievedDog);
	assert(vector2.getSize() == 1);
	cout << "DynamicVector tests passed!" << "\n";
}