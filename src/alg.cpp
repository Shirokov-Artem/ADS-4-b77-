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
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        int l = i + 1, r = len - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] + arr[i] == value) {
                count++;
                break;
            } else if (arr[mid] + arr[i] < value) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }
    return count;
}
