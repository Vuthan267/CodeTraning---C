#include <stdio.h>

#include "atm.h"
#include "fracknap.h"
#include "tsp.h"
#include "cookie.h"
#include "stock.h"
#include "activity.h"
#include "jump.h"

int main() {
	int n = 6;
	int steps[] = {1, 4, 3, 2, 6, 7};

	printf("%d", findMinJump(steps, n));
	return 0;
}
