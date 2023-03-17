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
            if (arr[i] + arr[j] == value) {
                countSum++;
            }
        }
    }
    return countSum;
}
int countPairs2(int *arr, int len, int value) {
    Sort(arr, len);
    int countSum = 0;
    int newLen = len - 1;
    for (int i = 0; i < newLen; i++) {
        for (int j = newLen; i < j; j--) {
            if (arr[i] + arr[j] == value) {
                countSum++;
            }
        }
    }
    return countSum;
}
int countPairs3(int *arr, int len, int value) {
    Sort(arr, len);
    int count = 0;
    int i = 0;
    int j = len - 1;
    while (i < j) {
        if (arr[i] + arr[j] == value) {
            count++;
            i++;
            j--;
            while (i < len && arr[i] == arr[i - 1])
                i++;
            while (j >= 0 && arr[j] == arr[j + 1])
                j--;
        } else if (arr[i] + arr[j] < value) {
            i++;
        } else {
            j--;
        }
    }
    return count;
}
