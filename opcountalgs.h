//
// Created by Алексей Степанов on 2023-02-15.
//

#ifndef CHW1__OPCOUNTALGS_H_
#define CHW1__OPCOUNTALGS_H_
#include <iostream>

// Функции сортировок с подсчетом операций

// Сортировка пузырьком с подсчетом операций
void bubbleSortOP(int *arr, int n, int k, int64_t &count);
// Сортировка пузырьком с 1м условием Айверсона с подсчетом операций
void bubbleSortI1OP(int *arr, int n, int k, int64_t &count);
// Сортировка пузырьком со 2м условием Айверсона с подсчетом операций
void bubbleSortI2OP(int *arr, int n, int k, int64_t &count);
// Сортировка вставками с подсчетом операций
void insertionSortOP(int *arr, int n, int k, int64_t &count);
// Сортировка вставками с бинарным поиском с подсчетом операций
void binaryInsertionSortOP(int *arr, int n, int k, int64_t &count);
// Сортировка слиянием с подсчетом операций
void mergeSortOP(int *arr, int n, int k, int64_t &count);
// Сортировка пирамидальная с подсчетом операций
void pyramideSortOP(int *arr, int n, int k, int64_t &count);
// Быстрая сортировка с подсчетом операций
void quickSortOP(int *arr, int n, int k, int64_t &count);
// Стабильная сортировка подсчетом с подсчетом операций
void stableCountingSortOP(int *arr, int n, int k, int64_t &count);
// Цифровая сортировка по основанию 256 с подсчетом операций
void radixSortOP(int *arr, int n, int k, int64_t &count);
// Сортировка выбором с подсчетом операций
void selectionSortOP(int *arr, int n, int k, int64_t &count);
// Сортировка Шелла с последовательностью Циура с подсчетом операций
void shellSortCrOP(int *arr, int n, int k, int64_t &count);
// Сортировка Шелла с последовательностью Шелла с подсчетом операций
void shellSortShOP(int *arr, int n, int k, int64_t &count);

#endif//CHW1__OPCOUNTALGS_H_
