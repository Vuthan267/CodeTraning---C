//
// Created by toingubo on 8/31/26.
//

#ifndef C_KNAPBNB_H
#define C_KNAPBNB_H
#include <limits.h>
#include <stdlib.h>

int compareKnapBnB(const void *a, const void *b);

float calBound(float items[][2], int n, int index, int current_capacity, int current_value);

void knapBnBRec(float items[][2], int n, int index, int current_capacity, int current_value, int *best_value);

int solveKnapsackBnB(int val[], int wt[], int n, int capacity);

#endif //C_KNAPBNB_H
