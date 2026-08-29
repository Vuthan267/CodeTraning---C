//
// Created by toingubo on 8/29/26.
//

#include "mazerat.h"

bool isValidPath(int n, int m, int maze[n][m], int next_row, int next_column) {
	return (next_row >= 0 && next_row < n
	        && next_column >= 0 && next_column < m
	        && maze[next_row][next_column] == 1)
		       ? true
		       : false;
}

void solveRat(int n, int m, int maze[n][m], int current_row, int current_column, char path[], int pathSize) {
	if (current_row == n - 1 && current_column == m - 1) {
		for (int i = 0; i < pathSize; i++) {
			printf("%c ", path[i]);
			if (i != pathSize - 1) {
				printf("-> ");
			}
		}
		printf("\n");
		return;
	}

	int dR[] = {-1, 1, 0, 0};
	int dC[] = {0, 0, -1, 1};
	char dir[] = {'U', 'D', 'L', 'R'};

	maze[current_row][current_column] = 0;

	for (int i = 0; i < 4; i++) {
		int next_row = current_row + dR[i];
		int next_column = current_column + dC[i];
		if (isValidPath(n, m, maze, next_row, next_column)) {
			path[pathSize] = dir[i];
			solveRat(n, m, maze, next_row, next_column, path, pathSize + 1);
		}
	}

	maze[current_row][current_column] = 1;
}

void findPathRatMaze(int n, int m, int maze[n][m]) {
	char path[100];
	solveRat(n, m, maze, 0, 0, path, 0);
}
