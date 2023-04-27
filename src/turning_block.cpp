#include "turning_block.hpp"

TurningBlock::TurningBlock(int x, int y) : StableObject(x, y, CHAR_LENGTH_IN_PX, CHAR_LENGTH_IN_PX, "turning_block") {}

ENTITIES TurningBlock::what_are_you() {
    return TURNING_BLOCK;
}