// Copyright 2021 NNTU-CS
void Sort(int* arr, int len) {
    int t;
    for (int i = 0; i < len - 1 ; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j + 1] < arr[j]) {
                t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}
int countPairs1(int *arr, int len, int value) {
    Sort(arr, len);
    int countSum = 0;
    int newLen = len - 1;
    for (int i = 0; i < newLen; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] == arr[j]) {
                ++countSum;
            }
        }
    }
    return countSum;
}
int countPairs2(int *arr, int len, int value) {
    Sort(arr, len);
    int countSum = 0;
    int newLen = len - 1;
    for (int i = 0; i < newLen; i++) {
        for (int j = newLen; i < j; --j) {
            if (arr[i] == arr[j]) {
                ++countSum;
            }
        }
    }
    return countSum;
}
int binarySearch(int *arr, int len, int value) {
    Sort(arr, len);
    int low = 0;
    int high = len - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == value) {
            return mid;
        } else if (arr[mid] < value) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}
int countPairs3(int *arr, int len, int value) {
    Sort(arr, len);
    int count = 0;
    for (int i = 0; i < len; i++) {
        int diff = value - arr[i];
        int index = binarySearch(arr, len, diff);
        if (index != -1 && index != i) {
            count++;
        }
    }
    return count / 2;
}
