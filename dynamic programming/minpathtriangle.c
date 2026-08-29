//
// Created by toingubo on 8/29/26.
//

#include "minpathtriangle.h"

int minTriangle(int a, int b) {
	return (a < b) ? a : b;
}

// 2D unoptimized space, calculating from top to bottom version
int findMinPathTriangle1(int n, int triangle[n][n]) {
	int dp[n + 1][n + 1];
	dp[1][1] = triangle[0][0];

	int upper_left, upper_right;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j > 1) {
				upper_left = dp[i - 1][j - 1];
			} else {
				upper_left = INT_MAX;
			}

			if (j < i) {
				upper_right = dp[i - 1][j];
			} else {
				upper_right = INT_MAX;
			}

			dp[i][j] = minTriangle(upper_left, upper_right) + triangle[i - 1][j - 1];
		}
	}

	int min_path = INT_MAX;
	for (int j = 1; j <= n; j++) {
		if (dp[n][j] < min_path) {
			min_path = dp[n][j];
		}
	}

	return min_path;
}

// Optimized 1D array, calculting from bottom to top version
int findMinPathTriangle2(int n, int triangle[n][n]) {
	int dp[n + 1];
	for (int i = 1; i <= n; i++) {
		dp[i] = triangle[n - 1][i - 1];
	}

	for (int i = n - 1; i > 0; i--) {
		for (int j = 1; j <= i; j++) {
			dp[j] = triangle[i - 1][j - 1] + minTriangle(dp[j], dp[j + 1]);
		}
	}

	return dp[1];
}
