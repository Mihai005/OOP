#include "Domain.h"
#include <iostream>
#include <string.h>
#include <cassert>

Dog::Dog()
{
	/// initializes an empty dog
	this->breed = "";
	this->name = "";
	this->age = 0;
	this->photograph = "";
}

void Dog::CreateDog(string breed, string name, int age, string photograph)
{
	/// creates a dog with the given parameters
	this->breed = breed;
	this->name = name;
	this->age = age;
	this->photograph = photograph;
}

const string Dog::getBreed()
{
	/// returns the breed of the dog
	return this->breed;
}

const string Dog::getName()
{
	/// returns the name of the dog
	return this->name;
}

const int Dog::getAge()
{
	/// returns the age of the dog
	return this->age;
}

const string Dog::getPhotograph()
{
	/// returns the photograph of the dog
	return this->photograph;
}

void Dog::setBreed(string b)
{
	/// sets the breed of the dog
	this->breed = b;
}

void Dog::setName(string n)
{
	/// sets the name of the dog
	this->name = n;
}

void Dog::setAge(int a)
{
	/// sets the age of the dog
	this->age = a;
}

void Dog::setPhotograph(string p)
{
	/// sets the photograph of the dog
	this->photograph = p;
}

Dog::~Dog()
{
	/// destructor
} 


void Dog::testDomain()
{
	Dog d = Dog();
	d.CreateDog("Breed", "Name", 10, "https://testdog.com");
	assert(d.getBreed() == "Breed");
	assert(d.getName() == "Name");
	assert(d.getAge() == 10);
	assert(d.getPhotograph() == "https://testdog.com");
	d.setBreed("Breed2");
	d.setName("Name2");
	d.setAge(20);
	d.setPhotograph("https://alink.com");
	assert(d.getBreed() == "Breed2");
	assert(d.getName() == "Name2");
	assert(d.getAge() == 20);
	assert(d.getPhotograph() == "https://alink.com");
	cout << "Domain tests passed successfully!\n";
}
