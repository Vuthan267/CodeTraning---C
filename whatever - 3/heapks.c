//
// Created by toingubo on 9/5/26.
//

#include "heapks.h"

void swap_node(KnapNode *a, KnapNode *b) {
    KnapNode temp = *a;
    *a = *b;
    *b = temp;
}

void init(MaxHeap *heap) {
    heap->elements = (KnapNode*)malloc(1 * sizeof(KnapNode));
    heap->last = 0;
    heap->size = 1;
}

void push(MaxHeap *heap, KnapNode node) {
    if (heap->last == heap->size) {
        heap->size *= 2;
        heap->elements = realloc(heap->elements, heap->size * sizeof(KnapNode));
    }

    int i = heap->last;
    heap->elements[heap->last] = node;
    heap->last++;

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (heap->elements[parent].bound > heap->elements[i].bound) {
            break;
        }

        swap_node(&heap->elements[parent], &heap->elements[i]);
        i = parent;
    }
}

KnapNode pop(MaxHeap *heap) {
    KnapNode result = heap->elements[0];
    heap->last--;
    heap->elements[0] = heap->elements[heap->last];

    int i = 0;
    while (2 * i + 1 < heap->last) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < heap->last && heap->elements[left].bound > heap->elements[largest].bound) {
            largest = left;
        }
        if (right < heap->last && heap->elements[right].bound > heap->elements[largest].bound) {
            largest = right;
        }

        if (largest == i) {
            break;
        }

        swap_node(&heap->elements[i], &heap->elements[largest]);
        i = largest;
    }

    return result;
}

void free_heap(MaxHeap *heap) {
    free(heap->elements);
}
