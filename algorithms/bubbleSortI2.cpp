void bubbleSortI2(int *arr, int n, int k) {
    int newn = n;
    while (newn > 0) {
        int last_swap = 0;
        for (int i = 1; i < newn; i++) {
            if (arr[i - 1] > arr[i]) {
                int temp = arr[i - 1];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                last_swap = i;
            }
        }
        newn = last_swap;
    }
}