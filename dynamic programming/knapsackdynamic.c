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
