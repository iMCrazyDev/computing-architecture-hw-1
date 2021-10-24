#ifndef __container__
#define __container__

//------------------------------------------------------------------------------
// container.h - содержит тип данных,
// представляющий простейший контейнер
//------------------------------------------------------------------------------

#include "shape.h"

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива
class container {

private:
    static const size_t kCapacity = 10000;
    shape* cont[kCapacity];
    size_t size;

public:
    container() : size(0) {}

    ~container() {
        for (int i = 0; i < size; i++) {
            delete cont[i];
        }
    }
    void push_back(shape* value) {
        cont[size++] = value;
    }

    void pop_back() {
        delete cont[--size];
    }

    inline shape& operator[](size_t position) {
        return *cont[position];
    }

    size_t getSize() {
        return size;
    }

    double AreaSum() {
        double sum = 0.0;
        for (int i = 0; i < size; i++) {
            sum += cont[i]->getArea();
        }
        return sum;
    }

    void Sort() {
        for (int i = 1; i < size; i++) {
            shape* s = cont[i];

            int j = i - 1;
            for (; j >= 0 && cont[j]->getArea() > s->getArea(); j--) {
                cont[j + 1] = cont[j];
            }
            cont[j + 1] = s;
        }
    }
};

#endif
