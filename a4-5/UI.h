#pragma once
#include "Domain.h"
#include "Repository.h"
#include "Service.h"
#include <iostream>
#include <string>

class UI {
private:
	Service service = Service();
public: 
	void run();
private:
	void choosemode(std::string& option);
	void printMenuAdmin(int& optionadmin);
	void printMenuUser(int& optionuser);
	void defaultshelter();

	void printDogsUI();
	void addDogUI();
	void deleteDogUI();
	void updateDogUI();
};