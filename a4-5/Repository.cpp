#include "Repository.h"
#include "DynamicVector.h"
#include <iostream>
#include <cassert>

Repository::Repository()
{
	/// constructor
}

DynamicVector Repository::getDogs()
{
	/// getter for the dogs
	return this->dogs;
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

Dog* Repository::getElements()
{
	/// returns the elements of the repository
	return this->dogs.getElements();
}

Dog* Repository::getElementRepo(int pos)
{
	/// returns the element from a given position
	return this->dogs.getElement(pos);
}

void Repository::testRepository()
{
	/// tests the repository
	DynamicVector v;
	Dog d1 = Dog();
	d1.CreateDog("Husky", "Rex", 5, "www.photograph.com");
	Dog d2 = Dog();
	d2.CreateDog("Labrador", "Max", 3, "www.photograph.com");
	Dog d3 = Dog();
	d3.CreateDog("Pug", "Rex", 2, "www.photograph.com");
	v.addElement(d1);
	v.addElement(d2);
	v.addElement(d3);
	this->dogs = v;
	assert(this->getSizeRepo() == 3);
	cout << "Repository tests passed!" << "\n";
}