//
// Created by toingubo on 8/25/26.
//

#ifndef C_CLOSEST2POINT_H
#define C_CLOSEST2POINT_H

typedef struct {
    double x, y;
} Point;

int compareX(const void* a, const void* b);

int compareY(const void* a, const void* b);

double dist(Point a, Point b);

double bruteDist(Point arr[], int low, int high);

double stripClosest(Point strip[], int size, double minSides);

double closestSolve(Point arr[], int low, int high);

double closest(Point arr[], int low, int high);

#endif //C_CLOSEST2POINT_H
