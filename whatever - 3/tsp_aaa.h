//
// Created by toingubo on 9/5/26.
//

#ifndef C_TSP_AAA_H
#define C_TSP_AAA_H
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "heaptsp.h"

int solve_tsp_greedy(int n, int cost[n][n]);

int cal_bound_tsp(int n, int cost[n][n], TSPNode node);

int solve_tsp_bnb(int n, int cost[n][n]);

#endif //C_TSP_AAA_H
