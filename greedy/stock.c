//
// Created by toingubo on 8/26/26.
//

#include "stock.h"

int compareStock(const void *a, const void *b) {
	int price_a = ((Stock *) a)->price;
	int price_b = ((Stock *) b)->price;
	return (price_a > price_b) - (price_a < price_b);
}

int findMaxStock(int price[], int n, int money) {
	Stock S[n];
	for (int i = 0; i < n; i++) {
		S[i].price = price[i];
		S[i].max_amount = i + 1;
	}
	qsort(S, n, sizeof(Stock), compareStock);

	int stock_cnt = 0;

	for (int i = 0; i < n; i++) {
		Stock *currStock = &S[i];
		int amount_today = currStock->max_amount;

		while (currStock->price <= money && amount_today > 0) {
			stock_cnt++;
			amount_today--;
			money -= currStock->price;
		}
	}

	return stock_cnt;
}
