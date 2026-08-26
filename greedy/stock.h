//
// Created by toingubo on 8/26/26.
//

#ifndef C_STOCK_H
#define C_STOCK_H
#include <stdlib.h>

typedef struct {
	int price;
	int max_amount;
} Stock;

int compareStock(const void *a, const void *b);

int findMaxStock(int price[], int n, int money);

#endif //C_STOCK_H
