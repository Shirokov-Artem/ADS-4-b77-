// Copyright 2021 NNTU-CS
int binary_search(int* arr, int len, int value) {
    int left = 0;
    int right = len - 1;
    int count = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == value) {
            count++;
            int i = mid - 1;
            while (i >= left && arr[i] == value) {
                count++;
                i--;
            }
            i = mid + 1;
            while (i <= right && arr[i] == value) {
                count++;
                i++;
            }
            return count;
        } else if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return count;
}
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
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        int num = value - arr[i];
        count += binary_search(arr + i + 1, len - i - 1, num);
    }
    return count;
}
