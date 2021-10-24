#ifndef __triangle__
#define __triangle__

//------------------------------------------------------------------------------
// triangle.h - содержит описание треугольника
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

#include "rnd.h"
#include "color.h"
#include "utils.h"
#include "shape.h"

//------------------------------------------------------------------------------
// треугольник
class triangle : public shape {
private:
    double calculateArea() {
        double a = Length(x, y, x1, y1);
        double b = Length(x, y, x2, y2);
        double c = Length(x1, y1, x2, y2);
        double p = (a + b + c) / 2;

        return sqrt(p * (p - a) * (p - b) * (p - c)); //формула герона
    }
public:
    int x, y, x1, y1, x2, y2; // координаты точек
    color col; // цвет

    triangle(int x_, int y_, int x1_, int y1_, int x2_, int y2_, color col_) : x(x_), y(y_), x1(x1_), y1(y1_), x2(x2_), y2(y2_), col(col_) {
        area = calculateArea();
        type = "triangle";
    }

    std::string toString() {
        return string("It is Triangle:  x = ")
            + "(" + std::to_string(x) + ", " + std::to_string(y) + ") x_1 = "
            + "(" + std::to_string(x1) + ", " + std::to_string(y1) + ") x_2 = "
            + "(" + std::to_string(x2) + ", " + std::to_string(y2) + ")"
            + ". Area = " + std::to_string(area) + ""
            + ". Color = " + getColor(col) + "\n";
    }
};


#endif //__triangle__
