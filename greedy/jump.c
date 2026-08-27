//
// Created by toingubo on 8/27/26.
//

#include "jump.h"


int max2(int a, int b) {
	return (a > b) ? a : b;
}

int findMinJump(int steps[], int n) {
	int current_reach = 0;
	int max_reach = 0;
	int jump_count = 0;

	for (int i = 0; i < n; i++) {
		max_reach = max2(max_reach, steps[i] + i);
		if (max_reach >= n - 1) {
			return jump_count + 1;
		}

		if (i == current_reach) {
			if (i == max_reach) {
				return -1;
			} else {
				jump_count++;
				current_reach = max_reach;
			}
		}

		// 1 4 3 2 6 7
	}

	return -1;
}
