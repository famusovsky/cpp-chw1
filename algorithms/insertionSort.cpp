// Метод сортировки вставками
void insertionSort(int *begin, int n, int k) {
    int *end = begin + n;
    if (begin != end) {
        for (auto i = begin + 1; i != end; ++i) {
            int cur = *i;
            auto j = i - 1;
            while (j - begin >= 0 && *j > cur) {
                *(j + 1) = *j;
                --j;
            }
            *(j + 1) = cur;
        }
    }
}