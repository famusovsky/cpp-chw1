#include <climits>
#include <iostream>

// Функция слияния двух отсортированных массивов, с подсчетом операций
void merge(int *begin, int *middle, int *end, int64_t &count) {
  int n_1 = middle - begin, n_2 = end - middle;
  int *left = new int[n_1 + 1];
  int *right = new int[n_2 + 1];
  for (int i = 0; i < n_1; ++i) {
    left[i] = *(begin + i);
    count++;
  }
  for (int i = 0; i < n_2; ++i) {
    right[i] = *(middle + i);
    count++;
  }
  left[n_1] = INT_MAX;
  right[n_2] = INT_MAX;
  int i = 0, j = 0;
  for (int *p = begin; p != end; ++p) {
    if (left[i] <= right[j]) {
      *p = left[i++];
    } else {
      *p = right[j++];
    }
    count += 4;
  }
  delete[] left;
  delete[] right;
}

// Рекурсивная функция сортировки слиянием, с подсчетом операций
void mergeSortRecursion(int *begin, int *end, int64_t &count) {
  if (end - begin > 1) {
    int *middle = begin + (end - begin) / 2;
    mergeSortRecursion(begin, middle, count);
    mergeSortRecursion(middle, end, count);
    merge(begin, middle, end, count);
    count += 3;
  }
}

// Метод вызывающий рекурсивную функцию сортировки слиянием, с подсчетом операций
void mergeSortOP(int *begin, int n, int k, int64_t &count) {
  mergeSortRecursion(begin, begin + n, count);
}
