#include <stdio.h>

#include  "permutationstring.h"
#include "subsetsum.h"
#include "mazerat.h"
#include "nqueen.h"

int main() {
	int n = 16;
	printf("%lld", solveNQueens2(n));

	return 0;
}
