#include "ui.h"
#include "Domain.h"
#include "DynamicArray.h"
#include "UndoList.h"
#include "service.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crtdbg.h>


int main()
{
    char option;
    DynamicArray *pharmacy;
    pharmacy = createDynamicArray(10);
    UndoList* undoList;
    undoList = createUndoList(10);
    UndoList* redoList;
    redoList = createUndoList(10);
    defaultpharmacy(pharmacy, undoList);
    do {
        printMenuUI();
        printf("Choose option: ");
        scanf(" %c", &option);
        switch (option)
        {
        case 'a':
            addMedicineUI(pharmacy, undoList);
            break;
        case 'b':
            deleteMedicineUI(pharmacy, undoList);
            break;
        case 'c':
            searchMedicineUI(pharmacy);
            break;
        case 'd':
            updateMedicineNameUI(pharmacy, undoList);
            break;
        case 'e':
            updateMedicineConcentrationUI(pharmacy, undoList);
            break;
        case 'f':
            updateMedicineQuantityUI(pharmacy, undoList);
            break;
        case 'g':
            updateMedicinePriceUI(pharmacy, undoList);
            break;
        case 'h':
            UndoUI(pharmacy, undoList);
            break;
        case 'i':
            RedoUI(pharmacy, redoList);
            break;
        case 'j':
            destroyDynamicArray(pharmacy);
            destroyUndoList(undoList);
            _CrtDumpMemoryLeaks();
            exit(0);
        default:
            printf("Invalid option\n");
        }
    } while (1);

	return 0;
}