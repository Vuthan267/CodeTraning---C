//
// Created by toingubo on 8/26/26.
//

#ifndef C_FRACKNAP_H
#define C_FRACKNAP_H
#include <stdlib.h>

int compareKnap(const void *a, const void *b);

double doKnapRec(float items[][2], int n, int index, int current_capacity);

double findHighestFracKnap(int val[], int wt[], int n, int capacity);

#endif //C_FRACKNAP_H
