//
// Created by toingubo on 8/30/26.
//

#include "bubblesort.h"

void swapBSort(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		bool swapped = false;
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swapBSort(&arr[j], &arr[j + 1]);
				swapped = true;
			}
		}
		if (!swapped) {
			break;
		}
	}
}
