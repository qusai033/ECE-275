#ifndef MORTY_H_
#define MORTY_H_
#include <iostream>
#include <cstdio> // std::sscanf
#include <cstring> // std::strcmp

enum class dimension {UNK = -1, C137, Z286};
using namespace std;

// Define a struct which holds this program's arguments
struct args {
    dimension dim;
    int start, stop, step;
    bool valid;
};

args parse_args(int, char**);

namespace C137 {
    void Morty (int, int, int);
    void  Morty (int, int);
}

namespace Z286 {
    void Morty (int, int, int);
    void Morty (int, int);
}
#endif
