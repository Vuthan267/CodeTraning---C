//
// Created by toingubo on 8/30/26.
//

#ifndef C_ATM_H
#define C_ATM_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Structures
typedef struct {
	int current_value;
	int num_bills;
} Node;

typedef struct {
	Node *elements;
	int capacity;
	int size;
} PriorityQueue;


// Priority Queue
void initQueue(PriorityQueue *PQ, int capacity);

void swapPQ(Node *a, Node *b);

void enqueue(PriorityQueue *PQ, Node new_node);

Node dequeue(PriorityQueue *PQ);

void free_queue(PriorityQueue *PQ);

// ATM
int findLeastBillATM(int money[], int n, int target);

#endif //C_ATM_H
