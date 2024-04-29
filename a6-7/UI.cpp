#include "UI.h"
#include "Exceptions.h"
#include <exception>
#include <crtdbg.h>
#include <fstream>
#include <sstream>

using namespace std;

UI::UI(Service service) : service(service)
{

}

void UI::printMenuAdmin(string& optionadminstr)
{
	cout << "Choose one option:\n";
	cout << "1. Add dog.\n";
	cout << "2. Delete dog.\n";
	cout << "3. Update dog.\n";
	cout << "4. Print dogs.\n";
	cout << "0. Logout.\n";
	cout << "Option: ";
	getline(cin, optionadminstr);
	//if (optionadminstr != "0" && optionadminstr != "1" && optionadminstr != "2" && optionadminstr != "3" && optionadminstr != "4")
		//throw invalid_argument("Please enter a valid input!");
	OptionValidator::validateMenuAdmin(optionadminstr);
	cout << "\n";
}

void UI::printMenuUser(string& optionuser)
{
	cout << "Choose one option:\n";
	cout << "1. See the dogs one by one\n";
	cout << "2. See the dogs by breed and less than age\n";
	cout << "3. See the adoption list\n";
	cout << "4. See the adoption list in the system\n";
	cout << "0. Logout.\n";
	cout << "Option: ";
	getline(cin, optionuser);
	/*if (optionuser.compare("0") == 0 && optionuser.compare("1") == 0 && optionuser.compare("2") == 0 && optionuser.compare("3") == 0)
		throw invalid_argument("Please enter a valid input!");*/
	OptionValidator::validateMenuUser(optionuser);
	cout << "\n";
}

void UI::defaultshelter()
{
	if (this->service.getSizeService() != 0)
		return;
	// read from file
	string breed, name, age, photograph;
	ifstream file("Dogs.txt");
	string line;
	while (getline(file, line)) {
		string breed, name, ageStr, photograph;
		stringstream ss(line);
		getline(ss, breed, ',');
		getline(ss, name, ',');
		getline(ss, ageStr, ',');
		getline(ss, photograph);
		int age = stoi(ageStr);
		Dog d = Dog();
		d.CreateDog(breed, name, age, photograph);
		this->service.addDogService(d);
	}
	file.close();
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
		catch (exception& e) {
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
			} while (optionuser.compare("0") != 0 && optionuser.compare("1") != 0 && optionuser.compare("2") != 0 && optionuser.compare("3") != 0 && optionuser.compare("4")!= 0);
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
			case 4:
				this->seeAdoptionListUI();
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
	Dog* beginIterator = this->service.getElement();
	Dog* endIterator = beginIterator + this->service.getSizeService();
	if (beginIterator == endIterator)
		cout << "There aren't any dogs in the shelter!";
	for (Dog* ptr = beginIterator; ptr != endIterator; ++ptr)
	{
		Dog& d = *ptr;
		cout << d.Representation() << "\n";
	}
	cout << "\n";
}

void UI::addDogUI()
{
	string breed;
	cout << "Enter the breed of the dog: ";
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
			getline(cin, breed);
		}
	} while (breed.empty());
	string name;
	cout << "Enter the name of the dog: ";
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
			getline(cin, name);
		}
	} while (name.empty());
	string age;
	cout << "Enter the age of the dog: ";
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
			getline(cin, age);
		}
	} while (ok1 == false);
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
	do {
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
				getline(cin, breed);
			}
			else if (strcmp(e.what(), "Invalid name!") == 0) {
				cout << "Enter the name of the dog: ";
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
	} while (ok == false);

	Dog d = Dog();
	d.CreateDog(breed, name, ageint, photograph);
	bool exists = false;
	try {
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

	// write to file
	ofstream file("Dogs.txt");
	Dog* dogs = this->service.getElement();
	for (int i = 0; i < this->service.getSizeService(); i++)
	{
		Dog d = dogs[i];
		file << d.getBreed() << "," << d.getName() << "," << d.getAge() << "," << d.getPhotograph() << "\n";
	}
	file.close();

	cout << "The dog was added!\n";
}

