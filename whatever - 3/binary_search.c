//
// Created by toingubo on 9/5/26.
//

int binary_search_util(int arr[], int x, int l, int h) {
    if (l > h) {
        return -1;
    }

    int m = l + (h - l) / 2;

    if (arr[m] == x) {
        return m;
    }

    if (arr[m] < x) {
        return binary_search_util(arr, x, m + 1, h);
    } else {
        return binary_search_util(arr, x, l, m - 1);
    }
}

int binary_search(int arr[], int n, int x) {
    return binary_search_util(arr, x, 0, n - 1);
}
