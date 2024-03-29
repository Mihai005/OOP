#include "UI.h"
#include <iostream>
#include <exception>
#include <crtdbg.h>

using namespace std;

void UI::printMenuAdmin(string& optionadminstr)
{
	cout << "Choose one option:\n";
	cout << "1. Add dog.\n";
	cout << "2. Delete dog.\n";
	cout << "3. Update dog.\n";
	cout << "4. Print dogs.\n";
	cout << "0. Logout.\n";
	cout << "Option: ";
	//cin >> optionadminstr;
	getline(cin, optionadminstr);
	if (optionadminstr != "0" && optionadminstr != "1" && optionadminstr != "2" && optionadminstr != "3" && optionadminstr != "4")
		throw invalid_argument("Please enter a valid input!");
	cout << "\n";
}

void UI::printMenuUser(string &optionuser)
{
	cout << "Choose one option:\n";
	cout << "1. See the dogs one by one\n";
	cout << "2. See the dogs by breed and less than age\n";
	cout << "3. See the adoption list\n";
	cout << "0. Logout.\n";
	cout << "Option: ";
	//cin >> optionuser;
	getline(cin, optionuser);
	if (optionuser.compare("0") == 0 && optionuser.compare("1") == 0 && optionuser.compare("2") == 0 && optionuser.compare("3") == 0)
		throw invalid_argument("Please enter a valid input!");
	cout << "\n";
}

void UI::defaultshelter()
{
	if (this->service.getSizeService() != 0)
		return;
	string breed= "Husky";
	string name = "Rex";
	string photograph = "https://shelter/link1.com";
	Dog d1 = Dog();
	d1.CreateDog(breed, name, 1, photograph);
	this->service.addDogService(d1);
	string breed2 = "Golden Retriever";
	string name2 = "Max";
	string photograph2 = "https://shelter/link2.com";
	Dog d2 = Dog();
	d2.CreateDog(breed2, name2, 2, photograph2);
	this->service.addDogService(d2);
	string breed3 = "Labrador";
	string name3 = "Bella";
	string photograph3 = "https://shelter/link3.com";
	Dog d3 = Dog();
	d3.CreateDog(breed3, name3, 3, photograph3);
	this->service.addDogService(d3);
	string breed4 = "Pug";
	string name4 = "Luna";
	string photograph4 = "https://shelter/link4.com";
	Dog d4 = Dog();
	d4.CreateDog(breed4, name4, 4, photograph4);
	this->service.addDogService(d4);
	string breed5 = "Beagle";
	string name5= "Charlie";
	string photograph5 = "https://shelter/link5.com";
	Dog d5 = Dog();
	d5.CreateDog(breed5, name5, 5, photograph5);
	this->service.addDogService(d5);
	string breed6 = "Poodle";
	string name6 = "Lucy";
	string photograph6 = "https://shelter/link6.com";
	Dog d6 = Dog();
	d6.CreateDog(breed6, name6, 6, photograph6);
	this->service.addDogService(d6);
	string breed7 = "Dalmatian";
	string name7 = "Daisy";
	string photograph7 = "https://shelter/link7.com";
	Dog d7 = Dog();
	d7.CreateDog(breed7, name7, 7, photograph7);
	this->service.addDogService(d7);
	string breed8 = "German Shepherd";
	string name8 = "Rocky";
	string photograph8 = "https://shelter/link8.com";
	Dog d8 = Dog();
	d8.CreateDog(breed8, name8, 8, photograph8);
	this->service.addDogService(d8);
	string breed9 = "Rottweiler";
	string name9 = "Milo";
	string photograph9 = "https://shelter/link9.com";
	Dog d9 = Dog();
	d9.CreateDog(breed9, name9, 9, photograph9);
	this->service.addDogService(d9);
	string breed10 = "Doberman";
	string name10 = "Buddy";
	string photograph10 = "https://shelter/link10.com";
	Dog d10 = Dog();
	d10.CreateDog(breed10, name10, 10, photograph10);
	this->service.addDogService(d10);
}

int UI::run()
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
		string optionadminstr;
		while (true) {
			do {
				optionadminstr = "";
				try {
					this->printMenuAdmin(optionadminstr);
				}
				catch (exception& e) {
					cout << e.what() << "\n";
				}
			} while (optionadminstr != "0" && optionadminstr != "1" && optionadminstr != "2" && optionadminstr != "3" && optionadminstr != "4");
			int optionadmin = stoi(optionadminstr);
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
				this->run();
				return 0;
			}
		}
	}
	else
	{
		string optionuser;
		while (true) {
			do {
				optionuser = "";
				try {
					this->printMenuUser(optionuser);
				}
				catch (exception& e) {
					cout << e.what() << "\n";
				}
			} while (optionuser.compare("0") != 0 && optionuser.compare("1") != 0 && optionuser.compare("2") != 0 && optionuser.compare("3") != 0);
			int optionuserint = stoi(optionuser);
			switch (optionuserint) {
			case 1:
				this->printDogsUserUI();
				break;
			case 2:
				this->printDogsByBreedUI();
				break;
			case 3:
				this->printAdoptionListUI();
				break;
			case 0:
				this->run();
				return 0;
			}
		}
	}
}

