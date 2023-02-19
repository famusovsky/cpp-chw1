#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Cтруктура, которая хранит массив, его размер и максимальный элемент
struct Data {
  int *arr;
  int n;
  int k;

  ~Data() {
    delete[] arr;
  }
};

// Функция, которая считывает из файла в объект Data массив, а также его размер и максимальный элемент
Data getData(std::string path) {
  int n, k = -1;
  std::fstream file;
  file.open(path, std::ios::in);
  file >> n;
  int *arr = new int[n];
  for (int i = 0; i < n; i++) {
    file >> arr[i];
    if (arr[i] > k) {
      k = arr[i];
    }
  }
  file.close();
  return {arr, n, k};
}

// Функция, которая проверяет, отсортирован ли массив
bool isSorted(int *arr, int n) {
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] > arr[i + 1]) {
      return false;
    }
  }
  return true;
}

std::vector<std::vector<int>> timer(void (*func)(int *, int, int), std::string path) {
  Data data = getData(path);
  int *arr = new int[data.n];
  int step = data.n == 300 ? 50 : 100;
  std::vector<std::vector<int>> times(data.n / step, std::vector<int>(10));
  for (int n = step; n <= data.n; n += step) {
    std::vector<int> time(10);
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < data.n; j++) {
        arr[j] = data.arr[j];
      }
      auto start = std::chrono::high_resolution_clock::now();
      func(arr, n, data.k);
      auto elapsed = std::chrono::high_resolution_clock::now() - start;
      int64_t nanoseconds = isSorted(arr, n)
          ? std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count()
          : -1;
      time[i] = nanoseconds;
    }
    times[(n - step) / step] = time;
  }
  delete[] arr;
  return times;
}

std::vector<int64_t> counter(void (*func)(int *, int, int, int64_t &), std::string path) {
  Data data = getData(path);
  int *arr = new int[data.n];
  int step = data.n == 300 ? 50 : 100;
  std::vector<int64_t> counts(data.n / step);
  for (int n = step; n <= data.n; n += step) {
    int64_t count = 0;
    for (int j = 0; j < data.n; j++) {
      arr[j] = data.arr[j];
    }
    func(arr, n, data.k, count);
    counts[(n - step) / step] = count;
  }
  delete[] arr;
  return counts;
}