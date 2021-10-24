#pragma once
#include "math.h"
#include <sstream>

inline double Length(int x, int y, int x1, int y1) {
	return sqrt(pow(x - x1, 2) + pow(y - y1, 2));
}

double calculateTriangleArea(int x, int y, int x1, int y1, int x2, int y2) {
    double a = Length(x, y, x1, y1);
    double b = Length(x, y, x2, y2);
    double c = Length(x1, y1, x2, y2);
    double p = (a + b + c) / 2;

    return sqrt(p * (p - a) * (p - b) * (p - c)); 
}
