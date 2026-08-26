//
// Created by toingubo on 8/25/26.
//

#include "closest2points.h"

#include <float.h>
#include <stdlib.h>
#include <math.h>

int compareX(const void *a, const void *b) {
    double x1 = ((Point*)a)->x;
    double x2 = ((Point*)b)->x;
    return (x1 > x2) - (x1 < x2);
}

int compareY(const void *a, const void *b) {
    double y1 = ((Point*)a)->y;
    double y2 = ((Point*)b)->y;
    return (y1 > y2) - (y1 < y2);
}

double dist(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double bruteDist(Point arr[], int low, int high) {
    if (low == high) return DBL_MAX;
    return dist(arr[low], arr[high]);
}

double stripClosest(Point strip[], int size, double minSides) {
    double minClosest = minSides;
    qsort(strip, size, sizeof(Point), compareY);

    for (int i = 0; i < size; i++)
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y < minClosest); j++)
            if (dist(strip[i], strip[j]) < minClosest)
                minClosest = dist(strip[i], strip[j]);

    return minClosest;
}

double closestSolve(Point arr[], int low, int high) {
    if (high - low <= 1) return bruteDist(arr, low, high);

    int mid = low + (high - low) / 2;
    double minDistLeft = closestSolve(arr, low, mid);
    double minDistRight = closestSolve(arr, mid + 1, high);
    double minSides = fmin(minDistLeft, minDistRight);
    Point midPoint = arr[mid];

    Point strip[high+1];
    int j = 0;
    for (int i = 0; i < high+1; i++)
        if (fabs(arr[i].x - midPoint.x) < minSides)
            strip[j++] = arr[i];

    return fmin(stripClosest(strip, j, minSides), minSides);
}

double closest(Point arr[], int low, int high) {
    qsort(arr, high + 1, sizeof(Point), compareX);
    return closestSolve(arr, low, high);
}
