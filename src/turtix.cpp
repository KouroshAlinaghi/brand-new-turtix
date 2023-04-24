#include "turtix.hpp"
#include <iostream>

Turtix::Turtix(int x, int y) : Playable(x, y, CHAR_LENGTH_IN_PX, CHAR_LENGTH_IN_PX, "turtle.png") {}

ENTITIES Turtix::what_are_you() {
    return TURTIX;
}