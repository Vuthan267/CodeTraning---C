//
// Created by toingubo on 8/30/26.
//

#include <stdio.h>

int main() {
	int a[] = {20, 10, 5, 1};
	int n = 4;
	int target = 37;

	BnB(a, n, target, 0, 0);

	if (best == 1000000)
		printf("Khong the tao target\n");
	else
		printf("So to it nhat: %d\n", best);

	return 0;
}