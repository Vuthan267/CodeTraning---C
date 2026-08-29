//
// Created by toingubo on 8/29/26.
//

#include "allsubset.h"

#include <stdbool.h>

void subsetRec(int set[], int n, int i, int subset[], int subsetSize) {
	if (i == n - 1) {
		printf("{");
		for (int i = 0; i < subsetSize; i++) {
			printf("%d", subset[i]);
			if (i != subsetSize - 1) {
				printf(", ");
			}
		}
		printf("} ");
		return;
	}

	subset[subsetSize] = set[i];
	subsetRec(set, n, i + 1, subset, subsetSize + 1);

	subsetRec(set, n, i + 1, subset, subsetSize);
}

void printAllSubset(int set[], int n) {
	int *subset = (int*)calloc(n, sizeof(int));
	subsetRec(set, n, 0, subset, 0);
}

// Optimized bitmasking version
void printAllSubset2(int set[], int n) {
	for (int i = 0; i < (1 << n); i++) {
		printf("{");
		bool first = true;
		for (int j = 0; j < n; j++) {
			if ((i & (1 << j)) != 0) {
				if (!first) {
					printf(", ");
				}
				printf("%d", set[j]);
				first = false;
			}
		}
		printf("}  ;  ");
	}
}
