//
// Created by toingubo on 8/26/26.
//

#include "tsp.h"

int findMinCostIndex(int n, int cost[n][n], int current_city, int passed[]) {
	int min_index = -1;
	int min_cost = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (passed[i] == 0 && cost[current_city][i] < min_cost) {
			min_cost = cost[current_city][i];
			min_index = i;
		}
	}
	return min_index;
}

void solveTSP(int n, int cost[n][n]) {
	int total_cost = 0;
	int route[n + 1];
	route[0] = 0;
	route[n] = 0;

	int passed[n];
	for (int i = 0; i < n; i++) {
		passed[i] = 0;
	}

	int current_city = 0;
	int remaining = n - 1;
	int route_idx = 1;
	while (remaining > 0) {
		passed[current_city] = 1;
		int next = findMinCostIndex(n, cost, current_city, passed);

		total_cost += cost[current_city][next];
		route[route_idx] = next;
		route_idx++;

		current_city = next;
		remaining--;
	}
	total_cost += cost[current_city][0];

	printf("Total Cost: %d\nPath: ", total_cost);
	for (int i = 0; i <= n; i++) {
		printf("%d ", route[i]);
		if (i != n) printf("-> ");
	}
}
