//
// Created by toingubo on 8/30/26.
//

#ifndef C_COMBINATIONALSUM_H
#define C_COMBINATIONALSUM_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void combineSumRec(int num[], int n, int target, int i, int subset[], int subsetSize);

void printCombineSum(int num[], int n, int target);

#endif //C_COMBINATIONALSUM_H
