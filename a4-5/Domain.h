#pragma once
#include <iostream>
#include <string>

using namespace std;

class Dog {
private:
	char* breed;
	char* name;
	char* photograph; 
	int age;

public:
	Dog();
	void CreateDog(char* breed, char* name, int age, char* photograph);
	const char* getBreed();
	const char* getName();
	const int getAge();
	const char* getPhotograph();

	void setBreed(char* b);
	void setName(char* n);
	void setAge(int a);
	void setPhotograph(char* p);

	string Representation() const {
		string representation = "Breed: ";
		representation += breed;
		representation += ", Name: ";
		representation += name;
		representation += ", Age: ";
		representation += to_string(age);
		representation += ", Photograph: ";
		representation += photograph;
		return representation;
	}

	bool operator==(const Dog& d) {
		return strcmp(this->name, d.name) == 0 && strcmp(this->breed, d.breed) == 0 && this->age == d.age;
	}

	~Dog();
};