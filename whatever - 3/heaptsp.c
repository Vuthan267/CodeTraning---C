//
// Created by toingubo on 9/5/26.
//

#include "heaptsp.h"

void swap_node(TSPNode *a, TSPNode *b) {
    TSPNode temp = *a;
    *a = *b;
    *b = temp;
}

void init(MinHeap *heap) {
    heap->elements = (TSPNode*)malloc(1 * sizeof(TSPNode));
    heap->last = 0;
    heap->size = 1;
}

void push(MinHeap *heap, TSPNode node) {
    if (heap->last == heap->size) {
        heap->size *= 2;
        heap->elements = realloc(heap->elements, heap->size * sizeof(TSPNode));
    }

    int i = heap->last;
    heap->elements[heap->last] = node;
    heap->last++;

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (heap->elements[parent].bound < heap->elements[i].bound) {
            break;
        }

        swap_node(&heap->elements[parent], &heap->elements[i]);
        i = parent;
    }
}

TSPNode pop(MinHeap *heap) {
    TSPNode result = heap->elements[0];
    heap->last--;
    heap->elements[0] = heap->elements[heap->last];

    int i = 0;
    while (2 * i + 1 < heap->last) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < heap->last && heap->elements[left].bound < heap->elements[smallest].bound) {
            smallest = left;
        }
        if (right < heap->last && heap->elements[right].bound < heap->elements[smallest].bound) {
            smallest = right;
        }

        if (smallest == i) {
            break;
        }

        swap_node(&heap->elements[i], &heap->elements[smallest]);
        i = smallest;
    }

    return result;
}

void free_heap(MinHeap *heap) {
    for (int i = 0; i < heap->last; i++) {
        free(heap->elements[i].visited);
    }

    free(heap->elements);
}
