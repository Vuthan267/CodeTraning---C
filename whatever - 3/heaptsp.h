//
// Created by toingubo on 9/5/26.
//

#ifndef C_HEAPTSP_H
#define C_HEAPTSP_H
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int total_cost;
    int current_city;
    int level;
    bool *visited;
    int bound;
} TSPNode;

typedef struct {
    TSPNode *elements;
    int last;
    int size;
} MinHeap;

void swap_node(TSPNode *a, TSPNode *b);
void init(MinHeap *heap);
void push(MinHeap *heap, TSPNode node);
TSPNode pop(MinHeap *heap);
void free_heap(MinHeap *heap);

#endif //C_HEAPTSP_H
