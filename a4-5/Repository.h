#pragma once
#include "Domain.h"
#include "DynamicVector.h"

class Repository {
private:
	DynamicVector dogs;
public:
	Repository();
	DynamicVector getDogs();
	void addDogRepo(Dog* dog);
	void removeDogRepo(Dog* dog);
	void updateDogBreed(Dog* dog, char breed[20]);
	void updateDogName(Dog* dog, char name[20]);
	void updateDogAge(Dog* dog, int age);
	int getSizeRepo();
	Dog* getElements();
	Dog* searchDog(char name[20], char breed[20], int age);

	~Repository();
};