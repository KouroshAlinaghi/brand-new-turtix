#include "rope.hpp"

Rope::Rope(int x, int y) : StableObject(x, y, CHAR_LENGTH_IN_PX, CHAR_LENGTH_IN_PX, "rope") {}

ENTITIES Rope::what_are_you() {
    return ROPE;
}