void UI::choosemode(string& input)
{
	cout << "Please choose how you want to login:\n";
	cout << "1. admin\n";
	cout << "2. user\n";
	cout << "0. Exit\n";
	cout << "Option: ";
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
	getline(cin, name);
	string breed;
	cout << "Enter the breed of the dog: ";
	getline(cin, breed);
	string age;
	cout << "Enter the age of the dog: ";
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
		cout << "The dog was removed!\n";
	}

	// write to file

	ofstream file("Dogs.txt");
	Dog* dogs = this->service.getElement();
	for (int i = 0; i < this->service.getSizeService(); i++)
	{
		Dog d = dogs[i];
		file << d.getBreed() << "," << d.getName() << "," << d.getAge() << "," << d.getPhotograph() << "\n";
	}
	file.close();
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
			getline(cin, breed);
		}
	} while (breed.empty());
	string age;
	cout << "Enter the age of the dog: ";
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
					getline(cin, new_breed);
				}
			} while (new_breed.empty());
			this->service.updateBreedService(d, new_breed);
			break;
		case 2:
			cout << "Enter the new name: ";
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
					getline(cin, new_name);
				}
			} while (new_name.empty());
			this->service.updateNameService(d, new_name);
			break;
		case 3:
			cout << "Enter the new age: ";
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
					getline(cin, new_age);
				}
			} while (new_age.empty());
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
					getline(cin, new_age);
				}
			} while (ok3 == false);
			int new_ageint = stoi(new_age);
			this->service.updateAgeService(d, new_ageint);
			break;
		}
	}

	// write to file
	ofstream file("Dogs.txt");
	Dog* dogs = this->service.getElement();
	for (int i = 0; i < this->service.getSizeService(); i++)
	{
		Dog d = dogs[i];
		file << d.getBreed() << "," << d.getName() << "," << d.getAge() << "," << d.getPhotograph() << "\n";
	}
	file.close();
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
			ofstream file2("Dogs.txt");
			Dog* dogs2 = this->service.getElement();
			for (int i = 0; i < this->service.getSizeService(); i++)
			{
				Dog d = dogs2[i];
				file2 << d.getBreed() << "," << d.getName() << "," << d.getAge() << "," << d.getPhotograph() << "\n";
			}
			file2.close();
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
	cout << "Enter the age: ";
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
			getline(cin, age);
		}
	} while (ok1 == false);
	int ageint = stoi(age);
	int j = 0;
	j = this->service.getSizeService();
	Dog* d = this->service.getElement();
	if (j == 0)
		cout << "There aren't any dogs in the shelter!";
	bool found = false;
	for (int i = 0; i < j; i++)
		if (d[i].getBreed() == breed && d[i].getAge() <= ageint)
		{
			cout << d[i].Representation() << "\n";
			found = true;
		}
	if (found == false)
		cout << "There aren't any dogs with the given breed and age!\n";
}

void UI::printAdoptionListUI()
{
	Dog* beginIterator = this->service.getElementAdoption();
	Dog* endIterator = beginIterator + this->service.getSizeServiceAdoption();
	if (beginIterator == endIterator)
		cout << "There aren't any dogs in the adoption list!";
	for (Dog* ptr = beginIterator; ptr != endIterator; ++ptr)
	{
		Dog& d = *ptr;
		cout << d.Representation() << "\n";
	}
	cout << "\n";
}

int UI::choosefile()
{
   	string optionfile;
	cout << "Choose one option:\n";
	cout << "1. CSV\n";
	cout << "2. HTML\n";
	cout << "Option: ";
	getline(cin, optionfile);
	cout << "\n";
	int optionfileint = stoi(optionfile);

	// clear adoption list file
	ofstream file2("AdoptedDogs.txt");
	file2.close();

	return optionfileint;
}

void UI::seeAdoptionListUI()
{
	int optionfileint = this->choosefile();
	if (optionfileint == 1)
	{
		string filename = "AdoptedDogs.csv";
		string command = "notepad.exe " + filename;
		system(command.c_str());
	}
	else if (optionfileint == 2)
	{
		string filename = "file:///C:/Users/Mihai/Documents/GitHub/oop-a6-7-Mihai005/a6-7/AdoptedDogs.html";
		string command = "\"C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe\" " + filename;
		system(command.c_str());
	}
	else
	{
		cout << "Invalid option!\n";
		return;
	}
}

UI::~UI()
{

}