// АиСД-2, 2023, задание 5
// Степанов А, БПИ212

#include "algorithms.h"
#include "checker.h"
#include "opcountalgs.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

// Метод, который запускает данные алгоритмы и записывает время их работы в данный файл
void runTimeToFile(std::vector<void (*)(int *, int, int)> functions, std::vector<std::string> names,
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
  file.close();
}

// Метод, который запускает данные алгоритмы и записывает их количество элементарных операций в данный файл
void runOperationsToFile(std::vector<void (*)(int *, int, int, int64_t &)> functions,
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
  file.close();
}

// Метод, который создает файл по данному пути
std::fstream createFile(std::string path) {
  std::fstream file;
  file.open(path, std::ios::out);
  file.precision(2);
  file << std::fixed;
  return file;
}

// Метод, который записывает данные размеры массивов в данный файл
void writeArraySizeToFile(int step, int size, std::fstream &file) {
  file << "Array size";
  for (int i = step; i <= size; i += step) {
    file << ";" << i;
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

  file = createFile("../results/time300.csv");
  writeArraySizeToFile(50, 300, file);
  runTimeToFile(normal_functions, names, pathes300, file);

  file = createFile("../results/time4100.csv");
  writeArraySizeToFile(100, 4100, file);
  runTimeToFile(normal_functions, names, pathes4100, file);

  file = createFile("../results/opcount300.csv");
  writeArraySizeToFile(50, 300, file);
  runOperationsToFile(opcount_functions, names, pathes300, file);

  file = createFile("../results/opcount4100.csv");
  writeArraySizeToFile(100, 4100, file);
  runOperationsToFile(opcount_functions, names, pathes4100, file);

  return 0;
}
