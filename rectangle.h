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

#endif //__rectangle__
