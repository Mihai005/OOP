#include "service.h"
#include "ui.h"
#include "domain.h"
#include "DynamicArray.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printMenu()
{
	printMenuUI();
}

int check_medicine(char* name, int concentration, int quantity, int price)
{
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
	int value = 0;
	value = check_medicine(name, concentration, quantity, price);
	if (value == 3)
		return 3;
	if(MedicineList->size == MedicineList->capacity)
	{
		resize(MedicineList);
	}
	for (int i = 0; i < MedicineList->size; i++)
	{
		if (strcmp(MedicineList->elems[i].name, name) == 0 && MedicineList->elems[i].concentration == concentration)
		{
			MedicineList->elems[i].quantity += quantity;
			return 2;
		}
	}
	MedicineList->elems[MedicineList->size].name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
	if (MedicineList->elems[MedicineList->size].name != NULL)
	{
		strcpy(MedicineList->elems[MedicineList->size].name, name);
	}
	else
		return 3;
	MedicineList->elems[MedicineList->size].concentration = concentration;
	MedicineList->elems[MedicineList->size].quantity = quantity;
	MedicineList->elems[MedicineList->size].price = price;
	MedicineList->size++;
	return 1;
}

int deleteMedicine(DynamicArray* MedicineList, char* name, int concentration)
{
	for (int i = 0; i < MedicineList->size; i++)
	{
		if (strcmp(MedicineList->elems[i].name, name) == 0 && MedicineList->elems[i].concentration == concentration)
		{
			for (int j = i; j < MedicineList->size - 1; j++)
			{
				MedicineList->elems[j] = MedicineList->elems[j + 1];
			}
			MedicineList->size--;
			return 1;
		}
	}
	return 0;
}

void clear_input_buffer()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

int updateMedicineName(char* name, int concentration, char* new_name, DynamicArray* MedicineList)
{
	for (int i = 0; i < MedicineList->size; i++)
	{
		if (strcmp(MedicineList->elems[i].name, name) == 0 && MedicineList->elems[i].concentration== concentration)
		{
			strcpy(MedicineList->elems[i].name, new_name);
			return 1;
		}
	}
	return 0;
}


int updateMedicineConcentration(char* name, int concentration, int new_concentration, DynamicArray* MedicineList)
{
	for (int i = 0; i < MedicineList->size; i++)
	{
		if (strcmp(MedicineList->elems[i].name, name) == 0 && MedicineList->elems[i].concentration == concentration)
		{
			MedicineList->elems[i].concentration = new_concentration;
			return 1;
		}
	}
	return 0;
}

int updateMedicineQuantity(char* name, int concentration, int new_quantity, DynamicArray* MedicineList)
{
	for (int i = 0; i < MedicineList->size; i++)
	{
		if (strcmp(MedicineList->elems[i].name, name) == 0 && MedicineList->elems[i].concentration == concentration)
		{
			MedicineList->elems[i].quantity = new_quantity;
			return 1;
		}
	}
	return 0;
}

int updateMedicinePrice(char* name, int concentration, int new_price, DynamicArray* MedicineList)
{
	for (int i = 0; i < MedicineList->size; i++)
	{
		if (strcmp(MedicineList->elems[i].name, name) == 0 && MedicineList->elems[i].concentration == concentration)
		{
			MedicineList->elems[i].price = new_price;
			return 1;
		}
	}
	return 0;
}

void searchMedicineByName(DynamicArray* MedicineList, char* name, DynamicArray* searchList)
{
	for (int i = 0; i < MedicineList->size; i++)
	{
		if (strstr(MedicineList->elems[i].name, name) != NULL)
		{
			addMedicine(searchList, MedicineList->elems[i].name, MedicineList->elems[i].concentration, MedicineList->elems[i].quantity, MedicineList->elems[i].price);
		}
	}
}

void sortMedicineListByName(DynamicArray* searchList)
{
	Medicine aux;
	for (int i = 0; i < searchList->size - 1; i++)
		for (int j = i; j < searchList->size; j++)
			if (strcmp(searchList->elems[i].name, searchList->elems[j].name) > 0)
			{
				aux = searchList->elems[i];
				searchList->elems[i] = searchList->elems[j];
				searchList->elems[j] = aux;
			}
}

void searchMedicineBySupply(DynamicArray* MedicineList, int supply, DynamicArray* searchList)
{
	for (int i = 0; i < MedicineList->size; i++)
	{
		if (MedicineList->elems[i].quantity <= supply)
		{
			addMedicine(searchList, MedicineList->elems[i].name, MedicineList->elems[i].concentration, MedicineList->elems[i].quantity, MedicineList->elems[i].price);
		}
	}
}

int Undo(DynamicArray* MedicineList, UndoRedo* UndoList)
{
	if (UndoList->size == 0)
		return 2;
	MedicineList->size = 0;
	for (int i = 0; i < UndoList->size; i++)
	{
		addMedicine(MedicineList, UndoList->elems[i].name, UndoList->elems[i].concentration, UndoList->elems[i].quantity, UndoList->elems[i].price);
	}
	UndoList->size -= 1;
	return 1;
}