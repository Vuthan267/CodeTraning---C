//
// Created by toingubo on 8/30/26.
//

#include "hamiltoniancycle.h"
/*
 * Only print different cycles, not their rotated variants. Just add a "start" parameter,
 * then loop through all starting values. (change all the hardcoded 0 to "start")
 */

void hamiRec(int n, bool adj_mat[n][n], int current, int solution[], int solution_size, bool visited[]) {
	if (solution_size == n) {
		if (adj_mat[current][0] == true) {
			solution[solution_size] = 0;
			for (int i = 0; i <= solution_size; i++) {
				printf("%d ", solution[i]);
			}
			printf("\n");
		}
		return;
	}

	for (int next = 0; next < n; next++) {
		if (adj_mat[current][next] == true && visited[next] == false) {
			solution[solution_size] = next;
			visited[next] = true;
			hamiRec(n, adj_mat, next, solution, solution_size + 1, visited);

			visited[next] = false;
		}
	}
}

void printHamiCycle(int n, bool adj_mat[n][n]) {
	int *solution = (int *) calloc(n + 1, sizeof(int));
	bool *visited = (bool *) calloc(n, sizeof(bool));

	solution[0] = 0;
	visited[0] = true;
	hamiRec(n,
	        adj_mat,
	        0,
	        solution,
	        1,
	        visited);

	free(solution);
	free(visited);
}
