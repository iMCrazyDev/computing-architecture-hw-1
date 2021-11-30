#pragma once
#include "math.h"

extern "C"
{
    double calculateLength(int x, int y, int x1, int y1);
}

double Length(int x, int y, int x1, int y1) {
	return calculateLength(x, y, x1, y1); //sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1)); //
}
