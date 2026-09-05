//
// Created by toingubo on 9/4/26.
//

#ifndef C_SORTING_H
#define C_SORTING_H
#include <limits.h>

int is_sorted(int arr[], int n);

void swap(int* a, int* b);

void b_sort(int arr[], int n);

void i_sort(int arr[], int n);

void s_sort(int arr[], int n);

void merge_a(int arr[], int l, int m, int h);

void m_sort_util(int arr[], int l, int h);

void m_sort(int arr[], int n);

int partition_a(int arr[], int l, int h);

void q_sort_util(int arr[], int l, int h);

void q_sort(int arr[], int n);

void heapify_a(int arr[], int n, int i);

void h_sort(int arr[], int n);

#endif //C_SORTING_H
