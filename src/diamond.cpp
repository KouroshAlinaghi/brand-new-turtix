#include "diamond.hpp"

Diamond::Diamond(int x, int y) : StableObject(x, y, CHAR_LENGTH_IN_PX, CHAR_LENGTH_IN_PX, "diamond.png") {}

ENTITIES Diamond::what_are_you() {
    return DIAMOND;
}