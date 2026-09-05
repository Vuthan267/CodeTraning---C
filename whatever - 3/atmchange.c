//
// Created by toingubo on 9/5/26.
//

#include "atmchange.h"

int compare_atm(const void* a, const void* b) {
    return (*(int*)b) - (*(int*)a);
}

int solve_atm_aaa(int money[], int n, int sum) {
    qsort(money, n, sizeof(int), compare_atm);

    int total_amount = 0;
    for (int i = 0; i < n; i++) {
        int curr_amount = sum / money[i];
        sum -= curr_amount * money[i];
        total_amount += curr_amount;
    }

    if (sum != 0) {
        return -1;
    }

    return total_amount;
}
