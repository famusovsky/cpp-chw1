#include <iostream>

// Функция сортировки Шелла (последовательность Шелла), с подсчетом операций
void shellSortShOP(int *arr, int n, int k, int64_t &count) {
  int gap = n / 2;
  while (gap > 0) {
    for (int i = gap; i < n; i++) {
      int temp = arr[i];
      int j = i;
      while (j >= gap && arr[j - gap] > temp) {
        arr[j] = arr[j - gap];
        j -= gap;
        count += 3;
      }
      arr[j] = temp;
      count += 2;
    }
    gap /= 2;
    count += 2;
  }
}
