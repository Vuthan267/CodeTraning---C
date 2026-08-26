//
// Created by toingubo on 8/25/26.
//

#include "lis.h"

#include <limits.h>

int max2(int a, int b) {
    return (a > b) ? a : b;
}

int lisTabulation(int arr[], int n) {
    int dp[n+1];
    for (int i = 0; i <= n; i++) dp[i] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++)
            if (arr[i-1] > arr[j-1])
                dp[i] = max2(dp[i], dp[j] + 1);
    }

    int max = INT_MIN;
    for (int i = 1; i <= n; i++)
        if (max < dp[i]) max = dp[i];
    return max;
}
