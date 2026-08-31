//
// Created by toingubo on 8/31/26.
//

#ifndef C_TSPBNB_H
#define C_TSPBNB_H
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
	int current_city;
	int level;
	int total_cost;
	int visited;
	int bound;
} TSP_Node;

void precalculateRowMinimums(int n, int cost[n][n]);

void printTSPNode(int n, TSP_Node node, int best);

int calTSPBound(int n, int cost[n][n], TSP_Node current);

void tspRec(int n, int cost[n][n], TSP_Node current, int *best);

int solveTSPBnB(int n, int cost[n][n]);

#endif //C_TSPBNB_H
