#include "ui.h"
#include "service.h"
#include "domain.h"
#include "DynamicArray.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printMenuUI()
{
    printf("List of options:\n");
    printf("a. Add medicine\n");
    printf("b. Delete medicine\n");
    printf("c. Search medicine by string matching\n");
    printf("d. Update medicine name\n");
    printf("e. Update medicine concentration\n");
    printf("f. Update medicine quantity\n");
    printf("g. Update medicine price\n");
    printf("h. Search medicine by supply\n");
    printf("i. Undo\n");
    printf("j. Redo\n");
    printf("k. Exit\n");
}

void printMedicine(Medicine* medicine)
{
    printf("Name: %s\n", medicine->name);
    printf("Concentration: %d\n", medicine->concentration);
    printf("Quantity: %d\n", medicine->quantity);
    printf("Price: %d\n", medicine->price);
}

void addMedicineUI(Medicine* medicine, DynamicArray* medicineList)
{
    char name[50];
    int concentration;
    int quantity;
    int price;
    printf("Enter the name of the medicine: ");
    scanf("%s", name);
    printf("Enter the concentration of the medicine: ");
    scanf("%d", &concentration);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &quantity);
    printf("Enter the price of the medicine: ");
    scanf("%d", &price);
    int value;
    value = addMedicine(medicineList, name, concentration, quantity, price);
    if (value == 1)
        printf("Medicine added successfully!\n");
    else if (value == 2)
        printf("Medicine quantity updated successfully\n");
    else
        printf("Something went wrong!\n");
}

void deleteMedicineUI(Medicine* medicine, DynamicArray* medicineList)
{
    char name[50];
    int concentration;
    printf("Enter the name of the medicine: ");
    scanf("%s", name);
    printf("Enter the concentration of the medicine: ");
    scanf("%d", &concentration);
    int value;
    value = deleteMedicine(medicineList, name, concentration);
    if (value == 1)
        printf("Medicine deleted successfully!\n");
    else
        printf("Medicine not found!\n");
}

void searchMedicineUI(Medicine* medicine, DynamicArray* medicineList)
{
    clear_input_buffer();
    char name[50];
    printf("Enter the name of the medicine: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    DynamicArray* searchList = createDynamicArray(10);
    searchMedicineByName(medicineList, name, searchList);
    if (searchList->size == 0)
    {
        printf("No medicine found!\n");
    }
    sortMedicineListByName(searchList);
    for (int i = 0; i < searchList->size; i++)
	{
		printMedicine(&searchList->elems[i]);
	}
    destroyDynamicArray(searchList);
}

void updateMedicineNameUI(DynamicArray* medicineList)
{
    char name[50];
    printf("Enter the name of the medicine: ");
    scanf("%s", name);
    int concentration;
    printf("Enter the concentration of the medicine: ");
    scanf("%d", &concentration);
    char new_name[50];
    printf("Enter the new name of the medicine: ");
    scanf("%s", new_name);
    int value = updateMedicineName(name, concentration, new_name, medicineList);
    if (value == 1)
        printf("Medicine name updated successfully!\n");
    else
        printf("Medicine not found!\n");
}

void updateMedicineConcentrationUI(DynamicArray* medicineList)
{
    char name[50];
    printf("Enter the name of the medicine: ");
	scanf("%s", name);
	int concentration;
	printf("Enter the concentration of the medicine: ");
	scanf("%d", &concentration);
	int new_concentration;
	printf("Enter the new concentration of the medicine: ");
	scanf("%d", &new_concentration);
	int value = updateMedicineConcentration(name, concentration, new_concentration, medicineList);
	if (value == 1)
		printf("Medicine concentration updated successfully!\n");
	else
		printf("Medicine not found!\n");
}

void updateMedicineQuantityUI(DynamicArray* medicineList)
{
    char name[50];
    printf("Enter the name of the medicine: ");
	scanf("%s", name);
	int concentration;
	printf("Enter the concentration of the medicine: ");
	scanf("%d", &concentration);
	int new_quantity;
	printf("Enter the new quantity of the medicine: ");
	scanf("%d", &new_quantity);
	int value = updateMedicineQuantity(name, concentration, new_quantity, medicineList);
	if (value == 1)
		printf("Medicine quantity updated successfully!\n");
	else
		printf("Medicine not found!\n");
}

void updateMedicinePriceUI(DynamicArray* medicineList)
{
    char name[50];
    printf("Enter the name of the medicine: ");
    scanf("%s", name);
    int concentration;
    printf("Enter the concentration of the medicine: ");
    scanf("%d", &concentration);
    int new_price;
    printf("Enter the new price of the medicine: ");
    scanf("%d", &new_price);
    int value = updateMedicinePrice(name, concentration, new_price, medicineList);
    if (value == 1)
		printf("Medicine price updated successfully!\n");
	else
		printf("Medicine not found!\n");
}

void MedicineShortSupplyUI(DynamicArray* medicineList)
{
    int supply = 0;
    printf("Enter supply: ");
    scanf("%d", &supply);
    DynamicArray* supplyList = createDynamicArray(10);
    searchMedicineBySupply(medicineList, supply, supplyList);
    if (supplyList->size == 0)
	{
		printf("No medicine found!\n");
	}
    for (int i = 0; i < supplyList->size; i++)
	{
		printMedicine(&supplyList->elems[i]);
	}
	destroyDynamicArray(supplyList);
}

void UndoUI(DynamicArray* medicineList)
{
    int value;
    value = Undo(medicineList);
    if (value == 2)
        printf("No more undo's!\n");
    else
        printf("Undo successfull");
}
