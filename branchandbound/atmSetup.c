//
// Created by toingubo on 8/30/26.
//

#include <stdio.h>
#include <stdlib.h>

#include "atm.h"

void initQueue(PriorityQueue *PQ, int capacity) {
	PQ->capacity = capacity;
	PQ->size = 0;
	PQ->elements = calloc(capacity, sizeof(Node));
}

void swapPQ(Node *a, Node *b) {
	Node temp = *a;
	*a = *b;
	*b = temp;
}

void enqueue(PriorityQueue *PQ, Node new) {
	if (PQ->size == PQ->capacity) {
		Node *temp = realloc(PQ->elements, PQ->capacity * 2 * sizeof(Node));
		if (temp == NULL) {
			printf("ERROR, ABORTING...");
			return;
		}
		PQ->elements = temp;
		PQ->capacity *= 2;
	}

	PQ->elements[PQ->size] = new;
	int current = PQ->size;

	while (current > 0) {
		int parent = (current - 1) / 2;
		if (PQ->elements[current].num_bills < PQ->elements[parent].num_bills) {
			swapPQ(&(PQ->elements[current]), &(PQ->elements[parent]));
			current = parent;
		} else {
			break;
		}
	}

	(PQ->size)++;
}

Node dequeue(PriorityQueue *PQ) {
	if (PQ->size == 0) {
		Node empty;
		return empty;
	}

	Node min_node = PQ->elements[0];

	PQ->elements[0] = PQ->elements[PQ->size - 1];
	(PQ->size)--;

	int current = 0;

	while (((2 * current) + 1) < PQ->size) {
		int left = 2 * current + 1;
		int right = 2 * current + 2;
		int smallest = current;

		if (PQ->elements[left].num_bills < PQ->elements[smallest].num_bills) {
			smallest = left;
		}

		if ((right < PQ->size) && (PQ->elements[right].num_bills < PQ->elements[smallest].num_bills)) {
			smallest = right;
		}

		if (smallest != current) {
			swapPQ(&PQ->elements[current], &PQ->elements[smallest]);
			current = smallest;
		} else {
			break;
		}
	}

	return min_node;
}

void free_queue(PriorityQueue *PQ) {
	free(PQ->elements);
	PQ->elements = NULL;
}