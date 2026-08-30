//
// Created by toingubo on 8/30/26.
//

#ifndef C_HAMILTONIANCYCLE_H
#define C_HAMILTONIANCYCLE_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void hamiRec(int n, bool adj_mat[n][n], int current, int solution[], int solution_size, bool visited[]);

void printHamiCycle(int n, bool adj_mat[n][n]);

#endif //C_HAMILTONIANCYCLE_H
