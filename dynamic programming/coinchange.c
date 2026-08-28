//
// Created by toingubo on 8/27/26.
//

#include "coinchange.h"

#include <limits.h>

int min2(int a, int b) {
	return (a < b) ? a : b;
}

int findMinCoin(int coins[], int n, int sum) {
	int dp[sum + 1];
	for (int i = 1; i <= sum; i++) {
		dp[i] = sum + 1;
	}
	dp[0] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = coins[i]; j <= sum; j++) {
			dp[j] = min2(dp[j], dp[j - coins[i]] + 1);
		}
	}

	return (dp[sum] != sum + 1) ? dp[sum] : -1;
}

int countAllWays(int coins[], int n, int sum) {
	int dp[sum + 1];
	dp[0] = 1;
	for (int i = 1; i <= sum; i++) {
		dp[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = coins[i]; j <= sum; j++) {
			dp[j] += dp[j - coins[i]];
		}
	}

	return dp[sum];
}
