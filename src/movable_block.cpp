#include "movable_block.hpp"

MovableBlock::MovableBlock(int x, int y) : NPC(x, y, CHAR_LENGTH_IN_PX, CHAR_LENGTH_IN_PX, "movable_block", 3) {}

ENTITIES MovableBlock::what_are_you() {
    return MOVABLE_BLOCK;
}