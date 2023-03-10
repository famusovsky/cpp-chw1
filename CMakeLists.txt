cmake_minimum_required(VERSION 3.24)
project(chw1)

set(CMAKE_CXX_STANDARD 17)

add_library(algotithms STATIC
    algorithms/binaryInsertionSort.cpp
    algorithms/bubbleSort.cpp
    algorithms/bubbleSortI1.cpp
    algorithms/bubbleSortI2.cpp
    algorithms/quickSort.cpp
    algorithms/insertionSort.cpp
    algorithms/mergeSort.cpp
    algorithms/pyramideSort.cpp
    algorithms/radixSort.cpp
    algorithms/selectionSort.cpp
    algorithms/shellSortCr.cpp
    algorithms/shellSortSh.cpp
    algorithms/stableCountingSort.cpp)

add_library(opcountalgs STATIC
    opcountalgs/binaryInsertionSort.cpp
    opcountalgs/bubbleSort.cpp
    opcountalgs/bubbleSortI1.cpp
    opcountalgs/bubbleSortI2.cpp
    opcountalgs/quickSort.cpp
    opcountalgs/insertionSort.cpp
    opcountalgs/mergeSort.cpp
    opcountalgs/pyramideSort.cpp
    opcountalgs/radixSort.cpp
    opcountalgs/selectionSort.cpp
    opcountalgs/shellSortCr.cpp
    opcountalgs/shellSortSh.cpp
    opcountalgs/stableCountingSort.cpp)

add_library(checker STATIC
    checker.cpp)

add_executable(chw1 main.cpp)

target_link_libraries(chw1 PRIVATE
    checker
    algotithms
    opcountalgs)
