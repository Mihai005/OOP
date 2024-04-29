#pragma once
#include "Domain.h"
#include <vector>
#include <typeinfo>

class Exceptions : public exception
{
private:
	string message;
public:
	Exceptions(const string& message) : message{ message } {}
	const char* what() const noexcept override
	{
		return message.c_str();
	}
};

class DogValidator {
public: 
	static void validate(Dog d) {
		if (d.getName().size() < 3)
			throw Exceptions("The name of the dog is too short!");
		if (d.getBreed().size() < 3)
			throw Exceptions("The breed of the dog is too short!");
		if (d.getAge() < 0)
			throw Exceptions("The age of the dog is negative!");
	}
};

class OptionValidator {
public:
	static void validateMenuAdmin(string option) {
		if (option != "0" && option != "1" && option != "2" && option != "3" && option != "4")
			throw Exceptions("Please enter a valid input!");
	}
	static void validateMenuUser(string optionuser) {
		if (optionuser != "0" && optionuser != "1" && optionuser != "2" && optionuser != "3" && optionuser != "4")
			throw Exceptions("Please enter a valid input!");
	}
};