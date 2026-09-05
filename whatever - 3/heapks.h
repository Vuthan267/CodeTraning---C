//
// Created by toingubo on 9/5/26.
//

#ifndef C_HEAPKS_H
#define C_HEAPKS_H
#include <stdlib.h>

typedef struct {
    int total_value;
    int remaining_weight;
    int level;
    float bound;
} KnapNode;

typedef struct {
    KnapNode *elements;
    int last;
    int size;
} MaxHeap;

void swap_node(KnapNode *a, KnapNode *b);
void init(MaxHeap *heap);
void push(MaxHeap *heap, KnapNode node);
KnapNode pop(MaxHeap *heap);
void free_heap(MaxHeap *heap);


#endif //C_HEAPKS_H
