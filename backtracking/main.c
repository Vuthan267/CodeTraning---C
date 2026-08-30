#include <stdio.h>

#include  "permutationstring.h"
#include "subsetsum.h"
#include "mazerat.h"
#include "nqueen.h"
#include  "allsubset.h"
#include "combinationalsum.h"
#include "hamiltoniancycle.h"

int main() {
	bool adjMat[5][5] = {{0, 1, 0, 1, 0}, {1, 0, 1, 1, 1}, {0, 1, 0, 0, 1}, {1, 1, 0, 0, 1}, {0, 1, 1, 1, 0}};
	printHamiCycle(5, adjMat);

	return 0;
}
