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
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        int complement = value - arr[i];
        int lo = 0, hi = len - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] == complement) {
                count++;
                break;
            }
            else if (arr[mid] < complement) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
    }
    return count / 2;
}
