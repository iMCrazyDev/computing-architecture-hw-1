//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию, 
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <cstdlib> // для функций rand() и srand()
#include <ctime>   // для функции time()
#include <cstring>

#include "container.h"
#include "shape.h"
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"
#include "utils.h"

void errMessage1() {
    std::cout << "incorrect command line!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n";
}

void errMessage2() {
    std::cout << "incorrect qualifier value!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n";
}

void writeContainer(container& cont, std::ofstream& stream) {
    stream << "Container contains " << cont.getSize() << " elements." << std::endl;
    for (size_t i = 0; i < cont.getSize(); i++) {
        stream << i << ": ";
        stream << cont[i].toString();
    }
}

void In(container& c, std::ifstream & ifst) {
    
    while (!ifst.eof()) {
        int k;
        ifst >> k;

        if (k == 1) {
            int x, y, x1, y1, color_code;
            ifst >> x >> y >> x1 >> y1 >> color_code;
            c.push_back(new rectangle(x, y, x1, y1, colors[color_code]));
        }
        else if (k == 2) {
            int x, y, x1, y1, x2, y2, color_code;
            ifst >> x >> y >> x1 >> y1 >> x2 >> y2 >> color_code;
            c.push_back(new triangle(x, y, x1, y1, x2, y2, colors[color_code]));
        }
        else if (k == 3) {
            int x, y, r, color_code;
            ifst >> x >> y >> r >> color_code;
            c.push_back(new circle(x, y, r, colors[color_code]));
        }
    }
}

void InRnd(container& c, int size) {
    while (size--) {

        int k = rand() % 3 + 1;

        if (k == 1) {
            int x, y, x1, y1, color_code;

            x = Random();
            y = Random();
            x1 = Random();
            do {
                y1 = Random();
            } while (y == y1);

            color_code = Random() % 7;

            c.push_back(new rectangle(x, y, x1, y1, colors[color_code]));

        }
        else if (k == 2) {
            int x, y, x1, y1, x2, y2, color_code;
            
            x = Random();
            y = Random();
            x1 = Random();
            y1 = Random();
            x2 = Random();
            do {
                y2 = Random();
            } while (calculateTriangleArea(x, y, x1, y1, x2, y2) != 0);

            color_code = Random() % 7;

            c.push_back(new triangle(x, y, x1, y1, x2, y2, colors[color_code]));

        }
        else if (k == 3) {
            int x, y, r, color_code;

            x = Random();
            y = Random();
            r = Random();
            color_code = Random() % 7;

            c.push_back(new circle(x, y, r, colors[color_code]));

        }
    }
}

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    if(argc != 5) {
        errMessage1();
        return 1;
    }

    std::cout << "Start" << std::endl;
    container c;

    if(!strcmp(argv[1], "-f")) {
        std::ifstream ifst(argv[2]);
        In(c, ifst);
    }
    else if(!strcmp(argv[1], "-n")) {
        auto size = atoi(argv[2]);
        if((size < 1) || (size > 10000)) { 
            std::cout << "incorrect numer of figures = "
                 << size
                 << ". Set 0 < number <= 10000\n";
            return 3;
        }
        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(0)));
        // Заполнение контейнера генератором случайных чисел
        InRnd(c, size);
    }
    else {
        errMessage2();
        return 2;
    }

    // Вывод содержимого контейнера в файл
    std::ofstream ofst1(argv[3]);
    ofst1 << "Filled container:\n";
    writeContainer(c, ofst1);

    // The 2nd part of task
    std::ofstream ofst2(argv[4]);
    ofst2 << "Area sum = " << c.AreaSum() << "\n";

    ofst2 << "Sorting..." << "\n";

    c.Sort();

    writeContainer(c, ofst2);

    std::cout << "Stop"<< std::endl;
    return 0;
}
