//
// Created by toingubo on 8/28/26.
//

#include "lcs.h"

int maxLCS(int a, int b) {
	return (a > b) ? a : b;
}

int findLCS(char s1[], char s2[2], int n, int m) {
	int dp[m + 1];
	for (int i = 0; i <= m; i++) {
		dp[i] = 0;
	}

	for (int i = 1; i <= n; i++) {
		int upper_left = dp[0];
		for (int j = 1; j <= m; j++) {
			int current_upper = dp[j];

			if (s1[i - 1] == s2[j - 1]) {
				dp[j] = upper_left + 1;
			} else {
				dp[j] = maxLCS(current_upper, dp[j - 1]);
			}

			upper_left = current_upper;
		}
	}

	return dp[m];
}
