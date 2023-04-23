#include "ladder.hpp"

Ladder::Ladder(int x, int y) : StableObject(x, y, CHAR_LENGTH_IN_PX, CHAR_LENGTH_IN_PX, "ladder.png") {}

ENTITIES Ladder::what_are_you() {
    return LADDER;
}