//
// Created by toingubo on 8/27/26.
//

#ifndef C_ACTIVITY_H
#define C_ACTIVITY_H
#include <limits.h>
#include <stdlib.h>

typedef struct {
	int start;
	int finish;
} Activity;

int compareAc(const void *a, const void *b);

int findMaxActivity(int start[], int finish[], int n);

#endif //C_ACTIVITY_H