void UI::printDogsUI()
{
	int j = 0;
	j = this->service.getSizeService();
	Dog* d = this->service.getElement();
	if (j == 0)
		cout << "There aren't any dogs in the shelter!";

	for (int i = 0; i < j; i++)
		cout<<d[i].Representation() << "\n";	
	cout << "\n";
}

void UI::addDogUI()
{
	string breed;
	cout << "Enter the breed of the dog: ";
	//cin >> breed;
	getline(cin, breed);
	do {
		try {
			if (breed.empty())
				throw invalid_argument("Invalid breed!");
		}
		catch (exception& e)
		{
			cout << e.what() << "\n";
			cout << "Enter the breed of the dog: ";
			//cin >> breed;
			getline(cin, breed);
		}
	} while (breed.empty());
	string name;
	cout << "Enter the name of the dog: ";
	//cin >> name;
	getline(cin, name);
	do {
		try {
			if (name.empty())
				throw invalid_argument("Invalid name!");
		}
		catch (exception& e)
		{
			cout << e.what() << "\n";
			cout << "Enter the name of the dog: ";
			//cin >> name;
			getline(cin, name);
		}
	} while(name.empty());
	string age;
	cout << "Enter the age of the dog: ";
	//cin >> age;
	getline(cin, age);
	do {
		try {
			if (age.empty())
				throw invalid_argument("Invalid age!");
		}
		catch (exception& e)
		{
			cout << e.what() << "\n";
			cout << "Enter the age of the dog: ";
			//cin >> age;
			getline(cin, age);
		}
	} while (age.empty());
	bool ok1 = false;
	do {
		try {
			ok1 = true;
			for (int i = 0; i < age.size(); i++)
				if (isdigit(age[i]) == false)
					throw invalid_argument("Invalid type!");
		}
		catch (exception& e)
		{
			ok1 = false;
			cout << e.what() << "\n";
			cout << "Enter the age of the dog: ";
			//cin >> age;
			getline(cin, age);
		}
	}while(ok1 == false);
	int ageint = stoi(age);
	string photograph;
	cout << "Enter the link to the photograph: ";
	getline(cin, photograph);
	do {
		try {
			if (photograph.empty())
				throw invalid_argument("Invalid photograph!");
		}
		catch (exception& e)
		{
			cout << e.what() << "\n";
			cout << "Enter the link to the photograph: ";
			getline(cin, photograph);
		}
	} while (photograph.empty());
	bool ok = false;
	do{
			try {
				ok = true;
				this->service.checkInput(breed, name, ageint, photograph);
			}
			catch (exception& e)
			{
				ok = false;
				cout << e.what() << "\n";
				if (strcmp(e.what(), "Invalid breed!") == 0) {
					cout << "Enter the breed of the dog: ";
					//cin >> breed;
					getline(cin, breed);
				}
				else if (strcmp(e.what(), "Invalid name!") == 0) {
					cout << "Enter the name of the dog: ";
					//cin >> name;
					getline(cin, name);
				}
				else if (strcmp(e.what(), "Invalid age!") == 0)
				{
					bool ok2 = false;
					do {
						try {
							ok2 = true;
							for (int i = 0; i < age.size(); i++)
								if (isdigit(age[i]) == false)
									throw invalid_argument("Invalid type!");
						}
						catch (exception& e)
						{
							ok2 = false;
							cout << e.what() << "\n";
							cout << "Enter the age of the dog: ";
							//cin >> age;
							getline(cin, age);
						}
					} while (ok2 == false);
					ageint = stoi(age);
				}
				else {
					cout << "Enter the link to the photograph: ";
					getline(cin, photograph);
				}
			}
		}while (ok == false);

	Dog d = Dog();
	d.CreateDog(breed, name, ageint, photograph);
	bool exists = false;
	try{
		exists = true;
		this->service.checkAlreadyExists(d);
	}
	catch (exception& e)
	{
		exists = false;
		cout << e.what() << "\n";
	}
	if (exists == true)
	  this->service.addDogService(d);
}

