#include "UI.h"
#include <iostream>
#include <exception>

using namespace std;

void UI::printMenuAdmin(int &optionadmin)
{
	std::cout << "Choose one option:\n";
	std::cout << "1. Add dog.\n";
	std::cout << "2. Delete dog.\n";
	std::cout << "3. Update dog.\n";
	std::cout << "4. Print dogs.\n";
	std::cout << "0. Exit.\n";
	std::cout << "Option: ";
	std::cin >> optionadmin;
	std::cout << "\n";
}

void UI::printMenuUser(int &optionuser)
{
	std::cout << "Choose one option:\n";
	std::cout << "1. See the dogs one by one\n";
	std::cout << "2. Adopt this dog\n";
	std::cout << "3. Don't adopt this dog and see next\n";
	std::cout << "4. See all the dogs of a breed, less than an age\n";
	std::cout << "5. See the adoption list\n";
	std::cout << "0. Exit\n";
	std::cout << "Option: ";
	std::cin >> optionuser;
	std::cout << "\n";
}

void UI::defaultshelter()
{
	char breed[] = "Husky";
	char name[] = "Rex";
	char photograph[] = "https://shelter/link1.com";
	Dog* d1 = new Dog();
	d1->CreateDog(breed, name, 1, photograph);
	this->service.addDogService(d1);
	char breed2[] = "Golden Retriever";
	char name2[] = "Max";
	char photograph2[] = "https://shelter/link2.com";
	Dog* d2 = new Dog();
	d2->CreateDog(breed2, name2, 2, photograph2);
	this->service.addDogService(d2);
	char breed3[] = "Labrador";
	char name3[] = "Bella";
	char photograph3[] = "https://shelter/link3.com";
	Dog* d3 = new Dog();
	d3->CreateDog(breed3, name3, 3, photograph3);
	this->service.addDogService(d3);
	char breed4[] = "Pug";
	char name4[] = "Luna";
	char photograph4[] = "https://shelter/link4.com";
	Dog* d4 = new Dog();
	d4->CreateDog(breed4, name4, 4, photograph4);
	this->service.addDogService(d4);
	char breed5[] = "Beagle";
	char name5[] = "Charlie";
	char photograph5[] = "https://shelter/link5.com";
	Dog* d5 = new Dog();
	d5->CreateDog(breed5, name5, 5, photograph5);
	this->service.addDogService(d5);
	char breed6[] = "Poodle";
	char name6[] = "Lucy";
	char photograph6[] = "https://shelter/link6.com";
	Dog* d6 = new Dog();
	d6->CreateDog(breed6, name6, 6, photograph6);
	this->service.addDogService(d6);
	char breed7[] = "Dalmatian";
	char name7[] = "Daisy";
	char photograph7[] = "https://shelter/link7.com";
	Dog* d7 = new Dog();
	d7->CreateDog(breed7, name7, 7, photograph7);
	this->service.addDogService(d7);
	char breed8[] = "German Shepherd";
	char name8[] = "Rocky";
	char photograph8[] = "https://shelter/link8.com";
	Dog* d8 = new Dog();
	d8->CreateDog(breed8, name8, 8, photograph8);
	this->service.addDogService(d8);
	char breed9[] = "Rottweiler";
	char name9[] = "Milo";
	char photograph9[] = "https://shelter/link9.com";
	Dog* d9 = new Dog();
	d9->CreateDog(breed9, name9, 9, photograph9);
	this->service.addDogService(d9);
	char breed10[] = "Doberman";
	char name10[] = "Buddy";
	char photograph10[] = "https://shelter/link10.com";
	Dog* d10 = new Dog();
	d10->CreateDog(breed10, name10, 10, photograph10);
	this->service.addDogService(d10);
}

void UI::run()
{
	this->defaultshelter();
	int option;
	string input;
	cout << "Welcome to 'Keep calm and adopt a pet!' shelter!\n";
	do {
		try {
			this->choosemode(input);
		}
		catch (exception& e){
			cout << e.what() << "\n";
		}
	} while (input != "0" && input != "1" && input != "2");
	option = stoi(input);
	if (option == 1)
	{
		int optionadmin;
		while (true) {
			this->printMenuAdmin(optionadmin);
			switch (optionadmin) {
			case 1:
				this->addDogUI();
				break;
			case 2:
				this->deleteDogUI();
				break;
			case 3:
				this->updateDogUI();
				break;
			case 4:
				this->printDogsUI();
				break;
			case 0:
				cout << "Bye admin!\n";
				exit(0);
			}
		}
	}
	else
	{
		int optionuser;
		while (true) {
			this->printMenuUser(optionuser);
			switch (optionuser) {
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 0:
				cout << "Bye user!\n";
				exit(0);
			}
		}
	}
}

void UI::printDogsUI()
{
	int j = 0;
	j = this->service.getSizeService();
	Dog* d = this->service.getElement();

	for (int i = 0; i < j; i++)
		cout<<d[i].Representation() << "\n";	
	cout << "\n";
}

void UI::addDogUI()
{
	char breed[100];
	cout << "Enter the breed of the dog: ";
	cin >> breed;
	char name[100];
	cout << "Enter the name of the dog: ";
	cin >> name;
	int age;
	cout << "Enter the age of the dog: ";
	cin >> age;
	char photograph[100];
	cout << "Enter the link to the photograph: ";
	cin >> photograph;
	Dog* d = new Dog();
	d->CreateDog(breed, name, age, photograph);
	this->service.addDogService(d);
}

void UI::choosemode(string& input)
{
	cout << "Please choose how you want to login:\n";
	cout << "1. admin\n";
	cout << "2. user\n";
	cout << "0. Exit\n";
	cout << "Option: ";
	cin >> input;
	int choice = stoi(input);
	if (choice == 1)
		cout << "Welcome admin\n";
	else if (choice == 2)
		cout << "Welcome user\n";
	else if (choice == 0)
		exit(0);
	else
		throw invalid_argument("Invalid option!");
}

void UI::deleteDogUI()
{
	char name[100];
	cout << "Enter the name of the dog: ";
	cin >> name;
	char breed[100];
	cout << "Enter the breed of the dog: ";
	cin >> breed;
	int age;
	cout << "Enter the age of the dog: ";
	cin >> age;
	Dog* d = this->service.searchDogService(name, breed, age);
	this->service.removeDogService(d);
}

void UI::updateDogUI()
{
	int option;
	cout << "List of possible updates: \n";
	cout << "1. Update breed\n";
	cout << "2. Update name\n";
	cout << "3. Update age\n";
	cout << "What do you want to update?: ";
	cin >> option;
	cout << "Enter the name of the dog: ";
	char name[100];
	cin >> name;
	cout << "Enter the breed of the dog: ";
	char breed[100];
	cin >> breed;
	int age;
	cout << "Enter the age of the dog: ";
	cin >> age;
	Dog* d = this->service.searchDogService(name, breed, age);
	switch (option)
	{
	case 1:
		char new_breed[20];
		cout << "Enter the new breed: ";
		cin >> new_breed;
		this->service.updateBreedService(d, new_breed);
		break;
	case 2:
		char new_name[20];
		cout << "Enter the new name: ";
		cin >> new_name;
		this->service.updateNameService(d, new_name);
		break;
	case 3:
		int new_age;
		cout << "Enter the new age: ";
		cin >> new_age;
		this->service.updateAgeService(d, new_age);
		break;
	}
}