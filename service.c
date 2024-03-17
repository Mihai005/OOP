#include "service.h"
#include "ui.h"
#include "Domain.h"
#include "DynamicArray.h"
#include "UndoList.h"
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
	strcpy(MedicineList->elems[MedicineList->size].name, name);
	MedicineList->elems[MedicineList->size].concentration = concentration;
	MedicineList->elems[MedicineList->size].quantity = quantity;
	MedicineList->elems[MedicineList->size].price = price;
	MedicineList->size++;
	return 1;
}

int addMedicineUndo(DynamicArray* MedicineList, char* name, int concentration, int quantity, int price, UndoList* undoList)
{
	{
		int value = 0;
		value = check_medicine(name, concentration, quantity, price);
		if (value == 3)
			return 3;
		if (MedicineList->size == MedicineList->capacity)
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
		addUndoList(undoList, MedicineList);
		MedicineList->elems[MedicineList->size].name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
		strcpy(MedicineList->elems[MedicineList->size].name, name);
		MedicineList->elems[MedicineList->size].concentration = concentration;
		MedicineList->elems[MedicineList->size].quantity = quantity;
		MedicineList->elems[MedicineList->size].price = price;
		MedicineList->size++;
		return 1;
	}
}

int deleteMedicine(DynamicArray* MedicineList, char* name, int concentration, UndoList* undoList)
{
	for (int i = 0; i < MedicineList->size; i++)
	{
		if (strcmp(MedicineList->elems[i].name, name) == 0 && MedicineList->elems[i].concentration == concentration)
		{
			addUndoList(undoList, MedicineList);
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

int updateMedicineName(char* name, int concentration, char* new_name, DynamicArray* MedicineList, UndoList* undoList)
{
	for (int i = 0; i < MedicineList->size; i++)
	{
		if (strcmp(MedicineList->elems[i].name, name) == 0 && MedicineList->elems[i].concentration== concentration)
		{
			addUndoList(undoList, MedicineList);
			MedicineList->elems[i].name = (char*)realloc(MedicineList->elems[i].name, sizeof(char) * (strlen(new_name) + 1));
			strcpy(MedicineList->elems[i].name, new_name);
			return 1;
		}
	}
	return 0;
}


int updateMedicineConcentration(char* name, int concentration, int new_concentration, DynamicArray* MedicineList, UndoList* undoList)
{
	for (int i = 0; i < MedicineList->size; i++)
	{
		if (strcmp(MedicineList->elems[i].name, name) == 0 && MedicineList->elems[i].concentration == concentration)
		{
			addUndoList(undoList, MedicineList);
			MedicineList->elems[i].concentration = new_concentration;
			return 1;
		}
	}
	return 0;
}

int updateMedicineQuantity(char* name, int concentration, int new_quantity, DynamicArray* MedicineList, UndoList* undoList)
{
	for (int i = 0; i < MedicineList->size; i++)
	{
		if (strcmp(MedicineList->elems[i].name, name) == 0 && MedicineList->elems[i].concentration == concentration)
		{
			addUndoList(undoList, MedicineList);
			MedicineList->elems[i].quantity = new_quantity;
			return 1;
		}
	}
	return 0;
}

int updateMedicinePrice(char* name, int concentration, int new_price, DynamicArray* MedicineList, UndoList* undoList)
{
	for (int i = 0; i < MedicineList->size; i++)
	{
		if (strcmp(MedicineList->elems[i].name, name) == 0 && MedicineList->elems[i].concentration == concentration)
		{
			addUndoList(undoList, MedicineList);
			MedicineList->elems[i].price = new_price;
			return 1;
		}
	}
	return 0;
}

void searchMedicine(DynamicArray* MedicineList, char* name, DynamicArray* searchList)
{
	for (int i = 0; i < MedicineList->size; i++)
	{
		if (strstr(MedicineList->elems[i].name, name) != NULL)
		{
			addMedicine(searchList, MedicineList->elems[i].name, MedicineList->elems[i].concentration, MedicineList->elems[i].quantity, MedicineList->elems[i].price);
		}
	}
}

int Undo(DynamicArray* MedicineList, UndoList* undoList)
{
	if (undoList->size == 0)
		return 1;
	MedicineList->elems = (Medicine*)realloc(MedicineList->elems, sizeof(Medicine) * undoList->array[undoList->size-1].capacity);
	if (MedicineList->elems == NULL)
		return 1;
	MedicineList->size = undoList->array[undoList->size-1].size;
	MedicineList->capacity = undoList->array[undoList->size-1].capacity;

	for (int i = 0; i < MedicineList->size; i++)
	{
		MedicineList->elems[i].concentration= undoList->array[undoList->size-1].elems[i].concentration;
		MedicineList->elems[i].price = undoList->array[undoList->size - 1].elems[i].price;
		MedicineList->elems[i].name = undoList->array[undoList->size - 1].elems[i].name;
		MedicineList->elems[i].quantity = undoList->array[undoList->size - 1].elems[i].quantity;
	}
	undoList->size--;
	return 0;
}

int addUndoList(UndoList* list, DynamicArray* arr)
{
	if (list->size == list->capacity)
		resizeUndo(list);
	list->array[list->size].capacity= arr->capacity;
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
	list->size++;
	for (int i = 0; i < list->size; i++)
	for (int j=0;j<list->array[i].size;j++)
	{
		printf("%s ", list->array[i].elems[j].name);
		printf("%d ", list->array[i].elems[j].concentration);
		printf("%d ", list->array[i].elems[j].quantity);
		printf("%d ", list->array[i].elems[j].price);
		printf("\n");
	}
	
	return 0;
}

void defaultpharmacy(DynamicArray* pharmacy, UndoList* undoList)
{
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

int Redo(DynamicArray* medicineList, UndoList* redoList)
{
	
}
