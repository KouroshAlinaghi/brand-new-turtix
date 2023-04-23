#include "turtlack.hpp"

Turtlack::Turtlack(int x, int y) : NPC(x, y, CHAR_LENGTH_IN_PX, CHAR_LENGTH_IN_PX, "turtlack.png") {}

ENTITIES Turtlack::what_are_you() {
    return TURTLACK;
}