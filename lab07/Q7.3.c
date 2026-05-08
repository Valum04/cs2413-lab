#include <stdio.h>

#define K 3

void insertionSort(int arr[], int left, int right) {

    int i, j, key;

    for (i = left + 1; i <= right; i++) {

        key = arr[i];
        j = i - 1;

        while (j >= left && arr[j] > key) {

            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void merge(int arr[], int left, int mid, int right) {

    int i, j, k;

    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[1000], R[1000];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {

        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void hybridMergeSort(int arr[], int left, int right) {

    if (right - left + 1 <= K) {

        insertionSort(arr, left, right);
        return;
    }

    int mid = left + (right - left) / 2;

    hybridMergeSort(arr, left, mid);
    hybridMergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

void printArray(int arr[], int n) {

    int i;

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main() {

    int arr[] = {39, 81, 45, 90, 27, 72, 18};

    int n = sizeof(arr) / sizeof(arr[0]);

    hybridMergeSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}
