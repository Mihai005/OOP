#pragma once
#include "Domain.h"
#include "DynamicVector.h"

class Repository {
private:
	DynamicVector dogs;
public:
	Repository();
	DynamicVector getDogs();
	void addDogRepo(Dog dog);
	void removeDogRepo(Dog* dog);
	void updateDogBreed(Dog* dog, string breed);
	void updateDogName(Dog* dog, string name);
	void updateDogAge(Dog* dog, int age);
	int getSizeRepo();
	Dog* getElements();
	Dog* getElementRepo(int pos);

	~Repository();

	void testRepository();
};