//
// Created by toingubo on 8/30/26.
//

#include <stdio.h>

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "atm.h"

// Global variable to keep track of the upper bound (best solution found so far)
// We initialize it to a massive number representing infinity
int best_num_bills = 1e9;

// Internal recursive function for DFS Branch and Bound
void dfs_bnb_helper(int current_value, int current_bills, int money[], int n, int target) {
	// 1. BOUNDING / PRUNING STEP:
	// If the number of bills we've used *so far* is already equal to or worse
	// than the best solution we've already found elsewhere, cut this branch immediately!
	if (current_bills >= best_num_bills) {
		return;
	}

	// 2. BASE CASES:
	if (current_value == target) {
		// We found a valid solution that beats our old record! Update the upper bound.
		best_num_bills = current_bills;
		return;
	}
	if (current_value > target) {
		return; // Overshot the target, dead end
	}

	// 3. BRANCHING STEP:
	// Explore children deeply.
	// TIP: Sorting bills from largest to smallest makes DFS BnB find a good bound much faster!
	for (int i = 0; i < n; i++) {
		dfs_bnb_helper(current_value + money[i], current_bills + 1, money, n, target);
	}
}

// Wrapper function to reset the global variable and start the search
int findLeastBillATM_DFS_BnB(int money[], int n, int target) {
	// Reset global bound for this run
	best_num_bills = 1e9;

	// Start DFS at value 0, using 0 bills
	dfs_bnb_helper(0, 0, money, n, target);

	// If best_num_bills never changed, the target is impossible
	if (best_num_bills == 1e9) {
		return -1;
	}
	return best_num_bills;
}

int main() {
	// TEST CASE: The "Greedy Trap & Combinatorial Explosion" Test
	// A greedy algorithm will instantly pick 50, then get stuck because 50 + 50 = 100 (overshoot).
	// An un-memoized BFS will generate millions of redundant paths (e.g., 9+9+9... vs 12+12+12...).
	int money[] = {9, 12, 15, 50};
	int n = sizeof(money) / sizeof(money[0]);
	int target = 9999;

	printf("Running ATM Stress Test...\n");
	printf("Target Amount: $%d\n", target);
	printf("Available Bills: ");
	for (int i = 0; i < n; i++) printf("$%d ", money[i]);
	printf("\n\n");

	// Execute your flawless function
	int result = findLeastBillATM(money, n, target);

	if (result != -1) {
		printf("✅ SUCCESS! Optimal number of bills needed: %d\n", result);
	} else {
		printf("❌ FAILURE: Target cannot be formed with these bills.\n");
	}

	return 0;
}
