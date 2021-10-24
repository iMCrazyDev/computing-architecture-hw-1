#ifndef __rectangle__
#define __rectangle__

//------------------------------------------------------------------------------
// rectangle.h - содержит описание прямоугольника  и его интерфейса
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

#include "rnd.h"
#include "color.h"
#include "utils.h"
#include "shape.h"

// прямоугольник
class rectangle : public shape {

private:
    double calculateArea() {
        return Length(x, y, x, y1) * Length(x, y, x1, y);
    }
public:
    std::string toString() {
        return string("It is Rectangle: x = (") + std::to_string(x) + ", " + std::to_string(y) + ") "
            + "x_1 = (" + std::to_string(x1) + ", " + std::to_string(y1) + ")"
            + ". Area = " + std::to_string(area)
            + ". Color = " + getColor(col) + "\n";
    }

    int x, y, x1, y1; // левый верхний и правый нижний соответственно
    color col; // цвет

    rectangle(int x_, int y_, int x1_, int y1_, color col_) : x(x_), y(y_), x1(x1_), y1(y1_), col(col_) {
        area = calculateArea();
        type = "rectangle";
    }
};


#endif //__rectangle__
