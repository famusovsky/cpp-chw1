#include <iostream>

// Функция сортировки Шелла (последовательность Циура), с подсчетом операций
void shellSortCrOP(int *arr, int n, int k, int64_t &count) {
  int gap = 1;
  while (gap < n / 3) {
    gap = 3 * gap + 1;
    count += 1;
  }
  while (gap >= 1) {
    for (int i = gap; i < n; i++) {
      for (int j = i; j >= gap && arr[j] < arr[j - gap]; j -= gap) {
        std::swap(arr[j], arr[j - gap]);
        count += 3;
        count += 2;
      }
    }
    gap /= 3;
    count += 1;
  }
}
