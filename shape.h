#include <string>

#ifndef __shape__
#define __shape__

//------------------------------------------------------------------------------
// shape.h - содержит описание обобщающей геометрической фигуры,
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся фигуры
class shape {
protected:
    std::string type;
    double area;

    virtual double calculateArea() = 0;

public:
    std::string getType() {
        return type;
    }

    double getArea() {
        return area;
    }

    virtual std::string toString() = 0;

};


#endif
