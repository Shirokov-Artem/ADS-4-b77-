// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int countSum = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                countSum++;
            }
        }
    }
    return countSum;
}
int countPairs2(int *arr, int len, int value) {
    int countSum = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = len - 1; i < j; j--) {
            if (arr[i] + arr[j] == value) {
                countSum++;
            }
        }
    }
    return countSum;
}
int binary_search(int* arr, int len, int value) {
    int left = 0, right = len - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) {
            return mid;
        } else if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        int j = binary_search(arr, len, value - arr[i]);
        if (j != -1 && j > i) {
            count++;
        }
    }
    return count;
}
