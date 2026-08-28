#include <stdio.h>

#include  "rodcutting.h"
#include "fibonacci.h"
#include  "climbstairs.h"
#include "coinchange.h"
#include "mincostpath.h"
#include "decode.h"
#include "knapsackdynamic.h"

int main() {
	int val[] = {1, 2, 3};
	int wt[] = {4, 5, 1};
	int n = 3;
	int capacity = 4;
	printf("%d", solveBinKnap(val, wt, n, 4));

	return 0;
}
