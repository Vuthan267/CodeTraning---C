//
// Created by toingubo on 9/4/26.
//

#include "sorting.h"

int is_sorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) return 0; // Sai trật tự
    }
    return 1; // Đã sắp xếp đúng
}

// Easy sort

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void b_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;

        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }

        if (swapped == 0) {
            break;
        }
    }
}

void i_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void s_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;

        for (int j = i; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        swap(&arr[min_idx], &arr[i]);
    }
}

// Mergesort
void merge_a(int arr[], int l, int m, int h) {
    int n1 = m - l + 1;
    int n2 = h - m;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[m + 1 + i];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            arr[k] = L[i];
            i++;
        } else {
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
        arr[k] =R[j];
        j++;
        k++;
    }
}

void m_sort_util(int arr[], int l, int h) {
    if (l >= h) {
        return;
    }

    int m = l + (h - l) / 2;
    m_sort_util(arr, l, m);
    m_sort_util(arr, m + 1, h);

    merge_a(arr, l, m, h);
}

void m_sort(int arr[], int n) {
    m_sort_util(arr, 0, n - 1);
}

// Quicksort
int partition_a(int arr[], int l, int h) {
    int i = l - 1, j = h + 1;

    int m = l + (h - l) / 2;
    if (arr[l] > arr[m]) swap(&arr[l], &arr[m]);
    if (arr[l] > arr[h]) swap(&arr[l], &arr[h]);
    if (arr[m] > arr[h]) swap(&arr[m], &arr[h]);

    int pivot = arr[m];

    while (1) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j) {
            return j;
        }

        swap(&arr[i], &arr[j]);
    }
}

void q_sort_util(int arr[], int l, int h) {
    if (l >= h) {
        return;
    }

    int pi = partition_a(arr, l, h);

    q_sort_util(arr, l, pi);
    q_sort_util(arr, pi + 1, h);
}

void q_sort(int arr[], int n) {
    q_sort_util(arr, 0, n - 1);
}

// Heapsort
void heapify_a(int arr[], int n, int i) {
    int largest = i;

    while (1) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && arr[l] > arr[largest]) {
            largest = l;
        }
        if (r < n && arr[r] > arr[largest]) {
            largest = r;
        }

        if (largest == i) {
            break;
        }

        swap(&arr[i], &arr[largest]);
        i = largest;
    }
}

void h_sort(int arr[], int n) {
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapify_a(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify_a(arr, i, 0);
    }
}


