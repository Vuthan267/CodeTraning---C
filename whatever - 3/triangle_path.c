//
// Created by toingubo on 9/5/26.
//

#include "triangle_path.h"

#include <stdio.h>

int min2_t(int a, int b) {
    return (a < b) ? a : b;
}

int solve_triangle(int n, int triangle[n][n]) {
    int dp[n];
    for (int i = 0; i < n; i++) {
        dp[i] = triangle[n - 1][i];
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            dp[j] = min2_t(dp[j], dp[j + 1]) + triangle[i][j];
        }
    }

    return dp[0];
}
