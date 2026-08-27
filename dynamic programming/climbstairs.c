//
// Created by toingubo on 8/27/26.
//

#include "climbstairs.h"

// Can optimize by saving only the 2 previous states
int findNWaysClimb(int n) {
	int dp[n + 1];
	for (int i = 0; i <= n; i++) {
		dp[i] = 0;
	}
	dp[0] = 1;
	dp[1] = 1;

	if (n < 2) return dp[n];
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n];
}

int findNWaysClimb3(int n) {
	int dp[n + 1];
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;

	if (n < 3) return dp[n];
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	return dp[n];
}
