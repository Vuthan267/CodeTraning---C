//
// Created by toingubo on 8/29/26.
//

#ifndef C_ALLSUBSET_H
#define C_ALLSUBSET_H
#include <stdio.h>
#include <stdlib.h>

void subsetRec(int set[], int n, int i, int subset[], int subsetSize);

void printAllSubset(int set[], int n);

void subsetRec2(int set[], int n, int i, int bit);

void printAllSubset2(int set[], int n);

#endif //C_ALLSUBSET_H
