//
// Created by toingubo on 9/5/26.
//

#include "tsp_aaa.h"

int solve_tsp_greedy(int n, int cost[n][n]) {
    bool *visited = calloc(n, sizeof(bool));
    visited[0] = true;

    int current_city = 0;
    int total_cost = 0;

    for (int count = 1; count < n; count++) {
        int next = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] &&
                (next == -1 || cost[current_city][i] < cost[current_city][next])) {
                next = i;
            }
        }

        total_cost += cost[current_city][next];
        visited[next] = true;
        current_city = next;
    }

    total_cost += cost[current_city][0];

    free(visited);
    return total_cost;
}

int cal_bound_tsp(int n, int cost[n][n], TSPNode node) {
    //// Current to unvisited
    int min_current = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (node.visited[i] == true) {
            continue;
        }
        if (cost[node.current_city][i] < min_current) {
            min_current = cost[node.current_city][i];
        }
    }

    //// MST unvisited
    bool mst[n];
    int min_edge[n];
    for (int i = 0; i < n; i++) {
        mst[i] = false;
        min_edge[i] = INT_MAX;
    }

    // Choose 1st city
    int start = -1;
    for (int i = 0; i < n; i++) {
        if (node.visited[i]) {
            continue;
        }

        start = i;
        break;
    }

    mst[start] = true;
    min_edge[start] = 0;

    // Initialize min_edge[i] to starting city
    for (int i = 0; i < n; i++) {
        if (node.visited[i] || mst[i]) {
            continue;
        }

        min_edge[i] = cost[start][i];
    }

    // Count unvisited city
    int remaining = 0;
    for (int i = 0; i < n; i++) {
        if (!node.visited[i]) {
            remaining++;
        }
    }

    /*
     * Iterate over the remaining unvisited cities, minus 1 (we chose one starting city already)
     * Each iteration, we expand the mst by one
     */
    int mst_cost = 0;
    for (int count = 1; count < remaining; count++) {
        // Add the vertex with the lowest cost into mst
        int next = -1;
        int shortest = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (node.visited[i] || mst[i]) {
                continue;
            }

            if (min_edge[i] < shortest) {
                shortest = min_edge[i];
                next = i;
            }
        }

        mst[next] = true;
        mst_cost += shortest;

        // Recaculate shortest path from unvisited, not mst cities to the newly added one
        for (int i = 0; i < n; i++) {
            if (node.visited[i] || mst[i]) {
                continue;
            }

            if (cost[next][i] < min_edge[i]) {
                min_edge[i] = cost[next][i];
            }
        }
    }

    //// Unvisited to 0
    int min_return = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (node.visited[i] == true) {
            continue;
        }

        if (cost[i][0] < min_return) {
            min_return = cost[i][0];
        }
    }

    return node.total_cost + min_current + mst_cost + min_return;
}

int solve_tsp_bnb(int n, int cost[n][n]) {
    MinHeap pq;
    init(&pq);

    TSPNode head;
    head.total_cost = 0;
    head.current_city = 0;
    head.level = 1;
    head.visited = calloc(n, sizeof(bool));
    head.visited[0] = true;
    head.bound = cal_bound_tsp(n, cost, head);
    push(&pq, head);

    while (pq.last != 0) {
        TSPNode current = pop(&pq);
        if (current.level == n) {
            free(current.visited);
            free_heap(&pq);
            return current.total_cost + cost[current.current_city][0];
        }

        for (int i = 1; i < n; i++) {
            if (current.visited[i] == true) {
                continue;
            }

            TSPNode next = current;
            next.total_cost += cost[current.current_city][i];
            next.current_city = i;

            next.visited = calloc(n, sizeof(bool));
            memcpy(next.visited, current.visited, n * sizeof(bool));
            next.visited[i] = true;

            next.level++;
            next.bound = cal_bound_tsp(n, cost, next);

            push(&pq, next);
        }
        free(current.visited);
    }

    return -1;
}
