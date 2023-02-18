#include <iostream>

void stableCountingSortOP(int *a, int n, int k, int64_t &count) {
  int *c = new int[k + 1];
  int *b = new int[n];
  for (int i = 0; i <= k; ++i) {
    c[i] = 0;
    count++;
  }
  for (int i = 0; i <= n - 1; ++i) {
    c[a[i]] = c[a[i]] + 1;
    count += 2;
  }
  for (int i = 1; i <= k; ++i) {
    c[i] = c[i] + c[i - 1];
    count += 2;
  }
  for (int i = n - 1; i >= 0; --i) {
    c[a[i]] = c[a[i]] - 1;
    b[c[a[i]]] = a[i];
    count += 4;
  }
  for (int i = 0; i <= n - 1; ++i) {
    a[i] = b[i];
    count++;
  }
  delete[] c;
  delete[] b;
  count += 2;
}
