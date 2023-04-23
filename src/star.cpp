#include "star.hpp"

Star::Star(int x, int y) : StableObject(x, y, CHAR_LENGTH_IN_PX, CHAR_LENGTH_IN_PX, "star.png") {}

ENTITIES Star::what_are_you() {
    return STAR;
}