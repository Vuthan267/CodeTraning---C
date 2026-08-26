#include "quicksort.h"

void swap1(int *a, int *b) {
    const int temp = *a;
    *a = *b;
    *b = temp;
}

int partition1(int arr[], const int l, const int h) {
    const int pivot = arr[h];
    int i = l - 1;
    for (int j = l; j < h; j++) {
        if (arr[j] <= pivot)
            swap1(&arr[++i], &arr[j]);
    }
    swap1(&arr[i+1], &arr[h]);
    return i+1;
}

void qSort1(int arr[], const int l, const int h) {
    if (l >= h) return;
    const int pi = partition1(arr, l, h);

    qSort1(arr, l, pi - 1);
    qSort1(arr, pi + 1, h);
}

int partition2(int arr[], const int l, const int h) {
    int m = l + (h - l) / 2;

    if (arr[l] > arr[m]) swap1(&arr[l], &arr[m]);
    if (arr[l] > arr[h]) swap1(&arr[l], &arr[h]);
    if (arr[m] > arr[h]) swap1(&arr[m], &arr[h]);
    swap1(&arr[l], &arr[m]);

    const int pivot = arr[l];
    int i = l, j = h;
    while (1) {
        do i++;
        while (arr[i] < pivot);
        do j--;
        while (arr[j] > pivot);

        if (i > j) break;
        swap1(&arr[i], &arr[j]);
    }

    return j;
}

void qSort2(int arr[], const int l, const int h) {
    if (l >= h) return;

    const int pi = partition2(arr, l, h);
    qSort2(arr, l, pi);
    qSort2(arr, pi + 1, h);
}
