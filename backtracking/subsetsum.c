//
// Created by toingubo on 8/29/26.
//

#include "subsetsum.h"

void subsetSumRec(int set[], int n, int sum, int i, int res[], int resSize) {
	if (sum == 0) {
		printf("{");
		for (int i = 0; i < resSize; i++) {
			printf("%d", res[i]);
			if (i != resSize - 1) {
				printf(", ");
			}
		}
		printf("} ");
		return;
	} else if (i == n || sum < 0) {
		return;
	}

	res[resSize] = set[i];
	subsetSumRec(set, n, sum - set[i], i + 1, res, resSize + 1);

	subsetSumRec(set, n, sum, i + 1, res, resSize);
}

void findSubsetSum(int set[], int n, int sum) {
	int res[n];
	subsetSumRec(set, n, sum, 0, res, 0);
}
