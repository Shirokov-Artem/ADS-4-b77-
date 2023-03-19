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
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        int left = i + 1;
        int right = len - 1;
        int target = value - arr[i];
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                count++;
                break;
            } else if (arr[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
    }
    return count;
}
