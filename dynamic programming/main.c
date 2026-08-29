#include <stdio.h>

#include  "rodcutting.h"
#include "fibonacci.h"
#include  "climbstairs.h"
#include "coinchange.h"
#include "mincostpath.h"
#include "decode.h"
#include "knapsackdynamic.h"
#include "lcs.h"
#include "minpathtriangle.h"

int main() {
	int n = 4;

	// Triangle array declaration
	int triangle[4][4] = {
		{2},
		{3, 7},
		{8, 5, 6},
		{6, 1, 9, 3}
	};

	printf("%d", findMinPathTriangle2(n, triangle));

	return 0;
}
