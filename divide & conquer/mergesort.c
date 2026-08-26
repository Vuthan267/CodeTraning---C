#include "mergesort.h"

void merge(int arr[], const int l, const int m, const int h) {
    const int n1 = m - l + 1;
    const int n2 = h - m;

    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) R[i] = arr[m + i + 1];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mSort(int arr[], const int l, const int h) {
    if (l >= h) return;

    const int m = l + (h - l) / 2;
    mSort(arr, l, m);
    mSort(arr, m+1, h);

    merge(arr, l, m, h);
}
