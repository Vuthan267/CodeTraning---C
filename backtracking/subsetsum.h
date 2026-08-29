//
// Created by toingubo on 8/29/26.
//

#ifndef C_SUBSETSUM_H
#define C_SUBSETSUM_H
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void subsetSumRec(int set[], int n, int sum, int i, int res[], int resSize);

void findSubsetSum(int set[], int n, int sum);

#endif //C_SUBSETSUM_H
