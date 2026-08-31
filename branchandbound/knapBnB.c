//
// Created by toingubo on 8/31/26.
//

#include "knapBnB.h"

int compareKnapBnB(const void *a, const void *b) {
	float ratioA = *(float *) a / *((float *) a + 1);
	float ratioB = *(float *) b / *((float *) b + 1);
	return (ratioB > ratioA) - (ratioB < ratioA);
}

float calBound(float items[][2], int n, int index, int current_capacity, int current_value) {
	float bound = current_value;
	while (index < n && items[index][1] <= current_capacity) {
		bound += items[index][0];
		current_capacity -= items[index][1];
		index++;
	}

	if (current_capacity > 0 && index < n) {
		bound += (items[index][0] / items[index][1]) * current_capacity;
	}

	return bound;
}

void knapBnBRec(float items[][2], int n, int index, int current_capacity, int current_value, int *best_value) {
	if (index == n || current_capacity == 0) {
		if (current_value > *best_value) {
			*best_value = current_value;
		}
		return;
	}

	float bound = calBound(items, n, index, current_capacity, current_value);

	if (bound > *best_value) {
		if (current_capacity - items[index][1] >= 0) {
			knapBnBRec(items,
			           n,
			           index + 1,
			           current_capacity - items[index][1],
			           current_value + items[index][0],
			           best_value);
		}

		knapBnBRec(items,
		           n,
		           index + 1,
		           current_capacity,
		           current_value,
		           best_value);
	}
}

int solveKnapsackBnB(int val[], int wt[], int n, int capacity) {
	float items[n][2];
	for (int i = 0; i < n; i++) {
		items[i][0] = val[i];
		items[i][1] = wt[i];
	}
	qsort(items, n, sizeof(float[2]), compareKnapBnB);

	int best_value = 0;

	knapBnBRec(items, n, 0, capacity, 0, &best_value);

	return best_value;
}
