//
// Created by toingubo on 8/27/26.
//

#ifndef C_ROBBER_H
#define C_ROBBER_H

int maxRob(int a, int b);

// Can also optimize using variables, because we only care dp[i - 1] and dp[i - 2]
int findMaxRobbingMoney(int house_values[], int n) {
	int dp[n + 1];
	dp[0] = 0;
	dp[1] = house_values[0];

	for (int i = 0; i <= n; i++) {
		int rob = house_values[i - 1] + dp[i - 2];
		int not_rob = dp[i - 1];
		dp[i] = maxRob(rob, not_rob);
	}

	return dp[n];
}

#endif //C_ROBBER_H
