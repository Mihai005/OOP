#include "Repository.h"
#include "DynamicVector.h"
#include <iostream>

Repository::Repository()
{
}

DynamicVector Repository::getDogs()
{
	return this->dogs;
}

void Repository::addDogRepo(Dog* dog)
{
	this->dogs.addElement(dog);
}

void Repository::removeDogRepo(Dog* dog)
{
	this->dogs.deleteElement(dog);
}

void Repository::updateDogBreed(Dog* dog, char breed[20])
{
	dog->setBreed(breed);
}

void Repository::updateDogName(Dog* dog, char name[20])
{
	dog->setName(name);
}

void Repository::updateDogAge(Dog* dog, int age)
{
	dog->setAge(age);
}

Repository::~Repository()
{
	delete this;
}

int Repository::getSizeRepo()
{
	return this->dogs.getSize();
}

Dog* Repository::getElements()
{
	return this->dogs.getElements();
}

Dog* Repository::searchDog(char name[20], char breed[20], int age)
{
	Dog* dogs = this->dogs.getElements();
	for (int i = 0; i < this->dogs.getSize(); i++)
	{
		if (strcmp(dogs[i].getBreed(), breed) == 0 && strcmp(dogs[i].getName(), name) == 0 && dogs[i].getAge() == age)
			return this->dogs.getElement(i);
	}
	dogs = NULL;
	return dogs;
}