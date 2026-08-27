//
// Created by toingubo on 8/27/26.
//

#include "fibonacci.h"

int findFibo(int n) {
	int dp[n + 1];
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i-1] + dp[i-2];
	}

	return dp[n];
}
