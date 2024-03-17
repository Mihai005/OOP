#pragma once
#include "DynamicArray.h"
#include "Domain.h"
#include "UndoList.h"

void printMenuUI();
void printMedicine(Medicine* medicine);
void deleteMedicineUI(DynamicArray* MedicineList, UndoList* undoList);
void addMedicineUI(DynamicArray* MedicineList, UndoList* undoList);
void searchMedicineUI(DynamicArray* medicineList);
void updateMedicineNameUI(DynamicArray* medicineList, UndoList* undoList);
void updateMedicineConcentrationUI(DynamicArray* medicineList, UndoList* undoList);
void updateMedicineQuantityUI(DynamicArray* medicineList, UndoList* undoList);
void updateMedicinePriceUI(DynamicArray* medicineLIst, UndoList* undoList);
void UndoUI(DynamicArray* medicineList, UndoList* undoList, UndoList* redoList);
void RedoUI(DynamicArray* medicineList, UndoList* redoList, UndoList* undoList);