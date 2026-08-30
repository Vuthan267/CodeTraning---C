//
// Created by toingubo on 8/30/26.
//

#include <stdio.h>

#include "bubblesort.h"
#include "heapsort.h"
#include "insertionsort.h"
#include "selectionsort.h"

int main() {
	int arr[] = {3,8,3,8,3,6,26,14,537,6,2,845,35,578};
	int n = sizeof(arr) / sizeof(int);
	hSort(arr, n);

	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}