void UI::choosemode(string& input)
{
	cout << "Please choose how you want to login:\n";
	cout << "1. admin\n";
	cout << "2. user\n";
	cout << "0. Exit\n";
	cout << "Option: ";
	//cin >> input;
	getline(cin, input);
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
	string name;
	cout << "Enter the name of the dog: ";
	//cin >> name;
	getline(cin, name);
	string breed;
	cout << "Enter the breed of the dog: ";
	//cin >> breed;
	getline(cin, breed);
	string age;
	cout << "Enter the age of the dog: ";
	//cin >> age;
	getline(cin, age);
	bool ok1 = false;
	do {
		try {
			ok1 = true;
			for (int i = 0; i < age.size(); i++)
				if (isdigit(age[i]) == false)
					throw invalid_argument("Invalid type!");
		}
		catch (exception& e)
		{
			ok1 = false;
			cout << e.what() << "\n";
			cout << "Enter the age of the dog: ";
			//cin >> age;
			getline(cin, age);
		}
	} while (ok1 == false);
	int ageint = stoi(age);
	bool ok = false;
	try {
		ok = true;
		this->service.searchDogService(name, breed, ageint);
	}
	catch (exception& e)
	{
		ok = false;
		cout << e.what() << "\n";
	}
	if (ok == true) {
		Dog* d = this->service.searchDogService(name, breed, ageint);
		this->service.removeDogService(d);
	}
}

void UI::updateDogUI()
{
	string option;
	cout << "List of possible updates: \n";
	cout << "1. Update breed\n";
	cout << "2. Update name\n";
	cout << "3. Update age\n";
	cout << "0. Go back\n";
	cout << "What do you want to update?: ";
	//cin >> option;
	getline(cin, option);
	if (option == "0")
		return;
	bool ok1 = false;
	do {
		try {
			ok1 = true;
			if (option.compare("1") != 0 && option.compare("2") != 0 && option.compare("3") != 0)
				throw invalid_argument("Invalid option!");
		}
		catch (exception& e)
		{
			ok1 = false;
			cout << e.what() << "\n";
			cout << "What do you want to update?: ";
			//cin >> option;
			getline(cin, option);
			if (option.compare("0") == 0)
				return;
		}
	} while (!ok1);
	int optionint = stoi(option);
	cout << "Enter the name of the dog: ";
	string name;
	//cin >> name;
	getline(cin, name);
	do {
		try {
			if (name.empty())
				throw invalid_argument("Invalid name!");
		}
		catch (exception& e)
		{
			cout << e.what() << "\n";
			cout << "Enter the name of the dog: ";
			//cin >> name;
			getline(cin, name);
		}
	} while (name.empty());
	cout << "Enter the breed of the dog: ";
	string breed;
	//cin >> breed;
	getline(cin, breed);
	do {
		try {
			if (breed.empty())
				throw invalid_argument("Invalid breed!");
		}
		catch (exception& e)
		{
			cout << e.what() << "\n";
			cout << "Enter the breed of the dog: ";
			//cin >> breed;
			getline(cin, breed);
		}
	} while (breed.empty());
	string age;
	cout << "Enter the age of the dog: ";
	//cin >> age;
	getline(cin, age);
	do {
				try {
			if (age.empty())
				throw invalid_argument("Invalid age!");
		}
		catch (exception& e)
		{
			cout << e.what() << "\n";
			cout << "Enter the age of the dog: ";
			//cin >> age;
			getline(cin, age);
		}
	} while (age.empty());
	bool ok2 = false;
	do {
		try {
			ok2 = true;
			for (int i = 0; i < age.size(); i++)
				if (isdigit(age[i]) == false)
					throw invalid_argument("Invalid type!");
		}
		catch (exception& e)
		{
			ok2 = false;
			cout << e.what() << "\n";
			cout << "Enter the age of the dog: ";
			//cin >> age;
			getline(cin, age);
		}
	} while (ok2 == false);
	int ageint = stoi(age);
	bool ok = false;
	try {
		ok = true;
		this->service.searchDogService(name, breed, ageint);
	}
	catch (exception& e)
	{
		ok = false;
		cout << e.what() << "\n";
	}
	if (ok == true) {
	string new_breed;
	string new_name;
	string new_age;
	Dog* d = this->service.searchDogService(name, breed, ageint);
	switch (optionint)
	{
	case 1:
		cout << "Enter the new breed: ";
		//cin >> new_breed;
		getline(cin, new_breed);
		do {
			try {
				if (new_breed.empty())
					throw invalid_argument("Invalid breed!");
			}
			catch (exception& e)
			{
				cout << e.what() << "\n";
				cout << "Enter the new breed: ";
				//cin >> new_breed;
				getline(cin, new_breed);
			}
		} while (new_breed.empty());
		this->service.updateBreedService(d, new_breed);
		break;
	case 2:
		cout << "Enter the new name: ";
		//cin >> new_name;
		getline(cin, new_name);
		do {
			try {
				if (new_name.empty())
					throw invalid_argument("Invalid name!");
			}
			catch (exception& e)
			{
				cout << e.what() << "\n";
				cout << "Enter the new name: ";
				//cin >> new_name;
				getline(cin, new_name);
			}
		} while (new_name.empty());
		this->service.updateNameService(d, new_name);
		break;
	case 3:
		cout << "Enter the new age: ";
		//cin >> new_age;
		getline(cin, new_age);
		do {
						try {
				if (new_age.empty())
					throw invalid_argument("Invalid age!");
			}
						catch (exception& e)
						{
							cout << e.what() << "\n";
							cout << "Enter the new age: ";
							//cin >> new_age;
							getline(cin, new_age);
						}
		} while(new_age.empty());
		bool ok3 = false;
		do {
			try {
				ok3 = true;
				for (int i = 0; i < new_age.size(); i++)
					if (isdigit(new_age[i]) == false)
						throw invalid_argument("Invalid type!");
			}
			catch (exception& e)
			{
				ok3 = false;
				cout << e.what() << "\n";
				cout << "Enter the new age: ";
				//cin >> new_age;
				getline(cin, new_age);
			}
		} while (ok3 == false);
		int new_ageint = stoi(new_age);
		this->service.updateAgeService(d, new_ageint);
		break;
	}
}
}

