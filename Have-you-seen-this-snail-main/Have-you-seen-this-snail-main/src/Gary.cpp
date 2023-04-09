//
// Created by Qusai Almustafa on 4/12/22.
//
#include "Cell.hpp"
#include "Gary.hpp"
//int. in the

Gary::Gary(unsigned int BoardSize){
      temp = orientation::up; 
      x = BoardSize / 2; // intial position
      y = BoardSize / 2;
      if (BoardSize % 2 == 0){
          BoardSize++; // increment
      }
}

orientation Gary::get_orientation(){
   return temp;
}

std::tuple<unsigned int, unsigned int> Gary::get_location() {
    return  std::make_tuple(x, y);
}

void Gary::move (Cell *snail){
   orientation temp = orientation::up;
      //if else = black//white == black (clockwise) example, right (if white or black) = (white) if (right == down) else if (down == left)
    if (Cell::white == snail->get_color()){
        if (temp == orientation::up) {
            temp = orientation::right;
            // x y
            y++;
        }
        else if (temp == orientation::right){
              temp = orientation::down;
              x++;
        }
        else if (temp == orientation::down){
            temp = orientation::left;
            --y; // y = 1      x = --y; 0 x = y--; = 1
        }
        else if (temp == orientation::left){
            temp = orientation::up;
            x--;
        }
    }
    else if (Cell::black == snail->get_color()){
        if (temp == orientation::up) {
            temp = orientation::left;
            x++;
        }
        else if (temp == orientation::left){
            temp = orientation::down;
            y++;
        }
        else if (temp == orientation::down){
            temp = orientation::right;
            x--;
        }
        else if (temp == orientation::right){
            temp = orientation::up;
            y--;
        }
    }
}

