#pragma once
#include "Domain.h"
#include "DynamicArray.h"
#include "UndoList.h"

void printMenu();
int deleteMedicine(DynamicArray* MedicineList, char* name, int concentration, UndoList* undoList);
int addMedicine(DynamicArray* MedicineList, char* name, int concentration, int quantity, int price);
int addMedicineUndo(DynamicArray* MedicineList, char* name, int concentration, int quantity, int price, UndoList* undoList);
void clear_input_buffer();
int updateMedicineName(char* name, int concentration, char* new_name, DynamicArray* MedicineList, UndoList* undoList);
int updateMedicineConcentration(char* name, int concentration, int new_concentration, DynamicArray* MedicineList, UndoList* undoList);
int updateMedicineQuantity(char* name, int concentration, int new_quantity, DynamicArray* MedicineList, UndoList* undoList);
int updateMedicinePrice(char* name, int concentration, int new_price, DynamicArray* MedicineList, UndoList* undoList);
void searchMedicine(DynamicArray* MedicineList, char* name, DynamicArray* searchList);
int Undo(DynamicArray* MedicineList, UndoList* undoList, UndoList* redoList);
int addUndoList(UndoList* undoList, DynamicArray* medicineList);
void defaultpharmacy(DynamicArray* MedicineList, UndoList* undoList);
int Redo(UndoList* redoList, UndoList* undoList, DynamicArray* MedicineList);