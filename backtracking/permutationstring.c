//
// Created by toingubo on 8/29/26.
//

#include "permutationstring.h"

void swapChar(char *a, char *b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}

void printPermutation(char st[], int n, int i) {
	if (i == n - 1) {
		printf("%s\n", st);
		return;
	}

	for (int j = i; j < n; j++) {
		swapChar(&st[i], &st[j]);
		printPermutation(st, n, i + 1);
		swapChar(&st[i], &st[j]);
	}
}
