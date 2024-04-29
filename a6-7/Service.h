#pragma once

#include "Repository.h"

class Service {
private:
	Repository* repo;
public:
	Service(Repository* repo);
	int getSizeService();
	Dog* getElement();

	Dog* searchDogService(string name, string breed, int age);
	void updateBreedService(Dog* d, string breed);
	void updateNameService(Dog* d, string name);
	void updateAgeService(Dog* d, int age);

	void removeDogService(Dog* d);
	void addDogService(Dog d);

	void addAdoptionListService(Dog* d);

	int checkInput(string breed, string name, int age, string link);
	int checkAlreadyExists(Dog d);
	~Service();

	int getSizeServiceAdoption();
	Dog* getElementAdoption();

};