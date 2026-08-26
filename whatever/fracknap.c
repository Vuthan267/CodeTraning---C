//
// Created by toingubo on 8/24/26.
//

#include <stdlib.h>

#include "fracknap.h"

int compare(const void *a, const void *b) {
    double aa = *(double*)a / *((double*)a + 1);
    double bb = *(double*)b / *((double*)b + 1);
    return (bb > aa) - (bb < aa);
}

double fracKnap(int val[], int wt[], int n, int capacity) {
    double items[n][2];
    for (int i = 0; i < n; i++) {
        items[i][0] = val[i];
        items[i][1] = wt[i];
    }
    qsort(items, n, sizeof(double[2]), compare);

    double res = 0, currentCapacity = capacity;
    for (int i = 0; i < n; i++) {
        if (items[i][1] <= currentCapacity) {
            res += items[i][0];
            currentCapacity -= items[i][1];
        }
        else {
            res += (items[i][0] / items[i][1]) * currentCapacity;
            break;
        }
    }

    return res;
}
