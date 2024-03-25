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

	Dog* searchDogService(string name, string breed, int age);
	void updateBreedService(Dog* d, string breed);
	void updateNameService(Dog* d, string name);
	void updateAgeService(Dog* d, int age);

	void removeDogService(Dog* d);
	void addDogService(Dog d);
    
	int checkInput(string breed, string name, int age, string link);
	int checkAlreadyExists(Dog d);
	~Service();

	void testService();
};