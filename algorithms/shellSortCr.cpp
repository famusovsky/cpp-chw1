#include <iostream>

// Функция сортировки Шелла (последовательность Циура)
void shellSortCr(int *arr, int n, int k) {
  int gap = 1;
  while (gap < n / 3) {
    gap = 3 * gap + 1;
  }
  while (gap >= 1) {
    for (int i = gap; i < n; i++) {
      for (int j = i; j >= gap && arr[j] < arr[j - gap]; j -= gap) {
        std::swap(arr[j], arr[j - gap]);
      }
    }
    gap /= 3;
  }
}