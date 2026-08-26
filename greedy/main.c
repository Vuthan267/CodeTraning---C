#include <stdio.h>

#include "atm.h"
#include "fracknap.h"
#include "tsp.h"
#include "cookie.h"
#include "stock.h"

int main() {
	int n = 5;
	int price[] = {10, 8, 6, 4, 2};
	int money = 30;

	printf("%d", findMaxStock(price, n, money));
	return 0;
}
