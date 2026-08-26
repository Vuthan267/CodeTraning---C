#include <limits.h>
//
// Created by toingubo on 8/24/26.
//
int min2(int a, int b) {
    return (a < b) ? a : b;
}

int minCoins(int coins[], int n, int amount) {
    int dp[amount + 1];

    dp[0] = 0;
    for (int i = 1; i < amount + 1; i++) dp[i] = INT_MAX;

    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= amount; j++) {
            if (dp[j - coins[i]] != INT_MAX)
                dp[j] = min2(dp[j], dp[j - coins[i]] + 1);
        }
    }

    return dp[amount];
}