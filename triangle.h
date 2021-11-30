#ifndef __triangle__
#define __triangle__

//------------------------------------------------------------------------------
// triangle.h - содержит описание треугольника
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

#include "rnd.h"
#include "color.h"
#include "math.h"
#include "utils.h"

//------------------------------------------------------------------------------
// треугольник
struct triangle {
    int x, y, x1, y1, x2, y2; // координаты точек
    color col; // цвет
};

// Ввод параметров треугольника из файла
void In(triangle &t, ifstream &ifst);

// Случайный ввод параметров треугольника
void InRnd(triangle &);

// Вывод параметров треугольника в форматируемый поток
void Out(triangle &t, ofstream &ofst);

// Вычисление периметра треугольника
double Area(triangle &t);

color GetColor(triangle& t);

//------------------------------------------------------------------------------
// Ввод параметров треугольника из потока
void In(triangle &t, ifstream &ifst) {
    int color_code;
    ifst >> t.x >> t.y >> t.x1 >> t.y1 >> t.x2 >> t.y2 >> color_code;
    t.col = colors[color_code];
}

// Случайный ввод параметров треугольника
void InRnd(triangle &t) {
    t.x = Random();
    t.y = Random();
    t.x1 = Random();
    t.y1 = Random();
    t.x2 = Random();
    do {
        t.y2 = Random();
    } while (Area(t) != 0);
    t.col = colors[Random() % 7];
}

//------------------------------------------------------------------------------
// Вывод параметров треугольника в поток
void Out(triangle &t, ofstream &ofst) {
    ofst << "It is Triangle:  x = "
         << "(" << t.x << ", " << t.y << ") x_1 = "
         << "(" << t.x1 << ", " << t.y1 << ") x_2 = "
         << "(" << t.x2 << ", " << t.y2 << ")"
         << ". Area = " << Area(t) << ""
         << ". Color = " << GetColor(t) << "\n";
}

//------------------------------------------------------------------------------
// Вычисление периметра треугольника
/*double calculateTriangleArea(double a, double b, double c) {
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c)); 
}*/

extern "C"
{
    double calculateTriangleArea(double a, double b, double c);
}


double Area(triangle &t) {
    double a = Length(t.x, t.y, t.x1, t.y1);
    double b = Length(t.x, t.y, t.x2, t.y2);
    double c = Length(t.x1, t.y1, t.x2, t.y2);

    return calculateTriangleArea(a, b, c);
    //формула герона
} 

color GetColor(triangle& t) {
    return t.col;
}


#endif //__triangle__
