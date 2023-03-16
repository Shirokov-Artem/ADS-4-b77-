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
    return 0;
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
    return 0;
}
int countPairs3(int *arr, int len, int value) {
    Sort(arr, len);
    int left = 0, right = len - 1, count = 0;
    while (left < right) {
        int curr_sum = arr[left] + arr[right];
        if (curr_sum == value) {
            count++;
            int l = left + 1, r = right - 1;
            while (l <= r && arr[l] == arr[left]) {
                count++;
                l++;
            }
            while (l <= r && arr[r] == arr[right]) {
                count++;
                r--;
            }
            left = l;
            right = r;
        } else if (curr_sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return count;
    return 0;
}
