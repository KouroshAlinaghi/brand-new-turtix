#include "shielded.hpp"

Shielded::Shielded(int x, int y) : Enemy(x, y, CHAR_LENGTH_IN_PX, CHAR_LENGTH_IN_PX, "dummy.png") {}

ENTITIES Shielded::what_are_you() {
    return SHIELDED_ENEMY;
}