#pragma once
#include "DynamicVector.h"
#include "Domain.h"
#include "Repository.h"

class Service {
private:
	Repository repo = Repository();
public:
	int getSizeService();
	Dog* getElement();

	Dog* searchDogService(char name[20], char breed[20], int age);
	void updateBreedService(Dog* d, char breed[20]);
	void updateNameService(Dog* d, char name[20]);
	void updateAgeService(Dog* d, int age);

	void removeDogService(Dog* d);
	void addDogService(Dog* d);
};