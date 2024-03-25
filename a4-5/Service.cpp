#include "Domain.h"
#include "DynamicVector.h"
#include "Repository.h"
#include "Service.h"


int Service::getSizeService()
{
	return this->repo.getSizeRepo();
}

Dog* Service::getElement()
{
	return this->repo.getElements();
}

Dog* Service::searchDogService(char name[20], char breed[20], int age)
{
	return this->repo.searchDog(name, breed, age);
}

void Service::updateBreedService(Dog* d, char breed[20])
{
	this->repo.updateDogBreed(d, breed);
}

void Service::updateNameService(Dog* d, char name[20])
{
	this->repo.updateDogName(d, name);
}

void Service::updateAgeService(Dog* d, int age)
{
	this->repo.updateDogAge(d, age);
}

void Service::removeDogService(Dog* d)
{
		this->repo.removeDogRepo(d);
}

void Service::addDogService(Dog* d)
{
	this->repo.addDogRepo(d);
}