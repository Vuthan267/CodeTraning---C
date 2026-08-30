//
// Created by toingubo on 8/30/26.
//

#include <stdbool.h>

#include "atm.h"

int findLeastBillATM(int money[], int n, int target) {
	PriorityQueue PQ;
	initQueue(&PQ, 100);

	bool *visited = calloc(target + 1, sizeof(bool));
	Node start = {0, 0};
	visited[0] = true;
	enqueue(&PQ, start);

	while (PQ.size > 0) {
		Node current = dequeue(&PQ);

		if (current.current_value == target) {
			free(visited);
			free_queue(&PQ);
			return current.num_bills;
		}

		for (int i = 0; i < n; i++) {
			int next_value = current.current_value + money[i];
			if (next_value <= target && visited[next_value] == false) {
				visited[next_value] = true;
				Node next = {next_value, current.num_bills + 1};
				enqueue(&PQ, next);
			}
		}
	}

	free(visited);
	free_queue(&PQ);
	return -1;
}
