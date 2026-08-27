//
// Created by toingubo on 8/27/26.
//

#include "jobsequencing.h"

int compareJob(const void *a, const void *b) {
	int profit_a = ((Job *) a)->profit;
	int profit_b = ((Job *) b)->profit;
	return (profit_b > profit_a) - (profit_b < profit_a);
}

int * findMaxProfit(int deadline[], int profit[], int n) {
	Job jobs[n];
	int max_days = INT_MIN;
	for (int i = 0; i < n; i++) {
		jobs[i].deadline = deadline[i];
		jobs[i].profit = profit[i];
		if (jobs[i].deadline > max_days) {
			max_days = jobs[i].deadline;
		}
	}
	qsort(jobs, n, sizeof(Job), compareJob);

	int days[max_days + 1];
	for (int i = 0; i <= max_days; i++) {
		days[i] = 0;
	}

	int jobs_count = 0;
	int max_profit = 0;
	for (int i = 0; i < n; i++) {
		Job *current_job = &jobs[i];
		for (int j = current_job->deadline; j > 0; j--) {
			if (days[j] == 0) {
				days[j] = 1;
				jobs_count++;
				max_profit += current_job->profit;
				break;
			}
		}
	}

	// Result needs both
	int *res = (int*)malloc(2 * sizeof(int));
	*res = jobs_count;
	*(res + 1) = max_profit;

	return res;
}
