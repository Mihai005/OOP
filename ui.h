#pragma once
#include "DynamicArray.h"
#include "Domain.h"

void printMenuUI();
void printMedicine(Medicine* medicine);
void deleteMedicineUI(Medicine* medicine, DynamicArray* MedicineList);
void addMedicineUI(Medicine* medicine, DynamicArray* MedicineList);
void searchMedicineUI(Medicine* medicine, DynamicArray* medicineList);
void updateMedicineNameUI(DynamicArray* medicineList);
void updateMedicineConcentrationUI(DynamicArray* medicineList);
void updateMedicineQuantityUI(DynamicArray* medicineList);
void updateMedicinePriceUI(DynamicArray* medicineLIst);
void MedicineShortSupplyUI(DynamicArray* medicineList);
void UndoUI(DynamicArray* medicineList);