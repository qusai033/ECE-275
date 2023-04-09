#include "Gary.hpp"
#include "Board.hpp"
#include "Cell.hpp"


int main(int argc, char** argv){
    unsigned int boardSize = atoi(argv[1]);
    unsigned int numberSteps = atoi(argv[2]);
    //std::string outputFilename = ;
    int i = argc;
    argc = i; //to remove the unused variable warning
    Board B(boardSize);

    B.move_gary(numberSteps);

    return 0;
}
