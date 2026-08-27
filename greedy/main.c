#include <stdio.h>

#include "atm.h"
#include "fracknap.h"
#include "tsp.h"
#include "cookie.h"
#include "stock.h"
#include "activity.h"
#include "jump.h"
#include "jobsequencing.h"

int main() {
	int deadline[] = {4,1,1,1};
	int profit[] = {20,10,40,30};
	int n = 4;
	int *res = findMaxProfit(deadline, profit, n);
	printf("{%d, %d}", res[0], res[1]);

	return 0;
}
