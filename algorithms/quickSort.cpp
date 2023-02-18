#include <iostream>

void quickSortRecursion(int *arr, int left, int right) {
  int i = left, j = right;
  int pivot = arr[(left + right) / 2];
  while (i <= j) {
    while (arr[i] < pivot) {
      i++;
    }
    while (arr[j] > pivot) {
      j--;
    }
    if (i <= j) {
      std::swap(arr[i], arr[j]);
      i++;
      j--;
    }
  }
  if (left < j) {
    quickSortRecursion(arr, left, j);
  }
  if (i < right) {
    quickSortRecursion(arr, i, right);
  }
}

void quickSort(int *arr, int n, int k) {
  quickSortRecursion(arr, 0, n - 1);
}