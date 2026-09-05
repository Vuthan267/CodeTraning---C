//
// Created by toingubo on 9/4/26.
//

#include "karatsuba.h"

long long multiply_karatsuba(long long x, long long y) {
    if (x < BASE_A || y < BASE_A) {
        return x * y;
    }

    long long x1 = x / BASE_A;
    long long x0 = x % BASE_A;
    long long y1 = y / BASE_A;
    long long y0 = y % BASE_A;

    long long z0 = multiply_karatsuba(x0, y0);
    long long z1 = multiply_karatsuba(x1, y1);
    long long z2 = multiply_karatsuba(x0 + x1, y0 + y1) - z0 - z1;

    return z1 * (BASE_A * BASE_A) + z2 * BASE_A + z0;
}
