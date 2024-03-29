#include "Repository.h"
#include "DynamicVector.h"
#include <iostream>
#include <cassert>

Repository::Repository()
{
	/// constructor
}

void Repository::addDogRepo(Dog dog)
{
	/// adds a dog to the repository
    this->dogs.addElement(dog);
}

void Repository::removeDogRepo(Dog* dog)
{
	/// removes a dog from the repository
	this->dogs.deleteElement(dog);
}

void Repository::updateDogBreed(Dog* dog, string breed)
{
	/// updates the breed of a dog
	dog->setBreed(breed);
}

void Repository::updateDogName(Dog* dog, string name)
{
	/// updates the name of a dog
	dog->setName(name);
}

void Repository::updateDogAge(Dog* dog, int age)
{
	/// updates the age of a dog
	dog->setAge(age);
}

Repository::~Repository()
{
		/// destructor
}

int Repository::getSizeRepo()
{
	/// returns the size of the repository
	return this->dogs.getSize();
}

int Repository::getSizeAdoptionList()
{
	/// returns the size of the adoption list
	return this->adoptionList.getSize();
}

Dog* Repository::getElements()
{
	/// returns the elements of the repository
	return this->dogs.getElements();
}

Dog* Repository::getElementsAdoption()
{
    /// returns the elements of the adoption list
	return this->adoptionList.getElements();

}

Dog* Repository::getElementRepo(int pos)
{
	/// returns the element from a given position
	return this->dogs.getElement(pos);
}

void Repository::addAdoptionListRepo(Dog* dog)
{
	/// adds a dog to the adoption list
	this->adoptionList.addElement(*dog);
}
