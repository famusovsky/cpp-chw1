#include <iostream>

int binarySearch(int *arr, int key, int left, int right, int64_t &count) {
  while (left <= right) {
    int mid = left + (right - left) / 2;
    count++;
    if (key < arr[mid]) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
    count += 2;
  }
  count++;
  return left;
}

void binaryInsertionSortOP(int *arr, int n, int k, int64_t &count) {
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    count++;
    int j = i - 1;
    count += 2;
    int pos = binarySearch(arr, key, 0, j, count);
    count++;
    while (j >= pos) {
      arr[j + 1] = arr[j];
      j--;
      count += 2;
    }
    arr[j + 1] = key;
    count++;
  }
}