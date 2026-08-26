//
// Created by toingubo on 8/24/26.
//

#include "binknap.h"

int max2(int a, int b) {
    return (a > b) ? a : b;
}

int binKnap(int val[], int wt[], int n, int W) {
    int dp[W+1];
    for (int i = 0; i < W+1; i++) dp[i] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = W; j >= wt[i]; j--) {
            dp[j] = max2(dp[j], dp[j - wt[i]] + val[i]);
        }
    }

    return dp[W];
}
