//
// Created by toingubo on 8/27/26.
//

#include "rodcutting.h"

int max2a(int a, int b) {
	return (a > b) ? a : b;
}

int findMaxProfitRod(int prices[], int n) {
	n--;
	int dp[n];
	for (int i = 0; i < n; i++) {
		dp[i] = 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max2a(dp[i], prices[j] + dp[i - j]);
		}
	}

	return dp[n];
}
