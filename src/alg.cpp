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
    int count = 0;
    int i = 0;
    int j = len - 1;
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
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    int i = 0;
    int j = len - 1;
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