void UI::printDogsUserUI()
{
	int j = 0;
	j = this->service.getSizeService();
	Dog* d = this->service.getElement();
	if (j == 0)
		cout << "There aren't any dogs in the shelter!";
	int i = 0;
	while (i < j)
	{
		cout << d[i].Representation() << "\n";
		cout << "Do you want to adopt this dog? (yes/no)\n";
		cout << "0. Go back\n";
		string answer;
		//cin >> answer;
		getline(cin, answer);
		do {
			try {
				if (answer.compare("yes") != 0 && answer.compare("no") != 0 && answer.compare("0") != 0)
					throw invalid_argument("Invalid option!");
			}
			catch (exception& e)
			{
				cout << e.what() << "\n";
				cout << "Do you want to adopt this dog? (yes/no)\n";
				cout << "0. Go back\n";
				//cin >> answer;
				getline(cin, answer);
			}
		} while (answer.compare("yes") != 0 && answer.compare("no") != 0 && answer.compare("0") != 0);
		if (answer == "yes")
		{
			this->service.addAdoptionListService(&d[i]);
			this->service.removeDogService(&d[i]);
			cout << "You adopted the dog!\n";
		}
		else
			i++;
		if (answer.compare("0") == 0)
			return;
		if (i == j)
			i = 0;
	}
}

void UI::printDogsByBreedUI()
{
	string breed, age;
	cout << "Enter the breed: ";
	//cin >> breed;
	getline(cin, breed);
	if (breed.empty())
	{
		/// print all dogs
		int j = 0;
		j = this->service.getSizeService();
		Dog* d = this->service.getElement();
		if (j == 0)
			cout << "There aren't any dogs in the shelter!";
		for (int i = 0; i < j; i++)
			cout << d[i].Representation() << "\n";
		cout << "\n";
		return;
	}
	//string age;
	cout << "Enter the age: ";
	//cin >> age;
	getline(cin, age);
	do {
		try {
			if (age.empty())
				throw invalid_argument("Invalid age!");
		}
		catch (exception& e)
		{
			cout << e.what() << "\n";
			cout << "Enter the age: ";
			//cin >> age;
			getline(cin, age);
		}
	} while (age.empty());
	bool ok1 = false;
	do {
		try {
			ok1 = true;
			for (int i = 0; i < age.size(); i++)
				if (isdigit(age[i]) == false)
					throw invalid_argument("Invalid type!");
		}
		catch (exception& e)
		{
			ok1 = false;
			cout << e.what() << "\n";
			cout << "Enter the age: ";
			//cin >> age;
			getline(cin, age);
		}
	} while (ok1 == false);
	int ageint = stoi(age);
	int j = 0;
	j = this->service.getSizeService();
	Dog* d = this->service.getElement();
	if (j == 0)
		cout << "There aren't any dogs in the shelter!";
	for (int i = 0; i < j; i++)
		if (d[i].getBreed() == breed && d[i].getAge() <= ageint)
			cout << d[i].Representation() << "\n";
}

void UI::printAdoptionListUI()
{
	int j = this->service.getSizeServiceAdoption();
	Dog* d = this->service.getElementAdoption();
	if (j == 0)
		cout << "There aren't any dogs in the adoption list!\n";
	for (int i = 0; i < j; i++)
		cout << d[i].Representation() << "\n";
}

UI::~UI()
{

}
