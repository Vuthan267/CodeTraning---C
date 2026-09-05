//
// Created by toingubo on 9/5/26.
//

#ifndef C_KNAPSACKKK_H
#define C_KNAPSACKKK_H
#include <stdlib.h>

#include "heapks.h"

int compare_knapsack(const void *a, const void *b);

float solve_frac_knapsack(int val[], int wt[], int n, int capacity);

int max_knapp(int a, int b);

int solve_bin_knapsack(int val[], int wt[], int n, int capacity);

float cal_bound_knap(int n, float items[n][2], KnapNode current);

int solve_bin_knapsack_bnb(int val[], int wt[], int n, int capacity);

#endif //C_KNAPSACKKK_H
