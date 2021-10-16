#pragma once
#include "math.h"

inline double Length(int x, int y, int x1, int y1) {
	return sqrt(pow(x - x1, 2) + pow(y - y1, 2));
}
