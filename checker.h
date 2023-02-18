//
// Created by Алексей Степанов on 2023-02-15.
//

#ifndef CHW1__CHECKER_H_
#define CHW1__CHECKER_H_
#include <iostream>
#include <string>
#include <vector>

std::vector<std::vector<int>> timer(void (*func)(int *, int, int), std::string path);

std::vector<int64_t> counter(void (*func)(int *, int, int, int64_t &), std::string path);

#endif//CHW1__CHECKER_H_
