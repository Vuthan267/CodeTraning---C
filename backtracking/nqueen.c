//
// Created by toingubo on 8/29/26.
//

#include "nqueen.h"

#include <stdlib.h>

// Unoptimized default version (print too)
bool isValidQueen(int n, bool board[n][n], int r, int c) {
	for (int i = r - 1; i >= 0; i--) {
		if (board[i][c]) {
			return false;
		}
	}

	for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
		if (board[i][j]) {
			return false;
		}
	}

	for (int i = r - 1, j = c + 1; i >= 0 && j < n; i--, j++) {
		if (board[i][j]) {
			return false;
		}
	}

	return true;
}

void nQueensRec1(int n, bool board[n][n], int row) {
	if (row == n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d ", board[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		return;
	}

	for (int i = 0; i < n; i++) {
		if (isValidQueen(n, board, row, i)) {
			board[row][i] = true;
			nQueensRec1(n, board, row + 1);
			board[row][i] = false;
		}
	}
}

void solveNQueens(int n) {
	bool board[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			board[i][j] = false;
		}
	}

	nQueensRec1(n, board, 0);
}

// Count number of combinations only, optimized check by using 3 arrays
void nQueensRec2(int n, int row, bool cols[], bool diag_l[], bool diag_r[], long long *sum) {
	if (row == n) {
		(*sum)++;
		return;
	}

	for (int c = 0; c < n; c++) {
		int d1 = row - c + n - 1;
		int d2 = row + c;
		if (!cols[c] && !diag_l[d1] && !diag_r[d2]) {
			cols[c] = true;
			diag_l[d1] = true;
			diag_r[d2] = true;

			nQueensRec2(n, row + 1, cols, diag_l, diag_r, sum);

			cols[c] = false;
			diag_l[d1] = false;
			diag_r[d2] = false;
		}
	}
}

long long solveNQueens2(int n) {
	bool *cols = (bool *) calloc(n, sizeof(bool));
	bool *diag_l = (bool *) calloc(2 * n, sizeof(bool));
	bool *diag_r = (bool *) calloc(2 * n, sizeof(bool));

	long long sum = 0;
	nQueensRec2(n, 0, cols, diag_l, diag_r, &sum);

	free(cols);
	free(diag_l);
	free(diag_r);

	return sum;
}

// Even more optimized version, with bitmasking
void nQueensRec3(int n, int row, int cols, int diag_l, int diag_r, long long *sum) {
	if (row == n) {
		(*sum)++;
		return;
	}

	int available_positions = ((1 << n) - 1) & ~(cols | diag_l | diag_r);

	while (available_positions > 0) {
		int p = available_positions & -available_positions;

		available_positions -= p;

		nQueensRec3(n, row + 1, cols | p, (diag_l | p) << 1, (diag_r | p) >> 1, sum);
	}
}

long long solveNQueens3(int n) {
	long long sum = 0;
	nQueensRec3(n, 0, 0, 0, 0, &sum);
	return sum;
}
