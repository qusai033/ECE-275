//
// Created by Qusai Almustafa on 4/12/22.
//
//done
#include "Cell.hpp"

Cell::Cell() {
    color = Color::white;
}

void Cell::next_color() {
    if (color == Color::white) {
        color = Color::black;
    } else {
        color = Color::white;
    }
}

Cell::Color Cell::get_color () {
    return color;
}
