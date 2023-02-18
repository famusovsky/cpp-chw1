#include <iostream>

void bubbleSortI1OP(int *arr, int n, int k, int64_t &count) {
  bool swapped;
  for (int i = 0; i < n - 1; i++) {
    swapped = false;
    count += 3;
    for (int j = 0; j < n - i - 1; j++) {
      count += 2;
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        swapped = true;
        count += 3;
      }
      count += 2;
    }
    count += 1;
    if (!swapped) {
      break;
    }
  }
}
