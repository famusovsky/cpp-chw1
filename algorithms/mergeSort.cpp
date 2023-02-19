#include <climits>

// Функция слияния двух отсортированных массивов
void merge(int *begin, int *middle, int *end) {
    int n_1 = middle - begin + 1, n_2 = end - middle + 1;
    int* left = new int[n_1];
    int* right = new int[n_2];
    for (int i = 0; i < n_1 - 1; ++i) {
        left[i] = *(begin + i);
    }
    for (int i = 0; i < n_2 - 1; ++i) {
        right[i] = *(middle + i);
    }
    left[n_1 - 1] = INT_MAX;
    right[n_2 - 1] = INT_MAX;
    int i = 0, j = 0;
    for (; begin != end; ++begin) {
        if (left[i] <= right[j]) {
            *begin = left[i++];
        } else {
            *begin = right[j++];
        }
    }
    delete[] left;
    delete[] right;
}

// Рекурсивная функция сортировки слиянием
void mergeSortRecursion(int *begin, int *end) {
    if (begin != end - 1 && begin != end) {
        auto middle = begin + (end - begin) / 2;
        mergeSortRecursion(begin, middle);
        mergeSortRecursion(middle, end);
        merge(begin, middle, end);
    }
}

// Метод вызывающий рекурсивную функцию сортировки слиянием
void mergeSort(int *begin, int n, int k) {
    mergeSortRecursion(begin, begin + n);
}