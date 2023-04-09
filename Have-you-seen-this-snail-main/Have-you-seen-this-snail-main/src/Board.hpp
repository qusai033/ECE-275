//
// Created by Qusai Almustafa on 4/12/22.
//

#ifndef PROJECT_2_BOARD_H
#define PROJECT_2_BOARD_H

class Board{
public:
    //Gary (unsigned int BoardSize);
    char file[40];
    void setOutputFilename(char d[]);
    unsigned int x, y;
    unsigned int size;
    Board(unsigned int BoardSize);
    void move_gary(unsigned int steps);
};

#endif //PROJECT_2_BOARD_H
