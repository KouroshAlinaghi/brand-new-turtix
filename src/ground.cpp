#include "ground.hpp"

Ground::Ground(int x, int y, int num_of_blocks) : StableObject(x, y, CHAR_LENGTH_IN_PX*num_of_blocks, CHAR_LENGTH_IN_PX, "ground") {}

ENTITIES Ground::what_are_you() {
    return GROUND;
}