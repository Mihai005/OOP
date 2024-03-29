#pragma once
#include "Domain.h"
#include "DynamicVector.h"
#include <typeinfo>

class Repository {
private:
	DynamicVector<Dog> dogs;
	DynamicVector<Dog> adoptionList;
public:
	Repository();
	void addDogRepo(Dog dog);
	void removeDogRepo(Dog* dog);
	void updateDogBreed(Dog* dog, string breed);
	void updateDogName(Dog* dog, string name);
	void updateDogAge(Dog* dog, int age);
	void addAdoptionListRepo(Dog* dog);
	int getSizeRepo();
	Dog* getElements();
	Dog* getElementRepo(int pos);
	Dog* getElementsAdoption();
	int getSizeAdoptionList();

	~Repository();

};