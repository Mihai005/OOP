#include "Domain.h"
#include <iostream>
#include <string.h>

Dog::Dog()
{
	this->breed = NULL;
	this->name = NULL;
	this->age = 0;
	this->photograph = NULL;
}

void Dog::CreateDog(char* breed, char* name, int age, char* photograph)
{
	this->breed = new char[strlen(breed) + 1];
	strcpy(this->breed, breed);
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->age = age;
	this->photograph = new char[strlen(photograph) + 1];
	strcpy(this->photograph, photograph);
}

const char* Dog::getBreed()
{
	return this->breed;
}

const char* Dog::getName()
{
	return this->name;
}

const int Dog::getAge()
{
	return this->age;
}

const char* Dog::getPhotograph()
{
	return this->photograph;
}

void Dog::setBreed(char* b)
{
	this->breed = new char[strlen(b) + 1];
	strcpy(this->breed, b);
}

void Dog::setName(char* n)
{
	this->name = new char[strlen(n) + 1];
	strcpy(this->name, n);
}

void Dog::setAge(int a)
{
	this->age = a;
}

void Dog::setPhotograph(char* p)
{
	this->photograph = p;
}

Dog::~Dog()
{
	delete[] breed;
	delete[] name;
	delete[] photograph;
}
