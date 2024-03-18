#include "service.h"
#include "ui.h"
#include "Domain.h"
#include "DynamicArray.h"
#include "UndoList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void printMenu()
{
	/*
	   Function that prints the menu
	*/
	printMenuUI();
}

int check_medicine(char* name, int concentration, int quantity, int price)
{
	/*
	   Function that checks if the medicine is valid
	   Input: name - pointer to the name of the medicine
			  concentration - integer, the concentration of the medicine
			  quantity - integer, the quantity of the medicine
			  price - integer, the price of the medicine
	*/
	if (quantity < 0)
		return 3;
	if (concentration < 0 || concentration > 100)
		return 3;
	if (strlen(name) == 0)
		return 3;
	return 0;
}

int addMedicine(DynamicArray* MedicineList, char* name, int concentration, int quantity, int price)
{
	/*
	   Function that adds a medicine to the dynamic array
	   Input: MedicineList - pointer to the dynamic array
			  name - pointer to the name of the medicine
			  concentration - integer, the concentration of the medicine
			  quantity - integer, the quantity of the medicine
			  price - integer, the price of the medicine
	*/
	int value = 0;
	value = check_medicine(name, concentration, quantity, price);
	if (value == 3)
		return 3;
	if (getSize(MedicineList) == getCapacity(MedicineList))
	{
		resize(MedicineList);
	}
	for (int i = 0; i < getSize(MedicineList); i++)
	{
		if (strcmp(get_name(getElement(MedicineList, i)), name) == 0 && get_concentration(getElement(MedicineList, i)) == concentration)
		{
			set_quantity(getElement(MedicineList, i), get_quantity(getElement(MedicineList, i)) + quantity);
			return 2;
		}
	}
	setElement(MedicineList, getSize(MedicineList), name, concentration, quantity, price);
	setSize(MedicineList, getSize(MedicineList) + 1);
	return 1;
}

int addMedicineUndo(DynamicArray* MedicineList, char* name, int concentration, int quantity, int price, UndoList* undoList)
{
	 /*
	    Function that adds a medicine to the dynamic array and adds the operation to the undo list
		Input: MedicineList - pointer to the dynamic array
			   name - pointer to the name of the medicine
			   concentration - integer, the concentration of the medicine
			   quantity - integer, the quantity of the medicine
			   price - integer, the price of the medicine
			   undoList - pointer to the undo list
	 */
	int value = 0;
	value = check_medicine(name, concentration, quantity, price);
	if (value == 3)
		return 3;
	if (getSize(MedicineList) == getCapacity(MedicineList))
	{
		resize(MedicineList);
	}
	for (int i = 0; i < getSize(MedicineList); i++)
	{
	   if (strcmp(get_name(getElement(MedicineList, i)), name) == 0 && get_concentration(getElement(MedicineList, i)) == concentration)
		{
			set_quantity(getElement(MedicineList, i), get_quantity(getElement(MedicineList, i)) + quantity);
			return 2;
		}
	}
	addUndoList(undoList, MedicineList);
	setElement(MedicineList, getSize(MedicineList), name, concentration, quantity, price);
	setSize(MedicineList, getSize(MedicineList) + 1);
	return 1;
	
}

int deleteMedicine(DynamicArray* MedicineList, char* name, int concentration, UndoList* undoList)
{
	/*
	   Function that deletes a medicine from the dynamic array
	   Input: MedicineList - pointer to the dynamic array
			  name - pointer to the name of the medicine
			  concentration - integer, the concentration of the medicine
			  undoList - pointer to the undo list
	   Output: 0 - if the medicine was not found
			   1 - if the medicine was deleted successfully
	*/
	for (int i = 0; i < getSize(MedicineList); i++)
	{
		if (strcmp(get_name(getElement(MedicineList, i)), name) == 0 && get_concentration(getElement(MedicineList, i)) == concentration)
		{
			addUndoList(undoList, MedicineList);
			for (int j = i; j < getSize(MedicineList) - 1; j++)
			{
				setElement(MedicineList, j, get_name(getElement(MedicineList, j + 1)), get_concentration(getElement(MedicineList, j + 1)), get_quantity(getElement(MedicineList, j + 1)),
					get_price(getElement(MedicineList, j + 1)));
			}
			setSize(MedicineList, getSize(MedicineList) - 1);
			return 1;
		}
	}
	return 0;
}

