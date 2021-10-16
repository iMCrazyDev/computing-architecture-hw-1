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
#endif //__circle__
