//
// Created by toingubo on 8/28/26.
//

#include "knapsackdynamic.h"

int maxKnap(int a, int b) {
	return (a > b) ? a : b;
}

int solveBinKnap(int val[], int wt[], int n, int capacity) {
	int dp[capacity + 1];
	for (int i = 0; i <= capacity; i++) {
		dp[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = capacity; j >= wt[i]; j--) {
			dp[j] = maxKnap(dp[j], dp[j - wt[i]] + val[i]);
		}
	}

	return dp[capacity];
}

void printBinKnap(int val[], int wt[], int n, int capacity) {
	int dp[capacity + 1];
	bool chosen[n + 1][capacity + 1];

	for (int i = 0; i <= capacity; i++) {
		dp[i] = 0;
		for (int j = 0; j <= n; j++) {
			chosen[j][i] = false;
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = capacity; j >= wt[i]; j--) {
			int temp = dp[j];
			dp[j] = maxKnap(dp[j], dp[j - wt[i]] + val[i]);
			if (dp[j] > temp) {
				chosen[i][j] = true;
			}
		}
	}

	if (dp[capacity] == 0) {
		printf("Invalid!");
		return;
	}

	for (int i = n - 1; i >= 0; i--) {
		if (chosen[i][capacity]) {
			printf("%d ", wt[i]);
			capacity -= wt[i];
		}
	}
}
