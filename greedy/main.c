#include <stdio.h>

#include "atm.h"
#include "fracknap.h"
#include "tsp.h"

int main() {
	int n = 5;
	int cost[][5] = {
		{0,  2,  9, 10,  7},
		{2,  0,  6,  4,  3},
		{9,  6,  0,  8,  5},
		{10, 4,  8,  0,  6},
		{7,  3,  5,  6,  0}
	};

	solveTSP(n, cost);
	return 0;
}
