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
	// Input parameters
	int W = 100; // Knapsack capacity
	int n = 4;   // Number of items
	int wt[] = {5, 10, 15, 20};       // Weights of items
	int val[] = {10, 30, 20, 50};     // Values of items

	int max_val = solveUnboundedKnap(val, wt, n, W);

	printf("Maximum value in Knapsack = %d\n", max_val);
	printf("Expected Result = 300\n");

	return 0;
}
