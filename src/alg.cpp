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
    int count = 0, i = 0, j = len - 1;
    while (i < j) {
        int sum = arr[i] + arr[j];
        if (sum == value) {
            count++;
            i++;
            j--;
        } else if (sum < value) {
            i++;
        } else {
            j--;
        }
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        int lo = i + 1, hi = len - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (arr[mid] + arr[i] == value) {
                count++;
                break;
            } else if (arr[mid] + arr[i] < value) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
    }
    return count;
}
