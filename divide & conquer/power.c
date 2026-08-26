//
// Created by toingubo on 8/25/26.
//

#include "power.h"

double power(double b, int e) {
    if (e == 0) return 1;
    if (e < 0) return 1 / power(b, -e);

    const double temp = power(b, e / 2);

    if (e % 2 == 0) return temp * temp;
    else return b * temp * temp;
}
