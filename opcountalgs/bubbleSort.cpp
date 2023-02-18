#include <iostream>

void bubbleSortOP(int *arr, int n, int k, int64_t &count) {
  for (int i = 0; i < n - 1; i++) {
    count += 2;
    for (int j = 0; j < n - i - 1; j++) {
      count += 2;
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        count += 3;
      }
      count += 2;
    }
  }
}
