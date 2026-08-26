//
// Created by toingubo on 8/25/26.
//

#include "binarysearch.h"

int binarySearch(int arr[], const int l, const int h, const int x) {
    if (l >= h) return -1;
    int const m = l + (h - l) / 2;

    if (arr[m] == x) return m;
    if (arr[m] > x) return binarySearch(arr, l, m - 1, x);
    return binarySearch(arr, m + 1, h, x);
}
