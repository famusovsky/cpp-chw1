#include <iostream>

// Функция сортировки вставками, с подсчетом операций
void insertionSortOP(int *begin, int n, int k, int64_t &count) {
  int *end = begin + n;
  if (begin != end) {
    count += 2;
    for (auto i = begin + 1; i != end; ++i) {
      int cur = *i;
      auto j = i - 1;
      count += 2;
      while (j - begin >= 0 && *j > cur) {
        *(j + 1) = *j;
        --j;
        count += 3;
      }
      *(j + 1) = cur;
      count += 1;
    }
  }
}
