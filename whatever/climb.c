//
// Created by toingubo on 8/24/26.
//

#include "climb.h"

int climb1(int n, int memo[]) {
    if (n == 2) return 2;
    if (n == 1) return 1;

    if (memo[n] != -1) return memo[n];
    memo[n] = climb1(n-1, memo) + climb1(n-2, memo);
    return memo[n];
}
