//
// Created by toingubo on 8/29/26.
//

#ifndef C_NQUEEN_H
#define C_NQUEEN_H
#include <stdbool.h>
#include <stdio.h>

bool isValidQueen(int n, bool board[n][n], int r, int c);

void nQueensRec1(int n, bool board[n][n], int row);

void solveNQueens(int n);

void nQueensRec2(int n, int row, bool cols[], bool diag_l[], bool diag_r[], long long *sum);

long long solveNQueens2(int n);

void nQueensRec3(int n, int row, int cols, int diag_l, int diag_r, long long *sum);

long long solveNQueens3(int n);

#endif //C_NQUEEN_H
