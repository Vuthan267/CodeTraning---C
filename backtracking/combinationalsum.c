//
// Created by toingubo on 8/30/26.
//

#include "combinationalsum.h"

void combineSumRec(int num[], int n, int target, int i, int subset[], int subsetSize) {
	if (target == 0) {
		printf("{");
		bool first = true;
		for (int i = 0; i < subsetSize; i++) {
			if (!first) {
				printf(", ");
			}
			printf("%d", subset[i]);
			first = false;
		}
		printf("}  ;  ");
		return;
	}

	if (target < 0 || i == n) {
		return;
	}

	subset[subsetSize] = num[i];
	combineSumRec(num, n, target - num[i], i, subset, subsetSize + 1);

	combineSumRec(num, n, target, i + 1, subset, subsetSize);
}

void printCombineSum(int num[], int n, int target) {
	int *subset = (int*) calloc(100, sizeof(int));
	combineSumRec(num, n, target, 0, subset, 0);
	free(subset);
}
