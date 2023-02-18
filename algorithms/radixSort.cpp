#include <iostream>

void countingSort(int arr[], int n, int64_t exp) {
    int64_t *b = new int64_t[n];
    int64_t *c = new int64_t[256];
    for (int64_t i = 0; i < 256; ++i) {
        c[i] = 0;
    }
    for (int64_t i = 0; i < n; ++i) {
        c[(arr[i] / exp) % 256]++;
    }
    for (int64_t i = 1; i < 256; ++i) {
        c[i] += c[i - 1];
    }
    for (int64_t i = n - 1; i >= 0; --i) {
        b[c[(arr[i] / exp) % 256] - 1] = arr[i];
        c[(arr[i] / exp) % 256]--;
    }
    for (int64_t i = 0; i < n; i++) {
        arr[i] = b[i];
    }
    delete[] b;
    delete[] c;
}

void radixSort(int *arr, int n, int max) {
    int64_t exp = 1;
    while (max / exp > 0) {
        countingSort(arr, n, exp);
        exp *= 256;
    }
}