//
// Created by toingubo on 8/26/26.
//

#include "cookie.h"

int compareCookie(const void *a, const void *b) {
	int val_a = (*(int*)a);
	int val_b = (*(int*)b);
	return (val_a > val_b) - (val_a < val_b);
}

int findMaxChildren(int greed[], int cookies[], int ng, int nc) {
	qsort(greed, ng, sizeof(int), compareCookie);
	qsort(cookies, nc, sizeof(int), compareCookie);

	int i = 0;
	int j = 0;
	int max_child = 0;

	while (i < ng && j < nc) {
		if (greed[i] <= cookies[j]) {
			max_child++;
			i++;
			j++;
		} else {
			j++;
		}
	}

	return max_child;
}
