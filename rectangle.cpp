//------------------------------------------------------------------------------
// rectangle_In.cpp - содержит процедуру ввода параметров 
// для уже созданного прямоугольника
//------------------------------------------------------------------------------

#include "rectangle.h"
#include "shape.h"

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
double Area(rectangle &r) {
    return Length(r.x, r.y, r.x, r.y1) * Length(r.x, r.y, r.x1, r.y);
}

color GetColor(rectangle& r) {
    return r.col;
}

