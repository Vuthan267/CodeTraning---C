//
// Created by toingubo on 8/24/26.
//

#include "fibonacci.h"

int fib1(int n, int memo[]) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    memo[n] = fib1(n-1, memo) + fib1(n-2, memo);
    return memo[n];
}
