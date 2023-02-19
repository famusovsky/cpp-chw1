//
// Created by Алексей Степанов on 2023-02-15.
//

#ifndef CHW1__CHECKER_H_
#define CHW1__CHECKER_H_
#include <iostream>
#include <string>
#include <vector>

/// Метод, измеряющий время работы данных алгоритмов сортировки на данных массивах
/// \param func - функция, время работы которой нужно измерить
/// \param path - путь к файлу, в котором хранится массив
/// \return вектор, в котором хранятся вектора по 10 различных измерений времени работы алгоритма для каждого размера массива
std::vector<std::vector<int>> timer(void (*func)(int *, int, int), std::string path);

/// Метод, измеряющий количество операций, которые выполняются алгоритмами сортировки на данных массивах
/// \param func - функция, которая сортирует массив
/// \param path - путь к файлу, из которого считывается массив
/// \return вектор, в котором хранится количество операций для каждого размера массива
std::vector<int64_t> counter(void (*func)(int *, int, int, int64_t &), std::string path);

#endif//CHW1__CHECKER_H_
