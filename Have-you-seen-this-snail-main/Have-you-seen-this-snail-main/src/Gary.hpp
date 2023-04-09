#ifndef PROJECT_2_GARY_H
#define PROJECT_2_GARY_H
#include <iostream>
#include "Cell.hpp"
//#include <vector>
enum class orientation {up = 0, right , down , left};

//std::vector<int> vec ={};

class Gary{
public:
  //  char R, L, U, D;
    orientation temp = orientation::up;
    int x,y;
    Gary (unsigned int BoardSize);
    void move(Cell *snail);
    orientation get_orientation();
    std::tuple<unsigned int, unsigned int> get_location();
};

#endif //PROJECT_2_GARY_H

