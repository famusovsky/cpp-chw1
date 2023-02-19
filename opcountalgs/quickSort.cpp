#include <iostream>

// Рекурсивная функция быстрой сортировки, с подсчетом операций
void quickSortRecursion(int *arr, int left, int right, int64_t &count) {
  int i = left, j = right;
  int pivot = arr[(left + right) / 2];
  count += 3;
  while (i <= j) {
    while (arr[i] < pivot) {
      i++;
      count += 2;
    }
    while (arr[j] > pivot) {
      j--;
      count += 2;
    }
    if (i <= j) {
      std::swap(arr[i], arr[j]);
      i++;
      j--;
      count += 4;
    }
  }
  if (left < j) {
    quickSortRecursion(arr, left, j, count);
    count += 4;
  }
  if (i < right) {
    quickSortRecursion(arr, i, right, count);
    count += 4;
  }
}

// Метод вызывающий рекурсивную функцию быстрой сортировки, с подсчетом операций
void quickSortOP(int *arr, int n, int k, int64_t &count) {
  quickSortRecursion(arr, 0, n - 1, count);
  count += 4;
}