int binarySearch(int *arr, int key, int left, int right) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (key < arr[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

// Метод сортировки вставками с бинарным поиском
void binaryInsertionSort(int *arr, int n, int k) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        int pos = binarySearch(arr, key, 0, j);
        while (j >= pos) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
