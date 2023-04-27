#include "trap.hpp"

Trap::Trap(int x, int y) : StableObject(x, y+CHAR_LENGTH_IN_PX-17, CHAR_LENGTH_IN_PX, 17, "trap") {}

ENTITIES Trap::what_are_you() {
    return TRAP;
}