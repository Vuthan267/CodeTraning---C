//
// Created by toingubo on 8/24/26.
//

#include "activity.h"

int compare(const void *a, const void *b) {
    return *(int*)(a+1) -  *(int*)(b+1);
}

int selectAct(int start[], int end[], int n) {
    int count = 0;
    int jobs[n][2];
    for (int i = 0; i < n; i++) {
        jobs[i][0] = start[i];
        jobs[i][1] = end[i];
    }
    qsort(jobs, n, sizeof(int[2]), compare);

    int lastEnd = -1;
    for (int i = 0; i < n; i++) {
        if (jobs[i][0] >= lastEnd) {
            lastEnd = jobs[i][1];
            count++;
        }
    }

    return count;
}
