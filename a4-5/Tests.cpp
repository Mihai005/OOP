#include "Tests.h"

void testDomain()
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

void testDynamicVector()
{
	DynamicVector <Dog>v = DynamicVector<Dog>();
	DynamicVector<Dog> vector1;
	assert(vector1.getSize() == 0);
	DynamicVector<Dog> vector2(5);
	assert(vector2.getCapacity() == 5);
	Dog dog1 = Dog();
	dog1.CreateDog("Labrador", "Buddy", 2, "https://example.com");
	vector2.addElement(dog1);
	assert(vector2.getSize() == 1);
	Dog dog2 = Dog();
	dog2.CreateDog("Golden Retriever", "Max", 3, "https://example101.com");
	vector2.addElement(dog2);
	assert(vector2.getSize() == 2);
	Dog* retrievedDog = vector2.getElement(0);
	vector2.deleteElement(retrievedDog);
	assert(vector2.getSize() == 1);
	for (int i = 0; i < 10; i++)
	{
		Dog d = Dog();
		d.CreateDog("Breed", "Name", 10, "https://testdog.com");
		vector2.addElement(d);
	}
	assert(vector2.getCapacity() == 20);
	cout << "DynamicVector tests passed!" << "\n";
}

void testRepository()
{
	Repository r = Repository();

	// Test adding dogs
	Dog d1;
	d1.CreateDog("Husky", "Rex", 5, "www.photograph.com");
	Dog d2;
	d2.CreateDog("Labrador", "Max", 3, "www.photograph.com");
	Dog d3;
	d3.CreateDog("Pug", "Rex", 2, "www.photograph.com");

	r.addDogRepo(d1);
	r.addDogRepo(d2);
	r.addDogRepo(d3);

	assert(r.getSizeRepo() == 3);

	// Test removing a dog
	r.removeDogRepo(&d2);
	assert(r.getSizeRepo() == 2);

	// Test updating a dog's breed, name, and age
	r.updateDogBreed(&d1, "Golden Retriever");
	r.updateDogName(&d1, "Buddy");
	r.updateDogAge(&d1, 6);

	Dog* updatedDog = r.getElementRepo(0);

	assert(updatedDog->getBreed() == "Husky");
	assert(updatedDog->getName() == "Rex");
	assert(updatedDog->getAge() == 5);

	// Test adding a dog to the adoption list
	r.addAdoptionListRepo(&d3);
	assert(r.getSizeAdoptionList() == 1);

	Dog* elements = r.getElementsAdoption();
	Dog* elem = r.getElements();

	cout << "Repository tests passed!" << "\n";
}

void testService()
{
	Service s = Service();

	// Test adding a dog
	Dog d;
	d.CreateDog("Husky", "Rex", 5, "www.photograph.com");
	s.addDogService(d);
	assert(s.getSizeService() == 1);

	// Test removing a dog
	s.removeDogService(&d);
	assert(s.getSizeService() == 0);
	assert(s.checkAlreadyExists(d) == 1);

	string breed = "Golden Retriever";
	string name = "Buddy";
	int age = 6;
	string link = "https://www.photograph.com";
	assert(s.checkInput(breed, name, age, link) == 1);

	Dog adoptedDog;
	adoptedDog.CreateDog("Golden Retriever", "Buddy", 6, "https://www.photograph.com");
	s.addAdoptionListService(&adoptedDog);
	assert(s.getSizeServiceAdoption() == 1);
	s.addDogService(d);
	s.searchDogService("Rex", "Husky", 5);
	Dog* adoptedDogs = s.getElementAdoption();
	assert(adoptedDogs[0].getBreed() == "Golden Retriever");
	Dog* dogs = s.getElement();
	assert(dogs[0].getBreed() == "Husky");
	s.updateNameService(&d, "Max");
	s.updateBreedService(&d, "Labrador");
	s.updateAgeService(&d, 3);
	s.removeDogService(&d);
	try {
				s.searchDogService("Rex", "Husky", 20);
	}
	catch (exception) {
	}
	try {
		s.checkInput("", "Name", 0, "https://testdog.com");
	}
	catch (exception) {
	}
	try {
		s.checkInput("Breed", "", 0, "https://testdog.com");
	}
	catch (exception) {
	}
	try {
		s.checkInput("Breed", "Name", -1, "https://testdog.com");
	}
	catch (exception) {
	}
	try {
		s.checkInput("Breed", "Name", 0, "");
	}
	catch (exception) {

	}
	Dog d29;
	d29.CreateDog("Bison", "Lea", 3, "https://agoodlink.ro");
	s.addDogService(d29);
	try {
				s.checkAlreadyExists(d29);
	}
	catch (exception) {

	}
	cout << "Service tests passed!" << endl;
}

void testAll()
{
	testDomain();
	testDynamicVector();
	testRepository();
	testService();
}

