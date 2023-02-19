#include <iostream>

// Функция сортировки пузырьком со 2м условием Айверсона, с подсчетом операций
void bubbleSortI2OP(int *arr, int n, int k, int64_t &count) {
  int newn = n;
  count += 1;
  while (newn > 0) {
    int last_swap = 0;
    count += 2;
    for (int i = 1; i < newn; i++) {
      count += 3;
      if (arr[i - 1] > arr[i]) {
        int temp = arr[i - 1];
        arr[i] = arr[i - 1];
        arr[i - 1] = temp;
        last_swap = i;
        count += 3;
      }
      count += 2;
    }
    newn = last_swap;
    count += 1;
  }
}
