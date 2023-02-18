#include "algorithms.h"
#include "checker.h"
#include "opcountalgs.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

void runnerTime(std::vector<void (*)(int *, int, int)> functions, std::vector<std::string> names,
                std::vector<std::string> pathes, std::fstream &file) {
  for (int i = 0; i < static_cast<int>(functions.size()); i++) {
    for (int j = 0; j < static_cast<int>(pathes.size()); j++) {
      file << names[i] << " - " << pathes[j];
      void (*func)(int *, int, int) = functions[i];
      std::vector<std::vector<int>> times = timer(func, pathes[j]);
      for (int z = 0; z < static_cast<int>(times.size()); ++z) {
        double average = 0;
        for (int k = 0; k < static_cast<int>(times[z].size()); ++k) {
          average += times[z][k];
        }
        average /= static_cast<double>(times[z].size());
        file << ";" << average;
      }
      file << std::endl;
    }
  }
  file << std::endl;
}

void runnerOperations(std::vector<void (*)(int *, int, int, int64_t &)> functions,
                      std::vector<std::string> names, std::vector<std::string> pathes,
                      std::fstream &file) {
  for (int i = 0; i < static_cast<int>(functions.size()); i++) {
    for (int j = 0; j < static_cast<int>(pathes.size()); j++) {
      file << names[i] << " - " << pathes[j];
      void (*func)(int *, int, int, int64_t &) = functions[i];
      std::vector<int64_t> counts = counter(func, pathes[j]);
      for (int z = 0; z < static_cast<int>(counts.size()); ++z) {
        file << ";" << counts[z];
      }
      file << std::endl;
    }
  }
  file << std::endl;
}

int main() {
  std::vector<void (*)(int *, int, int)> normal_functions = {
      &binaryInsertionSort, &bubbleSort, &bubbleSortI1, &bubbleSortI2,
      &insertionSort, &mergeSort, &pyramideSort, &quickSort,
      &radixSort, &selectionSort, &shellSortCr, &shellSortSh, &stableCountingSort};
  std::vector<void (*)(int *, int, int, int64_t &)> opcount_functions = {
      &binaryInsertionSortOP, &bubbleSortOP, &bubbleSortI1OP, &bubbleSortI2OP,
      &insertionSortOP, &mergeSortOP, &pyramideSortOP, &quickSortOP,
      &radixSortOP, &selectionSortOP, &shellSortCrOP, &shellSortShOP, &stableCountingSortOP};
  std::vector<std::string> names = {
      "binaryInsertionSort", "bubbleSort", "bubbleSortI1", "bubbleSortI2",
      "insertionSort", "mergeSort", "pyramideSort", "quickSort",
      "radixSort", "selectionSort", "shellSortCr", "shellSortSh", "stableCountingSort"};
  std::vector<std::string> pathes300 = {
      "../arrays/300-0-5.txt", "../arrays/300-0-4000.txt",
      "../arrays/300-almost-sorted.txt", "../arrays/300-reversed.txt"};
  std::vector<std::string> pathes4100 = {
      "../arrays/4100-0-5.txt", "../arrays/4100-0-4000.txt",
      "../arrays/4100-almost-sorted.txt", "../arrays/4100-reversed.txt"};
  std::fstream file;
  file.open("results.csv", std::ios::out);
  file.precision(2);
  file << std::fixed;
  file << "Time in nanoseconds" << std::endl
       << "Array size";
  for (int i = 50; i <= 300; i += 50) {
    file << ";" << i;
  }
  file << std::endl;
  runnerTime(normal_functions, names, pathes300, file);
  file << "Array size";
  for (int i = 100; i <= 4100; i += 100) {
    file << ";" << i;
  }
  file << std::endl;
  runnerTime(normal_functions, names, pathes4100, file);
  file << "Elemental operations" << std::endl
       << "Array size";
  for (int i = 50; i <= 300; i += 50) {
    file << ";" << i;
  }
  file << std::endl;
  runnerOperations(opcount_functions, names, pathes300, file);
  file << "Array size";
  for (int i = 100; i <= 4100; i += 100) {
    file << ";" << i;
  }
  file << std::endl;
  runnerOperations(opcount_functions, names, pathes4100, file);
  file.close();
  return 0;
}
