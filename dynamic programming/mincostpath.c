//
// Created by toingubo on 8/28/26.
//

#include "mincostpath.h"

int minCost3(int a, int b, int c) {
	int min = a;
	if (b < min) min = b;
	if (c < min) min = c;
	return min;
}

int minCostPath(int n, int m, int cost[n][m]) {
	int dp[n][m];
	dp[0][0] = cost[0][0];

	for (int i = 1; i < n; i++) {
		dp[i][0] = dp[i - 1][0] + cost[i][0];
	}

	for (int j = 1; j < m; j++) {
		dp[0][j] = dp[0][j - 1] + cost[0][j];
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			dp[i][j] = minCost3(dp[i - 1][j - 1],
			                    dp[i][j - 1],
			                    dp[i - 1][j])
			           + cost[i][j];
		}
	}

	return dp[n - 1][m - 1];
}

int minCostPath1D(int n, int m, int cost[n][m]) {
	int dp[m];

	dp[0] = cost[0][0];
	for (int i = 1; i < m; i++) {
		dp[i] = dp[i - 1] + cost[0][i];
	}

	for (int i = 1; i < n; i++) {
		int top_left = dp[0];
		dp[0] += cost[i][0];
		for (int j = 1; j < m; j++) {
			int current_top = dp[j];
			dp[j] = minCost3(top_left, dp[j], dp[j-1]) + cost[i][j];
			top_left = current_top;
		}
	}

	return dp[m - 1];
}
