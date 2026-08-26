//
// Created by toingubo on 8/26/26.
//

#include "fracknap.h"

// Recursion approach. Can write as loop as well

int compareKnap(const void *a, const void *b) {
	float ratioA = *(float *) a / *((float *) a + 1);
	float ratioB = *(float *) b / *((float *) b + 1);
	return (ratioB > ratioA) - (ratioB < ratioA);
}

double doKnapRec(float items[][2], int n, int index, int current_capacity) {
	if (index == n) return 0;
	if (items[index][1] > current_capacity) {
		return ((float) items[index][0] / items[index][1]) * current_capacity;
	}

	return items[index][0] +
	       doKnapRec(items, n, index + 1, current_capacity - items[index][1]);
}

double findHighestFracKnap(int val[], int wt[], int n, int capacity) {
	float items[n][2];
	for (int i = 0; i < n; i++) {
		items[i][0] = val[i];
		items[i][1] = wt[i];
	}
	qsort(items, n, sizeof(float[2]), compareKnap);

	return doKnapRec(items, n, 0, capacity);
}
