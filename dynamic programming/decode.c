//
// Created by toingubo on 8/28/26.
//

#include "decode.h"

int countDecodeWays(char digits[], int n) {
	if (n == 0 || (n > 0 && digits[0] == '0')) {
		return 0;
	}

	int dp[n + 1];
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i] = 0;

		if (digits[i - 1] > '0') {
			dp[i] += dp[i - 1];
		}

		int two_digits = (digits[i - 2] - '0') * 10 + (digits[i - 1] - '0');
		if (two_digits >= 10 && two_digits <= 26) {
			dp[i] += dp[i - 2];
		}
	}

	return dp[n];
}
