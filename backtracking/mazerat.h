//
// Created by toingubo on 8/29/26.
//

#ifndef C_MAZERAT_H
#define C_MAZERAT_H
#include <stdbool.h>
#include <stdio.h>

bool isValidPath(int n, int m, int maze[n][m], int next_row, int next_column);

void solveRat(int n, int m, int maze[n][m], int current_row, int current_column, char path[], int pathSize);

void findPathRatMaze(int n, int m, int maze[n][m]);

#endif //C_MAZERAT_H
