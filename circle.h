#ifndef __circle__
#define __circle__

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
// круг
class circle : public shape {
private:
    double calculateArea() {
        return r * r * 3.14159265358979323846;
    }
public:
  int x, y, r; // радиус и центр
  color col; // цвет

  circle(int x_, int y_, int r_, color col_) : x(x_), y(y_), r(r_), col(col_) {
      area = calculateArea();
      type = "circle";
  }

  std::string toString() {
      return string("It is Circle:    x = ") + "(" + std::to_string(x) + ", " + std::to_string(y) + ") r = " + std::to_string(r)
          + ". Area = " + std::to_string(area)
          + ". Color = " + getColor(col) + "\n";
  }
};

#endif //__circle__
