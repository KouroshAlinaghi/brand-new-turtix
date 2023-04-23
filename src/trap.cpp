#include "trap.hpp"

Trap::Trap(int x, int y) : StableObject(x, y, CHAR_LENGTH_IN_PX, CHAR_LENGTH_IN_PX, "trap.png") {}

ENTITIES Trap::what_are_you() {
    return TRAP;
}