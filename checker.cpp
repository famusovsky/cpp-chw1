#include <chrono>
#include <fstream>
#include <string>
#include <vector>

struct Data {
  int *arr;
  int n;
  int k;

  ~Data() {
    delete[] arr;
  }
};

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
  //
  for (int n = step; n <= data.n; n += step) {
    std::vector<int> time(10);
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < data.n; j++) {
        arr[j] = data.arr[j];
      }
      auto start = std::chrono::high_resolution_clock::now();
      func(arr, n, data.k);
      auto elapsed = std::chrono::high_resolution_clock::now() - start;
      long long nanoseconds = isSorted(arr, n)
          ? std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count()
          : -1;
      time[i] = nanoseconds;
    }
    times[(n - step) / step] = time;
  }
  /*
  for (int i = 0; i < 10; i++) {
    std::vector<int> time(data.n / step);
    for (int n = step; n <= data.n; n += step) {
      for (int j = 0; j < data.n; j++) {
        arr[j] = data.arr[j];
      }
      auto start = std::chrono::high_resolution_clock::now();
      func(arr, n, data.k);
      auto elapsed = std::chrono::high_resolution_clock::now() - start;
      long long nanoseconds = isSorted(arr, n)
          ? std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count()
          : -1;
      time[(n - step) / step] = nanoseconds;
    }
    times.push_back(time);
  }*/
  //
  delete[] arr;
  return times;
}