//
// Created by toingubo on 8/31/26.
//

#include "tspBnB.h"

static int ROW_MIN_1[50];
static int ROW_MIN_2[50];

void precalculateRowMinimums(int n, int cost[n][n]) {
	for (int i = 0; i < n; i++) {
		int m1 = INT_MAX, m2 = INT_MAX;
		for (int j = 0; j < n; j++) {
			if (i == j) continue; // Skip traveling to itself

			if (cost[i][j] < m1) {
				m2 = m1;
				m1 = cost[i][j];
			} else if (cost[i][j] < m2) {
				m2 = cost[i][j];
			}
		}
		ROW_MIN_1[i] = m1;
		ROW_MIN_2[i] = m2;
	}
}

void printTSPNode(int n, TSP_Node node, int best) {
	printf("Visited: ");

	for (int i = 0; i < n; i++) {
		if (node.visited & (1 << i)) {
			printf("%d ", i);
		}
	}

	printf("| Current: %d", node.current_city);
	printf(" | Level: %d", node.level);
	printf(" | Cost: %d", node.total_cost);
	printf(" | Bound: %d", node.bound);
	printf(" | Best: %d\n", best);
}

int calTSPBound(int n, int cost[n][n], TSP_Node current) {
	int bound = current.total_cost;
	int min = INT_MAX;
	for (int i = 1; i < n; i++) {
		if (!(current.visited & (1 << i)) && cost[current.current_city][i] < min) {
			min = cost[current.current_city][i];
		}
	}

	if (min != INT_MAX) {
		bound += min;
	}

	int temp = 0;
	for (int i = 1; i < n; i++) {
		if (!(current.visited & (1 << i))) {
			temp += (ROW_MIN_1[i] + ROW_MIN_2[i]);
		}
	}
	bound += temp / 2;

	min = INT_MAX;
	for (int i = 1; i < n; i++) {
		if (!(current.visited & (1 << i)) && cost[i][0] < min) {
			min = cost[i][0];
		}
	}

	if (min != INT_MAX) {
		bound += min;
	}

	return bound;
}

void tspRec(int n, int cost[n][n], TSP_Node current, int *best) {
	if (current.level == n) {
		int total_cost = current.total_cost + cost[current.current_city][0];
		if (total_cost < *best) {
			*best = total_cost;
		}
		return;
	}

	current.bound = calTSPBound(n, cost, current);
	printTSPNode(n, current, *best);

	if (current.bound < *best) {
		for (int i = 1; i < n; i++) {
			if (!(current.visited & (1 << i))) {
				TSP_Node next = current;
				next.current_city = i;
				next.level++;
				next.total_cost += cost[current.current_city][i];
				next.visited |= (1 << i);
				tspRec(n, cost, next, best);
			}
		}
	}
}

int solveTSPBnB(int n, int cost[n][n]) {
	precalculateRowMinimums(n, cost);

	int best = INT_MAX;

	TSP_Node Greedy = {0};
	Greedy.total_cost = 0;
	Greedy.current_city = 0;
	Greedy.level = 1;
	Greedy.visited = 1 << 0;

	while (true) {
		if (Greedy.level == n) {
			best = Greedy.total_cost + cost[Greedy.current_city][0];
			break;
		}

		int min_cost = INT_MAX;
		int min_idx = -1;
		for (int i = 1; i < n; i++) {
			if (!(Greedy.visited & (1 << i)) && cost[Greedy.current_city][i] < min_cost) {
				min_cost = cost[Greedy.current_city][i];
				min_idx = i;
			}
		}

		if (min_idx == -1) {
			break;
		}

		Greedy.level++;
		Greedy.total_cost += cost[Greedy.current_city][min_idx];
		Greedy.current_city = min_idx;
		Greedy.visited |= (1 << min_idx);
	}

	TSP_Node root = {0};
	root.current_city = 0;
	root.level = 1;
	root.total_cost = 0;
	root.visited = 1 << 0;

	tspRec(n, cost, root, &best);

	return best;
}
