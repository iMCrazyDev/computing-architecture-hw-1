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
struct rectangle {
    int x, y, x1, y1; // левый верхний и правый нижний соответственно
    color col; // цвет
};

// Ввод параметров прямоугольника из файла
void In(rectangle &r, ifstream &ifst);

// Случайный ввод параметров прямоугольника
void InRnd(rectangle &r);

// Вывод параметров прямоугольника в форматируемый поток
void Out(rectangle &r, ofstream &ofst);

// Вычисление периметра прямоугольника
double Area(rectangle &r);

color GetColor(rectangle& r);


//------------------------------------------------------------------------------
// Ввод параметров прямоугольника из файла
void In(rectangle &r, ifstream &ifst) {
    int color_code;
    ifst >> r.x >> r.y >> r.x1 >> r.y1 >> color_code;
    r.col = colors[color_code];
}

// Случайный ввод параметров прямоугольника
void InRnd(rectangle &r) {
    r.x = Random();
    r.y = Random();
    r.x1 = Random();
    do {
        r.y1 = Random();
    } while (r.y == r.y1);
    r.col = colors[Random() % 7];
}

//------------------------------------------------------------------------------
// Вывод параметров прямоугольника в форматируемый поток
void Out(rectangle &r, std::ofstream &ofst) {
    ofst << "It is Rectangle: x = (" << r.x << ", " << r.y << ") "
         << "x_1 = (" << r.x1 << ", " << r.y1 << ")"
         << ". Area = " << Area(r)
         << ". Color = " << GetColor(r) << "\n";
}

//------------------------------------------------------------------------------
// Вычисление периметра прямоугольника

extern "C"
{
    double calculateRectangleArea(double a, double b);
}

/*double calculateRectangleArea(double a, double b) {
    return a*b;
}*/

double Area(rectangle &r) {
    return calculateRectangleArea(Length(r.x, r.y, r.x, r.y1), Length(r.x, r.y, r.x1, r.y)); //t.r * t.r * 3.14159265358979323846;
}


/*double calculateRectangleArea(double a, double b)) {
    return Length(r.x, r.y, r.x, r.y1) * Length(r.x, r.y, r.x1, r.y);
}*/

color GetColor(rectangle& r) {
    return r.col;
}


#endif //__rectangle__
