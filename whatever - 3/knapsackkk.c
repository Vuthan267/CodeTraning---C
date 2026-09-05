//
// Created by toingubo on 9/5/26.
//

#include "knapsackkk.h"

// Fractional Knapsack
int compare_knapsack(const void* a, const void* b) {
    int ratio_a = (*(float*)a) / (*((float*)a + 1));
    int ratio_b = (*(float*)b) / (*((float*)b + 1));
    return ratio_b - ratio_a;
}

float solve_frac_knapsack(int val[], int wt[], int n, int capacity) {
    float items[n][2];
    for (int i = 0; i < n; i++) {
        items[i][0] = val[i];
        items[i][1] = wt[i];
    }
    qsort(items, n, sizeof(float[2]), compare_knapsack);

    float total_value = 0;
    for (int i = 0; i < n; i++) {
        int curr_value = items[i][0];
        int curr_weight = items[i][1];

        if (curr_weight <= capacity) {
            total_value += curr_value;
            capacity -= curr_weight;
        } else {
            total_value += ((float) curr_value / curr_weight) * capacity;
            return total_value;
        }
    }

    return total_value;
}

// 0/1 Knapsack DP
int max_knapp(int a, int b) {
    return (a > b) ? a : b;
}

int solve_bin_knapsack(int val[], int wt[], int n, int capacity) {
    int dp[capacity + 1];
    for (int i = 0; i <= capacity; i++) {
        dp[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int curr_value = val[i];
        int curr_weight = wt[i];
        for (int j = capacity; j >= curr_weight; j--) {
            dp[j] = max_knapp(dp[j], dp[j - curr_weight] + curr_value);
        }
    }

    return dp[capacity];
}

// 0/1 Knapsack BnB
float cal_bound_knap(int n, float items[n][2], KnapNode current) {
    float bound = current.total_value;
    int remaining_weight = current.remaining_weight;

    for (int i = current.level; i < n; i++) {
        if (items[i][1] <= remaining_weight) {
            bound += items[i][0];
            remaining_weight -= items[i][1];
        } else {
            bound += (items[i][0] / items[i][1]) * remaining_weight;
            break;
        }
    }
    return bound;
}

int solve_bin_knapsack_bnb(int val[], int wt[], int n, int capacity) {
    float items[n][2];
    for (int i = 0; i < n; i++) {
        items[i][0] = val[i];
        items[i][1]= wt[i];
    }
    qsort(items, n, sizeof(float[2]), compare_knapsack);

    MaxHeap pq;
    init(&pq);

    KnapNode head;
    head.total_value = 0;
    head.remaining_weight = capacity;
    head.level = 0;
    head.bound = cal_bound_knap(n, items, head);

    push(&pq, head);

    while (pq.last != 0) {
        KnapNode current = pop(&pq);
        if (current.level == n) {
            free_heap(&pq);
            return current.total_value;
        }

        int current_value = items[current.level][0];
        int current_weight = items[current.level][1];

        if (current_weight <= current.remaining_weight) {
            KnapNode take = current;
            take.total_value += current_value;
            take.remaining_weight -= current_weight;
            take.level++;
            take.bound = cal_bound_knap(n, items, take);
            push(&pq, take);
        }

        KnapNode not_take = current;
        not_take.level++;
        not_take.bound = cal_bound_knap(n, items, not_take);
        push(&pq, not_take);
    }

    free_heap(&pq);
    return -1;
}


