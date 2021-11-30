#ifndef __shape__
#define __shape__

//------------------------------------------------------------------------------
// shape.h - содержит описание обобщающей геометрической фигуры,
//------------------------------------------------------------------------------

#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include "math.h"

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся фигуры
struct shape {
    // значения ключей для каждой из фигур
    enum key {RECTANGLE, TRIANGLE, CIRCLE};

    key k; // ключ
    double area;
    // используемые альтернативы
    union { // используем простейшую реализацию
        rectangle r;
        triangle t;
        circle c;
    };
};

// Ввод обобщенной фигуры
bool In(shape &s, ifstream &ifdt);

// Случайный ввод обобщенной фигуры
bool InRnd(shape &s);

// Вывод обобщенной фигуры
void Out(shape &s, ofstream &ofst);

// Вычисление периметра обобщенной фигуры
double Area(shape &s);

// Получить цвет
color Color(shape &s);

bool In2(shape& s, ifstream& ifst) {
    int k;
    ifst >> k;
    switch (k) {
    case 1:
        s.k = shape::RECTANGLE;
        In(s.r, ifst);
        return true;
    case 2:
        s.k = shape::TRIANGLE;
        In(s.t, ifst);
        return true;
    case 3:
        s.k = shape::CIRCLE;
        In(s.c, ifst);
        return true;
    default:
        return false;
    }
}
//------------------------------------------------------------------------------
// Ввод параметров обобщенной фигуры из файла
bool In(shape& s, ifstream &ifst) {
    bool result = In2(s, ifst);
    if (result) {
        s.area = Area(s);
    }
    return result;
}

bool InRnd2(shape& s) {
    auto k = rand() % 3 + 1;
    switch (k) {
    case 1:
        s.k = shape::RECTANGLE;
        InRnd(s.r);
        return true;
    case 2:
        s.k = shape::TRIANGLE;
        InRnd(s.t);
        return true;
    case 3:
        s.k = shape::CIRCLE;
        InRnd(s.c);
        return true;
    default:
        return false;
    }
}

// Случайный ввод обобщенной фигуры
bool InRnd(shape& s) {
    bool result = InRnd2(s);
    if (result) {
        s.area = Area(s);
    }
    return result;
}

//------------------------------------------------------------------------------
// Вывод параметров текущей фигуры в поток
void Out(shape &s, ofstream &ofst) {
    switch(s.k) {
        case shape::RECTANGLE:
            Out(s.r, ofst);
            break;
        case shape::TRIANGLE:
            Out(s.t, ofst);
            break;
        case shape::CIRCLE:
            Out(s.c, ofst);
            break;
        default:
            ofst << "Incorrect figure!" << endl;
    }
}

//------------------------------------------------------------------------------
// Вычисление периметра фигуры
double Area(shape &s) {
    switch(s.k) {
        case shape::RECTANGLE:
            return Area(s.r);
            break;
        case shape::TRIANGLE:
            return Area(s.t);
            break;
        case shape::CIRCLE:
          return Area(s.c);
          break;
        default:
            return 0.0;
    }
}

//
color Color(shape &s) {
  switch(s.k) {
    case shape::RECTANGLE:
      return s.r.col;
    case shape::TRIANGLE:
      return s.t.col;
    case shape::CIRCLE:
      return s.c.col;
  }
}


#endif
