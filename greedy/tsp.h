//
// Created by toingubo on 8/26/26.
//

#ifndef C_TSP_H
#define C_TSP_H
#include <limits.h>
#include <stdio.h>

int findMinCostIndex(int n, int cost[n][n], int current_city, int passed[]);

void solveTSP(int n, int cost[n][n]);

#endif //C_TSP_H
