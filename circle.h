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

//------------------------------------------------------------------------------
// круг
struct circle {
  int x, y, r; // радиус и центр
  color col; // цвет
};

// Ввод параметров круга из файла
void In(circle &t, ifstream &ifst);

// Случайный ввод параметров круга
void InRnd(circle &);

// Вывод параметров круга в форматируемый поток
void Out(circle &c, ofstream &ofst);

// Вычисление периметра круга
double Area(circle &t);


color GetColor(circle& c);


//------------------------------------------------------------------------------
// Ввод параметров треугольника из потока
void In(circle &c, ifstream &ifst) {
    int color_code;
    ifst >> c.x >> c.y >> c.r >> color_code;
    c.col = colors[color_code];
}

// Случайный ввод параметров треугольника
void InRnd(circle &c) {
  c.x = Random();
  c.y = Random();
  c.r = Random();
  c.col = colors[Random() % 7];
}


//------------------------------------------------------------------------------
// Вывод параметров треугольника в поток
void Out(circle &c, ofstream &ofst) {
    ofst << "It is Circle:    x = "
        << "(" << c.x << ", " << c.y << ") r = " << c.r
        << ". Area = " << Area(c)
        << ". Color = " << GetColor(c) << "\n";
}

//------------------------------------------------------------------------------
// Вычисление периметра треугольника

extern "C"
{
    double calculateCircleArea(circle &c);
}

double Area(circle &t) {
    return calculateCircleArea(t); //t.r * t.r * 3.14159265358979323846;
}

color GetColor(circle& c) {
    return c.col;
}


#endif //__circle__
