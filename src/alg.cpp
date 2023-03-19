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
    int countSum = 0;
    int i = 0;
    int j = len - 1;
    while (i < j) {
        int sum = arr[i] + arr[j];
        if (sum == value) {
            countSum++;
            i++;
            j--;
        } else if (sum < value) {
            i++;
        } else {
            j--;
        }
    }
    return countSum;
}
