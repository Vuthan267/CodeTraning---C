//
// Created by toingubo on 8/26/26.
//

#include "atm.h"

int compareMoney(const void *a, const void *b) {
	return (*(int*)b - *(int*)a);
}

int findLowestATM(int money[], int n, int M) {
	qsort(money, n, sizeof(int), compareMoney);
	int money_cnt = 0;
	int i = 0;

	while (i < n) {
		if (money[i] <= M) {
			money_cnt++;
			M -= money[i];
		} else {
			i++;
		}
	}

	return (M == 0) ? money_cnt : -1;
}