void clear_input_buffer()
{
	/*
	   Function that clears the input buffer
	*/
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

int updateMedicineName(char* name, int concentration, char* new_name, DynamicArray* MedicineList, UndoList* undoList)
{
	/*
	   Function that updates the name of a medicine
	   Input: name - pointer to the name of the medicine
			  concentration - integer, the concentration of the medicine
			  new_name - pointer to the new name of the medicine
			  MedicineList - pointer to the dynamic array
			  undoList - pointer to the undo list
	*/
	for (int i = 0; i < getSize(MedicineList); i++)
	{
		if (strcmp(get_name(getElement(MedicineList, i)), name) == 0 && get_concentration(getElement(MedicineList, i)) == concentration)
		{
			addUndoList(undoList, MedicineList);
			set_name(getElement(MedicineList, i), new_name);
			return 1;
		}
	}
	return 0;
}


int updateMedicineConcentration(char* name, int concentration, int new_concentration, DynamicArray* MedicineList, UndoList* undoList)
{
	/*
	   Function that updates the concentration of a medicine
	   Input: name - pointer to the name of the medicine
			  concentration - integer, the concentration of the medicine
			  new_concentration - integer, the new concentration of the medicine
			  MedicineList - pointer to the dynamic array
			  undoList - pointer to the undo list
	*/
	for (int i = 0; i < getSize(MedicineList); i++)
	{
		if (strcmp(get_name(getElement(MedicineList, i)), name) == 0 && get_concentration(getElement(MedicineList, i)) == concentration)
		{
			addUndoList(undoList, MedicineList);
			set_concentration(getElement(MedicineList, i), new_concentration);
			return 1;
		}
	}
	return 0;
}

int updateMedicineQuantity(char* name, int concentration, int new_quantity, DynamicArray* MedicineList, UndoList* undoList)
{
	/*
	   Function that updates the quantity of a medicine
	   Input: name - pointer to the name of the medicine
			  concentration - integer, the concentration of the medicine
			  new_quantity - integer, the new quantity of the medicine
			  MedicineList - pointer to the dynamic array
			  undoList - pointer to the undo list
	*/
	for (int i = 0; i < MedicineList->size; i++)
	{
		if (strcmp(get_name(getElement(MedicineList, i)), name) == 0 && get_concentration(getElement(MedicineList, i)) == concentration)
		{
			addUndoList(undoList, MedicineList);
			set_quantity(getElement(MedicineList, i), new_quantity);
			return 1;
		}
	}
	return 0;
}

int updateMedicinePrice(char* name, int concentration, int new_price, DynamicArray* MedicineList, UndoList* undoList)
{
	/*
	   Function that updates the price of a medicine
	   Input: name - pointer to the name of the medicine
			  concentration - integer, the concentration of the medicine
			  new_price - integer, the new price of the medicine
			  MedicineList - pointer to the dynamic array
			  undoList - pointer to the undo list
	*/
	for (int i = 0; i < MedicineList->size; i++)
	{
		if (strcmp(get_name(getElement(MedicineList, i)), name) == 0 && get_concentration(getElement(MedicineList, i)) == concentration)
		{
			addUndoList(undoList, MedicineList);
			set_price(getElement(MedicineList, i), new_price);
			return 1;
		}
	}
	return 0;
}

void searchMedicine(DynamicArray* MedicineList, char* name, DynamicArray* searchList)
{
	/*
	   Function that searches for a medicine in the dynamic array
	   Input: MedicineList - pointer to the dynamic array
			  name - pointer to the name of the medicine
			  searchList - pointer to the dynamic array
	   Output: searchList - pointer to the dynamic array
	*/
	for (int i = 0; i < getSize(MedicineList); i++)
	{
		if (strstr(get_name(getElement(MedicineList, i)), name) != NULL)
		{
			addMedicine(searchList, get_name(getElement(MedicineList, i)), 
			get_concentration(getElement(MedicineList, i)), get_quantity(getElement(MedicineList, i)), get_price(getElement(MedicineList, i)));
		}
	}
	for (int i = 0; i < getSize(searchList) - 1; i++)
		for (int j = i + 1; j < getSize(searchList); j++)
			if (strcmp(get_name(getElement(searchList, i)), (get_name(getElement(searchList, j)))) > 0)
			{
				Medicine* temp = (Medicine*)malloc(sizeof(Medicine));
				temp->name = (char*)malloc(sizeof(char) * (strlen(get_name(getElement(searchList, i))) + 1));
				strcpy(temp->name, get_name(getElement(searchList, i)));
				temp->concentration = get_concentration(getElement(searchList, i));
				temp->quantity = get_quantity(getElement(searchList, i));
				temp->price = get_price(getElement(searchList, i));
				set_name(getElement(searchList, i), get_name(getElement(searchList, j)));
				set_concentration(getElement(searchList, i), get_concentration(getElement(searchList, j)));
				set_quantity(getElement(searchList, i), get_quantity(getElement(searchList, j)));
				set_price(getElement(searchList, i), get_price(getElement(searchList, j)));
				set_name(getElement(searchList, j), temp->name);
				set_concentration(getElement(searchList, j), temp->concentration);
				set_quantity(getElement(searchList, j), temp->quantity);
				set_price(getElement(searchList, j), temp->price);
				free(temp->name);
				free(temp);
			}
}

int Undo(DynamicArray* MedicineList, UndoList* undoList, UndoList* redoList)
{
	/*
	   Function that performs the undo operation
	   Input: MedicineList - pointer to the dynamic array
			  undoList - pointer to the undo list
			  redoList - pointer to the redo list
			  Output: 0 - if the undo operation was successful
			   1 - if the undo list is empty
	*/
	if (get_size_undo(undoList) == 0)
		return 1;
	addUndoList(redoList, MedicineList);
    MedicineList->elems = (Medicine*)realloc(MedicineList->elems, sizeof(Medicine) * undoList->array[undoList->size - 1].capacity);
	if (MedicineList->elems == NULL)
		return 1;
      setSize(MedicineList, getSize(get_undo_array(undoList, get_size_undo(undoList) - 1)));
	  setCapacity(MedicineList, getCapacity(get_undo_array(undoList, get_size_undo(undoList) - 1)));

	for (int i = 0; i < MedicineList->size; i++)
	{
		set_concentration(getElement(MedicineList, i), undoList->array[undoList->size - 1].elems[i].concentration);
		set_price(getElement(MedicineList, i), undoList->array[undoList->size - 1].elems[i].price);
		set_name(getElement(MedicineList, i), undoList->array[undoList->size - 1].elems[i].name);
		set_quantity(getElement(MedicineList, i), undoList->array[undoList->size - 1].elems[i].quantity);
	}
	decreaseUndoListSize(undoList, get_size_undo(undoList) - 1);
	//set_size_undo(undoList, get_size_undo(undoList) - 1);
	return 0;
}

int addUndoList(UndoList* list, DynamicArray* arr)
{
	/*
	   Function that adds a new dynamic array to the undo list
	   Input: list - pointer to the undo list
			  arr - pointer to the dynamic array
			  Output: 0 - if the dynamic array was added successfully
			   1 - if the dynamic array could not be added
	*/
	if (get_size_undo(list) == get_capacity_undo(list))
		resizeUndo(list);
	list->array[list->size].capacity = arr->capacity;
	list->array[list->size].size = arr->size;
	list->array[list->size].elems = (Medicine*)malloc(sizeof(Medicine) * arr->capacity);
	if (list->array[list->size].elems == NULL)
		return 1;
	for (int i = 0; i < arr->size; i++)
	{
		list->array[list->size].elems[i].name = (char*)malloc(sizeof(char) * (strlen(arr->elems[i].name) + 1));
		strcpy(list->array[list->size].elems[i].name, arr->elems[i].name);
		list->array[list->size].elems[i].concentration = arr->elems[i].concentration;
		list->array[list->size].elems[i].quantity = arr->elems[i].quantity;
		list->array[list->size].elems[i].price = arr->elems[i].price;
	}
	set_size_undo(list, get_size_undo(list) + 1);
	return 0;
}

void defaultpharmacy(DynamicArray* pharmacy, UndoList* undoList)
{
	/*
	  Function that adds the default medicines to the pharmacy
	  Input: pharmacy - pointer to the dynamic array
			 undoList - pointer to the undo list
	*/
	addMedicine(pharmacy, "Ibuprofen", 5, 200, 5);
	addMedicine(pharmacy, "Paracetamol", 10, 100, 10);
	addMedicine(pharmacy, "Nurofen", 20, 50, 15);
	addMedicine(pharmacy, "Aspirin", 30, 30, 20);
	addMedicine(pharmacy, "VitaminC", 40, 20, 25);
	addMedicine(pharmacy, "VitaminD", 50, 10, 30);
	addMedicine(pharmacy, "VitaminE", 60, 5, 35);
	addMedicine(pharmacy, "VitaminB", 70, 3, 40);
	addMedicine(pharmacy, "VitaminA", 80, 2, 45);
	addMedicine(pharmacy, "VitaminK", 90, 1, 50);
}


int Redo(UndoList* redoList, UndoList* undoList, DynamicArray* MedicineList)
{
	/*
	  Function that performs the redo operation
	  Input: redoList - pointer to the redo list
			 undoList - pointer to the undo list
			 MedicineList - pointer to the dynamic array
			 Output: 0 - if the redo operation was successful
			  1 - if the redo list is empty
	 
	*/
	if (redoList->size == 0)
		return 1;
	addUndoList(undoList, MedicineList);
	MedicineList->elems = (Medicine*)realloc(MedicineList->elems, sizeof(Medicine) * redoList->array[redoList->size - 1].capacity);
	if (MedicineList->elems == NULL)
		return 1;
	MedicineList->size = redoList->array[redoList->size - 1].size;
	MedicineList->capacity = redoList->array[redoList->size - 1].capacity;

	for (int i = 0; i < getSize(MedicineList); i++)
	{
		set_concentration(getElement(MedicineList, i), redoList->array[redoList->size - 1].elems[i].concentration);
		set_price(getElement(MedicineList, i), redoList->array[redoList->size - 1].elems[i].price);
		set_name(getElement(MedicineList, i), redoList->array[redoList->size - 1].elems[i].name);
		set_quantity(getElement(MedicineList, i), redoList->array[redoList->size - 1].elems[i].quantity);
	}
	decreaseUndoListSize(redoList, get_size_undo(redoList) - 1);
	//set_size_undo(redoList, get_size_undo(redoList) - 1);
	return 0;
}

void testservice()
{
	/* 
	   Function that tests the service
	*/
	DynamicArray* pharmacy;
	pharmacy = createDynamicArray(10);
	UndoList* undoList;
	undoList = createUndoList(10);
	UndoList* redoList;
	redoList = createUndoList(10);
	defaultpharmacy(pharmacy, undoList);
	assert(addMedicine(pharmacy, "Fent", 190, 200, 5) == 3);
	assert(addMedicine(pharmacy, "Ibuprofen", 5, 200, 5) == 2);
	assert(deleteMedicine(pharmacy, "Ibuprofen", 5, undoList) == 1);
	assert(deleteMedicine(pharmacy, "Ibuprofen", 5, undoList) == 0);
	assert(updateMedicineName("VitaminC", 40, "Oxi", pharmacy, undoList) == 1);
	assert(updateMedicineName("Ibuprofen", 5, "Paracetamol", pharmacy, undoList) == 0);
	assert(updateMedicineConcentration("Paracetamol", 10, 30, pharmacy, undoList) == 1);
	assert(updateMedicineConcentration("Paracetamol", 5, 10, pharmacy, undoList) == 0);
	assert(updateMedicineQuantity("Paracetamol", 30, 100, pharmacy, undoList) == 1);
	assert(updateMedicineQuantity("Paracetamol", 10, 100, pharmacy, undoList) == 0);
	assert(updateMedicinePrice("VitaminK", 90, 10, pharmacy, undoList) == 1);
	assert(updateMedicinePrice("VitaminK", 87, 40, pharmacy, undoList) == 0);
	assert(Redo(redoList, undoList, pharmacy) == 1);
	assert(Undo(pharmacy, undoList, redoList) == 0);
	assert(Redo(redoList, undoList, pharmacy) == 0);
	assert(Redo(redoList, undoList, pharmacy) == 1);
	destroyDynamicArray(pharmacy);
	destroyUndoList(undoList);
	destroyUndoList(redoList);
}