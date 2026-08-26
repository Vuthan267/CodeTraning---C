//
// Created by toingubo on 8/25/26.
//

#include "karatsuba.h"

long long multiply(long long x, long long y) {
    if (x < BASE || y < BASE)
        return x * y;

    long long x1 = x / BASE;
    long long x0 = x % BASE;
    long long y1 = y / BASE;
    long long y0 = y % BASE;

    long long z0 = multiply(x0, y0);
    long long z2 = multiply(x1, y1);
    long long z3 = multiply((x0 + x1), (y0 + y1));

    return z2 * BASE * BASE + (z3 - z2 - z0) * BASE + z0;
}
