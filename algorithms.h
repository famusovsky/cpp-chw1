// АиСД-2, 2023, задание 5
// Степанов А, БПИ212

#ifndef CHW1__ALGORITHMS_H_
#define CHW1__ALGORITHMS_H_

// Функции сортировок

// Сортировка пузырьком
void bubbleSort(int *arr, int n, int k);
// Сортировка пузырьком с 1м условием Айверсона
void bubbleSortI1(int *arr, int n, int k);
// Сортировка пузырьком со 2м условием Айверсона
void bubbleSortI2(int *arr, int n, int k);
// Сортировка вставками
void insertionSort(int *arr, int n, int k);
// Сортировка вставками с бинарным поиском
void binaryInsertionSort(int *arr, int n, int k);
// Сортировка слиянием
void mergeSort(int *arr, int n, int k);
// Сортировка пирамидальная
void pyramideSort(int *arr, int n, int k);
// Быстрая сортировка
void quickSort(int *arr, int n, int k);
// Стабильная сортировка подсчетом
void stableCountingSort(int *arr, int n, int k);
// Цифровая сортировка по основанию 256
void radixSort(int *arr, int n, int k);
// Сортировка выбором
void selectionSort(int *arr, int n, int k);
// Сортировка Шелла с последовательностью Циура
void shellSortCr(int *arr, int n, int k);
// Сортировка Шелла с последовательностью Шелла
void shellSortSh(int *arr, int n, int k);

#endif//CHW1__ALGORITHMS_H_
