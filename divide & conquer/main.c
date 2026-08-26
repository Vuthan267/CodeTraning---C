#include <stdio.h>
#include <stdlib.h>

#include "mergesort.h"
#include "quicksort.h"
#include "binarysearch.h"
#include "power.h"
#include "karatsuba.h"
#include "closest2points.h"

int main() {
    Point pts[] = {
        {2, 3}, {12, 30}, {40, 50},
        {5, 1}, {12, 10}, {3, 4}
    };

    int n = sizeof(pts) / sizeof(pts[0]);

    printf("Minimum distance = %.6lf\n", closestSolve(pts, 0, n-1));

    return 0;
}
