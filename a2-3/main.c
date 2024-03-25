#include "ui.h"
#include "Domain.h"
#include "DynamicArray.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crtdbg.h>


int main()
{
    char option;
    Medicine medicine;
    DynamicArray *pharmacy;
    pharmacy = createDynamicArray(10);
    do {
        printMenuUI();
        printf("Choose option: ");
        scanf(" %c", &option);
        switch (option)
        {
        case 'a':
            addMedicineUI(&medicine, pharmacy);
            break;
        case 'b':
            deleteMedicineUI(&medicine, pharmacy);
            break;
        case 'c':
            searchMedicineUI(&medicine, pharmacy);
            break;
        case 'd':
            updateMedicineNameUI(pharmacy);
            break;
        case 'e':
            updateMedicineConcentrationUI(pharmacy);
            break;
        case 'f':
            updateMedicineQuantityUI(pharmacy);
            break;
        case 'g':
            updateMedicinePriceUI(pharmacy);
            break;
        case 'h':
            MedicineShortSupplyUI(pharmacy);
            break;
        case 'i':
            UndoUI(pharmacy);
            break;
        case 'j':
            RedoUI(pharmacy);
            break;
        case 'k':
            destroyDynamicArray(pharmacy);
            _CrtDumpMemoryLeaks();
            exit(0);
        default:
            printf("Invalid option\n");
        }
    } while (1);

	return 0;
}

/*
   TO DO:
   -> Undo / Redo functionality
   -> Error handling
   -> Tests
   -> Bonus week 4?
*/
