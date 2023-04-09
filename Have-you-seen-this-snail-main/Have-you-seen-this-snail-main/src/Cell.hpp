//
// Created by Qusai Almustafa on 4/12/22.
//

#ifndef PROJECT_2_CELL_H
#define PROJECT_2_CELL_H

#include <iostream>
#include <cstdio>
#include <cstring>
#include <tuple>
#include <fstream>

//enum class orientation {up = 0, right , down , left};
//done
class Cell {
public:
    enum Color { white, black};
    Color color;
    Cell();
    void next_color();
    Color get_color ();
};
#endif //PROJECT_2_CELL_H

