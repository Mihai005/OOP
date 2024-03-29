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
	int run();
	~UI();
private:
	void choosemode(string& option);
	void printMenuAdmin(string& optionadmin);
	void printMenuUser(string& optionuser);
	void defaultshelter();

	void printDogsUI();
	void addDogUI();
	void deleteDogUI();
	void updateDogUI();

	void printDogsUserUI();
	void printDogsByBreedUI();
	void printAdoptionListUI();

};