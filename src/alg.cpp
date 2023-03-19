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
    int newLen = len - 1;
    while (arr[newLen] > value) {
        newLen -= 1;
    }
    for (int i = 0; i < newLen; i++) {
        for (int j = newLen; j > i; j--) {
            if (arr[i] + arr[j] == value) {
                countSum++;
            }
        }
    }
    return countSum;
}
int binary_search(int *arr, int left, int right, int target) {
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        int j = binary_search(arr, i+1, len-1, value-arr[i]);
        if (j != -1) {
            count++;
        }
    }
    return count;
}
