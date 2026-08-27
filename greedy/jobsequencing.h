//
// Created by toingubo on 8/27/26.
//

#ifndef C_JOBSEQUENCING_H
#define C_JOBSEQUENCING_H
#include <limits.h>
#include <stdlib.h>

typedef struct {
	int deadline;
	int profit;
} Job;

int compareJob(const void *a, const void *b);

int *findMaxProfit(int deadline[], int profit[], int n);

#endif //C_JOBSEQUENCING_H
