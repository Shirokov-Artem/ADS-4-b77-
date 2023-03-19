// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int countSum = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                countSum++;
            }
        }
    }
    return countSum;
}
int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int i = 0, j = len - 1;
    while (i < j) {
        if (arr[i] + arr[j] == value) {
            count++;
            i++;
            j--;
        } else if (arr[i] + arr[j] < value) {
            i++;
        } else {
            j--;
        }
    }
    return count;
}
int binarySearch(int *arr, int left, int right, int value) {
    int mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (arr[mid] == value) {
            return mid;
        } else if (arr[mid] > value) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        int diff = value - arr[i];
        int j = binarySearch(arr, i + 1, len - 1, diff);
        if (j != -1) {
            count++;
        }
    }
    return count;
}
