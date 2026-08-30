//
// Created by toingubo on 8/30/26.
//

#include "selectionsort.h"

void swapSSort(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int max_idx = 0;
		for (int j = 0; j < n - i; j++) {
			if (arr[j] > arr[max_idx]) {
				max_idx = j;
			}
		}
		swapSSort(&arr[max_idx], &arr[n - i - 1]);
	}
}
