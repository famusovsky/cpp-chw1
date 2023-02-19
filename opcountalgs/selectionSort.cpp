#include <iostream>

// Функция сортировки выбором, с подсчетом операций
void selectionSortOP(int *arr, int n, int k, int64_t &count) {
  int i, j, min_idx;
  for (i = 0; i < n - 1; i++) {
    min_idx = i;
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
        count += 1;
      }
      count += 2;
    }
    int temp = arr[i];
    arr[i] = arr[min_idx];
    arr[min_idx] = temp;
    count += 3;
  }
}
