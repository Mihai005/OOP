#include "ui.h"
#include "service.h"
#include "Domain.h"
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
    printf("h. Exit\n");
}

void printMedicine(Medicine* medicine)
{
    printf("Name: %s\n", get_name(medicine));
    printf("Concentration: %d\n", get_concentration(medicine));
    printf("Quantity: %d\n", get_quantity(medicine));
    printf("Price: %d\n", get_price(medicine));
}

void addMedicineUI(DynamicArray* medicineList, UndoList* undoList)
{
    /*
       Function that reads the data for a medicine and adds it to the list
       Input: medicineList - pointer to the list of medicines
			  undoList - pointer to the list of undo operations
       Output: the medicine is added to the list or the quantity of the medicine is updated or an error message is displayed
    */
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
    value = addMedicineUndo(medicineList, name, concentration, quantity, price, undoList);
    if (value == 1)
    {
        printf("Medicine added successfully!\n");
    }
    else if (value == 2)
        printf("Medicine quantity updated successfully\n");
    else
        printf("Something went wrong!\n");
}

void deleteMedicineUI(DynamicArray* medicineList, UndoList* undoList)
{
    /*
       Function that reads the data for a medicine and deletes it from the list
       Input: medicineList - pointer to the list of medicines
       undoList - pointer to the list of undo operations
       Output: the medicine is deleted from the list or an error message is displayed
    */
    char name[50];
    int concentration;
    printf("Enter the name of the medicine: ");
    scanf("%s", name);
    printf("Enter the concentration of the medicine: ");
    scanf("%d", &concentration);
    int value;
    value = deleteMedicine(medicineList, name, concentration, undoList);
    if (value == 1)
        printf("Medicine deleted successfully!\n");
    else
        printf("Medicine not found!\n");
}

void searchMedicineUI(DynamicArray* medicineList)
{
    /*
       Function that reads the name of a medicine or a partial string and searches for all the matches in the list
       Input: medicineList - pointer to the list of medicines
       Output: the medicin(e/s) is/are found and displayed or an error message is displayed
    */
    clear_input_buffer();
    char name[50];
    printf("Enter the name of the medicine: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    DynamicArray* searchList = createDynamicArray(10);
    searchMedicine(medicineList, name, searchList);
    for (int i = 0; i < getSize(searchList); i++)
    {
        printMedicine(getElement(searchList, i));
    }
    destroyDynamicArray(searchList);
}

void updateMedicineNameUI(DynamicArray* medicineList, UndoList* undoList)
{
    /*
       Function that reads the data for a medicine and updates its name
       Input: medicineList - pointer to the list of medicines
       undoList - pointer to the list of undo operations
       Output: the name of the medicine is updated or an error message is displayed
    */
    char name[50];
    printf("Enter the name of the medicine: ");
    scanf("%s", name);
    int concentration;
    printf("Enter the concentration of the medicine: ");
    scanf("%d", &concentration);
    char new_name[50];
    printf("Enter the new name of the medicine: ");
    scanf("%s", new_name);
    int value = updateMedicineName(name, concentration, new_name, medicineList, undoList);
    if (value == 1)
        printf("Medicine name updated successfully!\n");
    else
        printf("Medicine not found!\n");
}

void updateMedicineConcentrationUI(DynamicArray* medicineList, UndoList* undoList)
{
    /*
       Function that reads the data for a medicine and updates its concentration
       Input: medicineList - pointer to the list of medicines
       undoList - pointer to the list of undo operations
       Output: the concentration of the medicine is updated or an error message is displayed
    */
    char name[50];
    printf("Enter the name of the medicine: ");
    scanf("%s", name);
    int concentration;
    printf("Enter the concentration of the medicine: ");
    scanf("%d", &concentration);
    int new_concentration;
    printf("Enter the new concentration of the medicine: ");
    scanf("%d", &new_concentration);
    int value = updateMedicineConcentration(name, concentration, new_concentration, medicineList, undoList);
    if (value == 1)
        printf("Medicine concentration updated successfully!\n");
    else
        printf("Medicine not found!\n");
}

void updateMedicineQuantityUI(DynamicArray* medicineList, UndoList* undoList)
{
    /*
       Function that reads the data for a medicine and updates its quantity
       Input: medicineList - pointer to the list of medicines
       undoList - pointer to the list of undo operations
       Output: the quantity of the medicine is updated or an error message is displayed
    */
    char name[50];
    printf("Enter the name of the medicine: ");
    scanf("%s", name);
    int concentration;
    printf("Enter the concentration of the medicine: ");
    scanf("%d", &concentration);
    int new_quantity;
    printf("Enter the new quantity of the medicine: ");
    scanf("%d", &new_quantity);
    int value = updateMedicineQuantity(name, concentration, new_quantity, medicineList, undoList);
    if (value == 1)
        printf("Medicine quantity updated successfully!\n");
    else
        printf("Medicine not found!\n");
}

void updateMedicinePriceUI(DynamicArray* medicineList, UndoList* undoList)
{
    /*
	   Function that reads the data for a medicine and updates its price
	   Input: medicineList - pointer to the list of medicines
	   undoList - pointer to the list of undo operations
	   Output: the price of the medicine is updated or an error message is displayed
	*/
    char name[50];
    printf("Enter the name of the medicine: ");
    scanf("%s", name);
    int concentration;
    printf("Enter the concentration of the medicine: ");
    scanf("%d", &concentration);
    int new_price;
    printf("Enter the new price of the medicine: ");
    scanf("%d", &new_price);
    int value = updateMedicinePrice(name, concentration, new_price, medicineList, undoList);
    if (value == 1)
        printf("Medicine price updated successfully!\n");
    else
        printf("Medicine not found!\n");
}

void UndoUI(DynamicArray* medicineList, UndoList* undoList, UndoList* redoList)
{
    /*
	   Function that undoes the last operation
	   Input: medicineList - pointer to the list of medicines
	   undoList - pointer to the list of undo operations
	   redoList - pointer to the list of redo operations
	   Output: the last operation is undone or an error message is displayed
	*/
    int value = Undo(medicineList, undoList, redoList);
    if (value == 0)
        printf("Undo successful!\n");
    else
        printf("Nothing to undo!\n");
}

void RedoUI(DynamicArray* medicineList, UndoList* redoList, UndoList* undoList)
{
    /*
      Function that redoes the last operation
      Input: medicineList - pointer to the list of medicines
      redoList - pointer to the list of redo operations
      undoList - pointer to the list of undo operations
      Output: the last operation is redone or an error message is displayed
    */
    int value = Redo(redoList, undoList, medicineList);
    if (value == 0)
        printf("Redo successful!\n");
    else
        printf("Nothing to redo!\n");
}
