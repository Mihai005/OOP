#include "Domain.h"
#include "DynamicVector.h"
#include "Repository.h"
#include "Service.h"
#include <cassert>


int Service::getSizeService()
{
	/// getter for the size of the repository
	return this->repo.getSizeRepo();
}

int Service::getSizeServiceAdoption()
{
	/// getter for the size of the adoption list
	return this->repo.getSizeAdoptionList();
}

Dog* Service::getElement()
{
	/// getter for the elements of the repository
	return this->repo.getElements();
}

Dog* Service::getElementAdoption()
{
	/// getter for the elements of the adoption list
	return this->repo.getElementsAdoption();
}

Dog* Service::searchDogService(string name, string breed, int age)
{
	/// searches for a dog in the repository
	/// input: name, breed, age - strings
	/// output: the dog if it exists, an exception otherwise
	Dog* dogs = this->repo.getElements();
	for (int i = 0; i < this->repo.getSizeRepo(); i++)
	{
		if ((dogs[i].getBreed() == breed) && (dogs[i].getName() == name) && (dogs[i].getAge() == age))
			return this->repo.getElementRepo(i);
	}
	throw exception("Dog not found!");
}

void Service::updateBreedService(Dog* d, string breed)
{
	/// updates the breed of a dog
	this->repo.updateDogBreed(d, breed);
}

void Service::updateNameService(Dog* d, string name)
{
	/// updates the name of a dog
	this->repo.updateDogName(d, name);
}

void Service::updateAgeService(Dog* d, int age)
{
	/// updates the age of a dog
	this->repo.updateDogAge(d, age);
}

void Service::removeDogService(Dog* d)
{
	/// removes a dog from the repository
	this->repo.removeDogRepo(d);
}

void Service::addDogService(Dog d)
{
	/// adds a dog to the repository
	this->repo.addDogRepo(d);
}

void Service::addAdoptionListService(Dog* d)
{
	/// adds a dog to the adoption list
	this->repo.addAdoptionListRepo(d);
}

int Service::checkInput(string breed, string name, int age, string link)
{
	/// checks if the input is valid
	if (breed.size() == 0 || (breed[0] >= '0' && breed[0] <= '9'))
		throw invalid_argument("Invalid breed!");
	if (name.size() == 0 || (name[0] >= '0' && name[0] <= '9'))
		throw invalid_argument("Invalid name!");
	if (age < 0)
		throw invalid_argument("Invalid age!");
	if (link.substr(0, 4) != "http")
		throw invalid_argument("Invalid link!");
	return 1;
}

int Service::checkAlreadyExists(Dog d)
{
	/// checks if a dog already exists in the repository
	/// input: d - Dog
	/// output: 1 if the dog already exists, 0 otherwise
	Dog* dogs = this->repo.getElements();
	for (int i = 0; i < this->repo.getSizeRepo(); i++)
		if (dogs[i] == d)
			throw exception("Dog already exists!");
	return 1;
}

Service::~Service()
{
	/// destructor
}
