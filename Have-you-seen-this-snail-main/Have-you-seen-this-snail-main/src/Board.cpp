//
// Created by Qusai Almustafa on 4/12/22.
//

#include "Board.hpp"
#include "Cell.hpp"
#include "Gary.hpp"

//Cell -> x and y gets updated then move gary gives each new coordinate as instructed by the board function
void Board::setOutputFilename(char d[]){
   strcpy(file, d);
}

Board::Board(unsigned int BoardSize){
    x = BoardSize / 2; // intial position
    y = BoardSize / 2;
    size = BoardSize;
   // unsigned int board[BoardSize][BoardSize]; use again
    if (BoardSize % 2 == 0){
        std::cout<<"Board dimension must be an odd number!! Got"<< BoardSize <<"and adding 1 to equal"<< BoardSize + 1 <<std::endl;
        BoardSize++; // increment
    } else {
    //    BoardSize; //  Keep it as it is
    }
}

void Board::move_gary(unsigned int steps) {
    //   int Board[size][size]; (remove-justfor test cases)
    // output each array element's value
    //Get_oreitation ->
    int Board[size][size];
    Gary B(size); //snail
    Cell * snail;
    //snail->steps = steps;
    //steps = snail->steps;
    //Gary t(size);
   //int i = steps;
   //steps = i;
   //Board[0][0] = i;
   //int i = Board[0][0];
    for ( unsigned int i = 0; i < size; i++ ) {
        for (unsigned int j = 0; j < size; j++) {
          Board[i][j]=0;
        }
    }
  for (unsigned int i = 0; i < steps; i++){
        // flip color
        // move -> gary;
        // change number in array = 1
        B.move(snail);
        snail->next_color();
        int x = Cell::white;
        int y = Cell::black;
        if (snail->get_color() == snail->Color::white){
            Board[x][y] = 0;
        }
        else if (snail->get_color() == snail->Color::black){
            Board[x][y] = 1;
        }
  }
  //
}


void
gary
    std::make_tuple<0>    get get_location x =0
 std::make_tuple<1> get_location y =1;


/*
void Board::move_gary(unsigned int steps) {
    Gary::move();
}
 8?
*/
