//
// Created by toingubo on 8/24/26.
//

#include "maxprofit.h"

#include <stdio.h>

int compare(const void *a, const void *b) {
    return ( *((int*)b + 2) > *((int*)a + 2) ) - ( *((int*)b + 2) < *((int*)a + 2) );
}

int maxProfit(int id[], int deadline[], int profit[], int n) {
    int jobs[n][3];
    int maxDays = INT_MIN;
    for (int i = 0; i < n; i++) {
        jobs[i][0] = id[i];
        jobs[i][1] = deadline[i];
        jobs[i][2] = profit[i];

        if (deadline[i] > maxDays)
            maxDays = deadline[i];
    }
    qsort(jobs, n, sizeof(int[3]), compare);

    int days[maxDays + 1];
    for (int i = 0; i <= maxDays; i++)
        days[i] = 0;

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i][1]; j > 0; j--) {
            if (days[j] == 0) {
                days[j] = jobs[i][0];
                res += jobs[i][2];
                break;
            }
        }
    }

    return res;
}
